//
// Created by DonV06 on 18.06.2023.
//

#include "vector2f.h"
#include "window.h"
#include "../libs/SDL2_base/include/SDL2/SDL.h"


window::window(vector2f _loc, vector2f _size) {
    if (_loc.getX() == -1 && _loc.getY() == -1) {
        SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                              SDL_WINDOWPOS_UNDEFINED,
                                              SDL_WINDOWPOS_UNDEFINED,
                                              _size.getX(), _size.getY(),
                                              SDL_WINDOW_SHOWN);

        sdlWindow = window;
        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        sdlRenderer = renderer;
    }else
    {

    }


}

SDL_Window *window::getSDLwindow() {
    return sdlWindow;
}

SDL_Renderer *window::getsdlRenderer() {
    return sdlRenderer;
}

window::~window() {

}

void window::destory() {
    SDL_DestroyWindow(sdlWindow);
    SDL_DestroyRenderer(sdlRenderer);
}
