//
// Created by DonV06 on 21.06.2023.
//

#ifndef MULTIHORROR_PLAYER_H
#define MULTIHORROR_PLAYER_H
#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "Vector2f.h"
#include "Window.h"
#include "Rect.h"
class Player
{
public:
    Player(Vector2f loc, Vector2f size): rect(loc, size) {};
    Rect rect;
    void move(float x, float y) {
        rect.x += x;
        rect.y += y;

    }
    void draw(SDL_Renderer* renderer) {
        SDL_Rect rectangle;
        rectangle.x = rect.x;  // the x coordinate
        rectangle.y = rect.y;  // the y coordinate
        rectangle.w = rect.width; // the width of the rectangle
        rectangle.h = rect.height;  // the height of the rectangle

// Set draw color (RGBA)
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color

// Draw filled rectangle
        SDL_RenderFillRect(renderer, &rectangle);



    }
private:
};

#endif //MULTIHORROR_PLAYER_H
