//
// Created by DonV06 on 25.06.2023.
//

#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "vector2f.h"
#include "window.h"
#include "Rect.h"
#include "rectblock.h"


rectblock::rectblock(vector2f _loc, vector2f _size) : rect(_loc, _size) {

}

void rectblock::draw(SDL_Renderer *renderer) {
    SDL_Rect rectangle;
    rectangle.x = rect.x;  // the x coordinate
    rectangle.y = rect.y;  // the y coordinate
    rectangle.w = rect.width    ; // the width of the rectangle
    rectangle.h = rect.height;  // the height of the rectangle

// Set draw color (RGBA)
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color

// Draw filled rectangle
    SDL_RenderFillRect(renderer, &rectangle);


}
