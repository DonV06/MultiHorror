//
// Created by DonV06 on 18.06.2023.
//
#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include "Vector2f.h"

#ifndef HORRORGAME_WINDOW_H
#define HORRORGAME_WINDOW_H
class Window
{
public:
    Window(Vector2f _loc, Vector2f _size) {
        if (_loc.getX() == -1 && _loc.getY() == -1) {
            SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                                  SDL_WINDOWPOS_UNDEFINED,
                                                  SDL_WINDOWPOS_UNDEFINED,
                                                  _size.getX(), _size.getY(),
                                                  SDL_WINDOW_SHOWN
            );

            sdlWindow = window;
            SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            sdlRenderer = renderer;
        }else
        {
            SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                                  _loc.getX(),
                                                  _loc.getY(),
                                                  _size.getX(), _size.getY(),
                                                  SDL_WINDOW_SHOWN);

            sdlWindow = window;
            SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            sdlRenderer = renderer;
        }


    }
    SDL_Window *getSDLwindow() {
        return sdlWindow;
    }
    SDL_Renderer *getsdlRenderer() {
        return sdlRenderer;
    }
    void destory() {
        SDL_DestroyWindow(sdlWindow);
        SDL_DestroyRenderer(sdlRenderer);
    }
private:
    SDL_Window* sdlWindow;
    SDL_Renderer* sdlRenderer;

};


#endif //HORRORGAME_WINDOW_H
