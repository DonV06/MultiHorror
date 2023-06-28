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
// Function that generates a random integer between min and max (inclusive)

std::vector<AstarNode> generateNodes(int size) {
    std::vector<AstarNode> nodes;
    for (int vi_x = 0; vi_x < 1000/size; vi_x++) {
        for (int vi_y = 0; vi_y < 700/size; vi_y++) {
            nodes.push_back(AstarNode(Vector2f(vi_x * size, vi_y * size), Vector2f(vi_x, vi_y), size));
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
const int FPS = 144;
const int frameDelay = 1000 / FPS;
Uint32 frameStart;
int frameTime;
std::vector<RectBlock> rectblocks;
std::vector<Enemy> Enemys;
std::vector<Wall> Walls;
int main(int argc, char* argv[]) {
    ScreenManager manager;
    manager.createWindow(Vector2f(-1, -1), Vector2f(1000, 700));

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        return 1;
    }

    AlgoritmicMap algoritmicMap;
    algoritmicMap.nodes = generateNodes(10);

    float speed = 5;
    Player player(Vector2f(600, 600), Vector2f(50, 50));
    Walls.push_back(Wall(Vector2f(500, 300), Vector2f(100, 300)));
    Enemys.push_back(Enemy(Vector2f(20, 20), Vector2f(50, 50), player));
    Window mainwindow = manager.getWindow(0);
    bool mainloop = true;
    SDL_Event event;
    const Uint8 *state = SDL_GetKeyboardState(NULL);

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


        int windowsposX, windowposY;
        SDL_GetWindowPosition(mainwindow.getSDLwindow(), &windowsposX, &windowposY);
        Vector2f poschange(0, 0);
        if (state[SDL_SCANCODE_W]) {
            poschange.addY(-speed);
            for (Wall& wall : Walls) {

                if (wall.isCollidingVectors(Vector2f(player.rect.x + poschange.x, player.rect.y + poschange.y), Vector2f(player.rect.width, player.rect.height))){
                    poschange.setY(0);
                }
            }
        }
        if (state[SDL_SCANCODE_A]) {
            poschange.addX(-speed);
            for (Wall& wall : Walls) {

                if (wall.isCollidingVectors(Vector2f(player.rect.x + poschange.x, player.rect.y + poschange.y), Vector2f(player.rect.width, player.rect.height))){
                    poschange.setX(0);
                }
            }
        }
        if (state[SDL_SCANCODE_D]) {
            poschange.addX(speed);
            for (Wall& wall : Walls) {

                if (wall.isCollidingVectors(Vector2f(player.rect.x + poschange.x, player.rect.y + poschange.y), Vector2f(player.rect.width, player.rect.height))){
                    poschange.setX(0);
                }
            }
        }
        if (state[SDL_SCANCODE_S]) {
            poschange.addY(speed);
            for (Wall& wall : Walls) {
                if (wall.isCollidingVectors(Vector2f(player.rect.x + poschange.x, player.rect.y + poschange.y), Vector2f(player.rect.width, player.rect.height))){
                    poschange.setY(0);
                }
            }
        }
        algoritmicMap.draw(mainwindow.getsdlRenderer());
        player.rect.x += poschange.x;
        player.rect.y += poschange.y;

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
