//
// Created by DonV06 on 18.06.2023.
//
#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include "vector2f.h"

#ifndef HORRORGAME_WINDOW_H
#define HORRORGAME_WINDOW_H
class window
{
public:
    window(vector2f _loc, vector2f _size);
    ~window();
    void destory();
    SDL_Window* getSDLwindow();
    SDL_Renderer* getsdlRenderer();
private:
    SDL_Window* sdlWindow;
    SDL_Renderer* sdlRenderer;

};


#endif //HORRORGAME_WINDOW_H
