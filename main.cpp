#include <iostream>
#include "libs/SDL2_base/include/SDL2/SDL.h"
#include "includes/vector2f.h"
#include "includes/ScreenManager.h"
#include "includes/window.h"
#include "libs/SDL2_image/include/SDL2/SDL_image.h"
#include "includes/player.h"
#include "includes/rectblock.h"
#include <algorithm>
#include <random>

// Function that generates a random integer between min and max (inclusive)
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
std::vector<rectblock> rectblocks;
int main(int argc, char* argv[]) {
    ScreenManager manager;
    manager.createWindow(vector2f(-1, -1), vector2f(1000, 700));

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        return 1;
    }
    float speed = 5;
    player _player(vector2f(600, 0), vector2f(100, 100));

    window mainwindow = manager.getWindow(0);
    rectblocks.push_back(rectblock(vector2f(0, 20), vector2f(100, 100)));
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
        for (rectblock& rectb : rectblocks) { // Use rectblock& to make rectb a reference, not a copy

            if (_player.rect.isCollidingRect(vector2f(rectb.rect.x, rectb.rect.y), vector2f(rectb.rect.width, rectb.rect.height))) {
                rectb.rect.y = generateRandomNumber(0, 600);
                rectb.rect.x = generateRandomNumber(0, 600);

                manager.createWindow(vector2f(-1, -1), vector2f(400, 400));
            }
        }

        std::cout << rectblocks[0].rect.x << " " << std::endl;
        int windowsposX, windowposY;
        SDL_GetWindowPosition(mainwindow.getSDLwindow(), &windowsposX, &windowposY);

        if (state[SDL_SCANCODE_W]) {
            _player.rect.y += -speed;
        }
        if (state[SDL_SCANCODE_A]) {
            _player.rect.x += -speed;
        }
        if (state[SDL_SCANCODE_D]) {
            _player.rect.x += speed;
        }
        if (state[SDL_SCANCODE_S]) {
            _player.rect.y += speed;
        }
        _player.draw(mainwindow.getsdlRenderer());
        for (rectblock block : rectblocks) {
            block.draw(mainwindow.getsdlRenderer());
        }

        for (window currentwin: manager.getwindows()) {
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
