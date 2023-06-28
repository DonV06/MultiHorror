//
// Created by DonV06 on 18.06.2023.
//

#include "Vector2f.h"
#include "Window.h"
#include "../libs/SDL2_base/include/SDL2/SDL.h"


Window::Window(Vector2f _loc, Vector2f _size) {
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

SDL_Window *Window::getSDLwindow() {
    return sdlWindow;
}

SDL_Renderer *Window::getsdlRenderer() {
    return sdlRenderer;
}

Window::~Window() {

}

void Window::destory() {
    SDL_DestroyWindow(sdlWindow);
    SDL_DestroyRenderer(sdlRenderer);
}
