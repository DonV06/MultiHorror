//
// Created by znak zapytania on 28.06.2023.
//
#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "Vector2f.h"
#include "Window.h"
#include "Enemy.h"
#include <cmath>
#include "Wall.h"


Enemy::Enemy(Vector2f _loc, Vector2f _size, Player& player): player(player), rect(_loc, _size) {}

std::pair<Wall*, std::pair<float, float>> Enemy::cast_rays(float angle, std::vector<Wall> walls, int RANGE = 2000) {
    float start_angle = angle;
    float target_x, target_y;

    for (int ray = 0; ray < 1; ++ray) {
        for (int depth = 0; depth < RANGE; ++depth) {
            target_x = (rect.x+(rect.width/2)) - std::sin(start_angle) * depth;
            target_y = (rect.y+(rect.height/2)) + std::cos(start_angle) * depth;

            for (Wall& wall: walls) {

                if (wall.isCollidingPoint(Vector2f(target_x, target_y))) {
                    return {&wall, {target_x, target_y}};
                }
            }

            if (player.rect.isCollidingPoint(Vector2f(target_x, target_y))) {
                return {NULL, {target_x, target_y}};
            }

            //if (SDL_PointInRect(&(SDL_Point){(int)target_x, (int)target_y}, &objects[0])) {
            //    return std::make_pair(objects[0], depth);
            //}
        }
    }
    return {NULL, {target_x, target_y}};

}


void Enemy::draw(SDL_Renderer *renderer, std::vector<Wall> walls) {
    SDL_Rect rectangle;
    rectangle.x = rect.x;  // the x coordinate
    rectangle.y = rect.y;  // the y coordinate
    rectangle.w = rect.width; // the width of the rectangle
    rectangle.h = rect.height;  // the height of the rectangle

// Set draw color (RGBA)
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Red color

// Draw filled rectangle
    SDL_RenderFillRect(renderer, &rectangle);
    std::pair<Wall*, std::pair<float, float>> ray = cast_rays(rect.angleBetweenRect(player.rect), walls);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(renderer, rect.x+(rect.width/2), rect.y+(rect.height/2), ray.second.first, ray.second.second);

}
