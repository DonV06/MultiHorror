#include <iostream>
#include "libs/SDL2_base/include/SDL2/SDL.h"
#include "includes/vector2f.h"
#include "includes/ScreenManager.h"
#include "includes/window.h"
#include "libs/SDL2_image/include/SDL2/SDL_image.h"
#include "includes/player.h"
#include "includes/rectblock.h"
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
    rectblocks.push_back(rectblock(vector2f(20, 20), vector2f(100, 100)));
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
        std::cout << (_player.isCollidingRect(rectblocks[0].getloc(), rectblocks[0].getsize())) << ": s" << std::endl;
        if (state[SDL_SCANCODE_W]) {
            _player.move(0, -speed);
        }
        if (state[SDL_SCANCODE_A]) {
            _player.move(-speed, 0);
        }
        if (state[SDL_SCANCODE_D]) {
            _player.move(speed, 0);
        }
        if (state[SDL_SCANCODE_S]) {
            _player.move(0, speed);
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
