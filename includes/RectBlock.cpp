//
// Created by DonV06 on 25.06.2023.
//

#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "Vector2f.h"
#include "Window.h"
#include "Rect.h"
#include "RectBlock.h"


RectBlock::RectBlock(Vector2f _loc, Vector2f _size) : Rect(_loc, _size) {

}

void RectBlock::draw(SDL_Renderer *renderer) {
    SDL_Rect rectangle;
    rectangle.x = x;  // the x coordinate
    rectangle.y = y;  // the y coordinate
    rectangle.w = width    ; // the width of the rectangle
    rectangle.h = height;  // the height of the rectangle

// Set draw color (RGBA)
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color

// Draw filled rectangle
    SDL_RenderFillRect(renderer, &rectangle);


}
