//
// Created by DonV06 on 21.06.2023.
//
#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "Vector2f.h"
#include "iostream"
#include "Player.h"

Player::Player(Vector2f _loc, Vector2f _size): rect(_loc, _size) {


}

void Player::move(float x, float y) {
    rect.x += x;
    rect.y += y;

}


void Player::draw(SDL_Renderer* renderer) {
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



