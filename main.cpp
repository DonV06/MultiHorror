#include <iostream>
#include "libs/SDL2_base/include/SDL2/SDL.h"
#include "includes/Vector2f.h"
#include "includes/ScreenManager.h"
#include "includes/Window.h"
#include "libs/SDL2_image/include/SDL2/SDL_image.h"
#include "includes/Player.h"
#include "includes/RectBlock.h"
#include <algorithm>
#include <random>
#include "includes/Enemy.h"
#include "includes/Wall.h"
#include "includes/AlgoritmicMap.h"
#include "includes/AstarNode.h"
#include <thread>
bool mainloop = true;
Vector2f lastvirualpos(0, 0);
Vector2f currentvirualpos(0, 0);
AlgoritmicMap algoritmicMap;
const int FPS = 144;
const int frameDelay = 1000 / FPS;
Uint32 frameStart;
int frameTime;
std::vector<RectBlock> rectblocks;
std::vector<Enemy> Enemys;

std::vector<Wall> Walls;
void ailoop() {
    while (mainloop) {
        if (currentvirualpos != lastvirualpos) {
            lastvirualpos = currentvirualpos;
            std::vector<std::pair<int, int>> path = algoritmicMap.GeneratePath(Vector2f(int32_t(Enemys[0].rect.x / 10), int32_t(Enemys[0].rect.y / 10)), currentvirualpos, 60000, 5);
            Enemys[0].path = path;
            for(const auto& pair : path) {
                std::cout << "(" << pair.first << ", " << pair.second << ")" << " ";
            }
            std::cout << std::endl;
        }
    }
}
// Function that generates a random integer between min and max (inclusive)

std::vector<std::vector<AstarNode>> generateNodes(int size) {
    int xSize = 1000/size;
    int ySize = 700/size;
    std::vector<std::vector<AstarNode>> nodes;
    std::vector<AstarNode> ytemp;
    for (int y = 0; y < ySize; y++) {
        ytemp.push_back(AstarNode(Vector2f(-1, -1), Vector2f(-1, -1), -1));
    }
    for (int x = 0; x < xSize; x++) {
        nodes.push_back(ytemp);
    }
    for (int vi_x = 0; vi_x < xSize; vi_x++) {
        for (int vi_y = 0; vi_y < ySize; vi_y++) {
            nodes[vi_x][vi_y] = AstarNode(Vector2f(vi_x * size, vi_y * size), Vector2f(vi_x, vi_y), size);
        }
    }
    return nodes;
}

int generateRandomNumber(int min, int max) {
    // static used for efficiency, so a new random engine isn't created every call
    static std::random_device rd;
    static std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(engine);
}

int main(int argc, char* argv[]) {
    ScreenManager manager;
    manager.createWindow(Vector2f(-1, -1), Vector2f(1000, 700));
    Walls.push_back(Wall(Vector2f(500, 300), Vector2f(100, 300)));
    Walls.push_back(Wall(Vector2f(100, 300), Vector2f(300, 100)));
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        return 1;
    }
    std::vector<Rect> aimoveing;
    for (Wall wall : Walls) {
        aimoveing.push_back(Rect(Vector2f(wall.x, wall.y), Vector2f(wall.width, wall.height)));
    }

    algoritmicMap.originalnodes = generateNodes(10);
    algoritmicMap.bakeMap(aimoveing);



    float speed = 5;
    Player player(Vector2f(800, 500), Vector2f(50, 50));
    algoritmicMap.GeneratePath(Vector2f(1, 1), Vector2f(int32_t((player.rect.x+(player.rect.width/2))/10), int32_t((player.rect.y+(player.rect.height/2))/10)), 200, 5);
    Enemys.push_back(Enemy(Vector2f(20, 20), Vector2f(50, 50), player));
    Window mainwindow = manager.getWindow(0);
    SDL_Event event;
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    std::vector<std::pair<int, int>> path = algoritmicMap.GeneratePath(Vector2f(int32_t(Enemys[0].rect.x / 10), int32_t(Enemys[0].rect.y / 10)), currentvirualpos, 12000, 5);
    Enemys[0].path = path;
    std::thread myThread(ailoop);
    while (mainloop) {
        frameStart = SDL_GetTicks();
        SDL_PumpEvents();
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                mainloop = false;
            }
        }
        // Set draw color to black (R, G, B, A = 0, 0, 0, 255)
        SDL_SetRenderDrawColor(mainwindow.getsdlRenderer(), 0, 0, 0, 255);
        // Clear the renderer with the draw color
        SDL_RenderClear(mainwindow.getsdlRenderer());
        //algoritmicMap.nodes = generateNodes(10);


        int windowsposX, windowposY;
        SDL_GetWindowPosition(mainwindow.getSDLwindow(), &windowsposX, &windowposY);
        Vector2f poschange(0, 0);


        if (state[SDL_SCANCODE_W] && player.rect.y + -speed > 0) {
            poschange.addY(-speed);
            currentvirualpos = Vector2f(int32_t(player.rect.x / 10), int32_t(player.rect.y / 10));
            for (Wall& wall : Walls) {

                if (wall.isCollidingVectors(Vector2f(player.rect.x + poschange.x, player.rect.y + poschange.y), Vector2f(player.rect.width, player.rect.height))){
                    poschange.setY(0);
                }
            }
        }
        if (state[SDL_SCANCODE_A] && player.rect.x + -speed > 0) {
            poschange.addX(-speed);
            currentvirualpos = Vector2f(int32_t(player.rect.x / 10), int32_t(player.rect.y / 10));
            for (Wall& wall : Walls) {

                if (wall.isCollidingVectors(Vector2f(player.rect.x + poschange.x, player.rect.y + poschange.y), Vector2f(player.rect.width, player.rect.height))){
                    poschange.setX(0);
                }
            }
        }
        if (state[SDL_SCANCODE_D]) {
            poschange.addX(speed);
            currentvirualpos = Vector2f(int32_t(player.rect.x / 10), int32_t(player.rect.y / 10));
            for (Wall& wall : Walls) {

                if (wall.isCollidingVectors(Vector2f(player.rect.x + poschange.x, player.rect.y + poschange.y), Vector2f(player.rect.width, player.rect.height))){
                    poschange.setX(0);
                }
            }
        }
        if (state[SDL_SCANCODE_S]) {
            poschange.addY(speed);
            currentvirualpos = Vector2f(int32_t(player.rect.x / 10), int32_t(player.rect.y / 10));
            for (Wall& wall : Walls) {
                if (wall.isCollidingVectors(Vector2f(player.rect.x + poschange.x, player.rect.y + poschange.y), Vector2f(player.rect.width, player.rect.height))){
                    poschange.setY(0);
                }
            }
        }
        //algoritmicMap.draw(mainwindow.getsdlRenderer());
        player.rect.x += poschange.x;
        player.rect.y += poschange.y;

        Enemys[0].move();
        player.draw(mainwindow.getsdlRenderer());
        for (RectBlock block : rectblocks) {
            block.draw(mainwindow.getsdlRenderer());
        }
        for (Wall& wall : Walls) {
            wall.draw(mainwindow.getsdlRenderer());
        }
        for (Enemy& enemy : Enemys) {
            enemy.draw(mainwindow.getsdlRenderer(), Walls);
        }



        for (Window currentwin: manager.getwindows()) {
            SDL_RenderPresent(currentwin.getsdlRenderer());
        }
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }


    manager.destroy();

    SDL_Quit();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
