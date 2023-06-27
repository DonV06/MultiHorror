//
// Created by DonV06 on 21.06.2023.
//
#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "vector2f.h"
#include "iostream"
#include "player.h"

player::player(vector2f _loc, vector2f _size): loc(_loc), size(_size), rect(_loc, _size) {


}

void player::move(float x, float y) {
    rect.x += x;
    rect.y += y;
    std::cout << "Adding: " << y << "Result: " << (loc.getY()) << std::endl;

}


void player::draw(SDL_Renderer* renderer) {
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

void player::teleport(vector2f new_cords) {
    loc.setX(new_cords.getX());
    loc.setY(new_cords.getY());

}



