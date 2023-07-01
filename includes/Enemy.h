//
// Created by znak zapytania on 28.06.2023.
//

#ifndef MULTIHORROR_ENEMY_H
#define MULTIHORROR_ENEMY_H
#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "Vector2f.h"
#include "Window.h"
#include "Rect.h"
#include "Player.h"
#include "Wall.h"
#include <cmath>
#include <utility>
#include <cmath>

class Enemy
{
public:
    Enemy(Vector2f _loc, Vector2f _size, Player& player) : player(player), rect(_loc, _size) {};
    Rect rect;
    std::vector<std::pair<int, int>> path;
    std::pair<int, int> currentPart = {-1, -1};
    bool isSeeing = false;
    std::pair<float, float> calculateVelocity(std::pair<float, float> start, std::pair<float, float> end, float speed) {
        // Calculate the direction vector
        std::pair<float, float> direction = {end.first - start.first, end.second - start.second};

        // Calculate the magnitude of the direction vector
        float magnitude = std::sqrt(std::pow(direction.first, 2) + std::pow(direction.second, 2));

        // If the start and end points are the same, return a velocity of {0, 0}
        if (magnitude == 0) {
            return {0, 0};
        }

        // Calculate the unit direction vector
        std::pair<float, float> unit_direction = {direction.first / magnitude, direction.second / magnitude};

        // Calculate the velocity vector
        std::pair<float, float> velocity = {speed * unit_direction.first, speed * unit_direction.second};

        return velocity;
    }
    void move(){
        if (path.size() == 0) {return;}
        if (currentPart.first == -1){ currentPart = path.front(); path.erase(path.begin() + 0); return;}
        if (isSeeing) return;
        std::pair<float, float> velocity = calculateVelocity({rect.x, rect.y}, {currentPart.first*10, currentPart.second*10}, 2);
        rect.x += velocity.first;
        rect.y += velocity.second;
        if ((currentPart.first*10)-5 < rect.x && rect.x < (currentPart.first*10)+5 && (currentPart.second*10)-5 < rect.y && rect.y < (currentPart.second*10)+5){
            currentPart = path.front();
            path.erase(path.begin());}
        return;
    };
    std::pair<Wall*, std::pair<float, float>> cast_rays(float angle, std::vector<Wall> walls, int RANGE = 2000) {
        float start_angle = angle;
        float target_x, target_y;
        isSeeing = false;
        for (int ray = 0; ray < 1; ++ray) {
            for (int depth = 0; depth < 200; ++depth) {
                target_x = (rect.x+(rect.width/2)) - std::sin(start_angle) * depth;
                target_y = (rect.y+(rect.height/2)) + std::cos(start_angle) * depth;

                for (Wall& wall: walls) {

                    if (wall.isCollidingPoint(Vector2f(target_x, target_y))) {
                        return {&wall, {target_x, target_y}};
                    }
                }

                if (player.rect.isCollidingPoint(Vector2f(target_x, target_y))) {
                    isSeeing = true;
                    return {NULL, {target_x, target_y}};
                }

                //if (SDL_PointInRect(&(SDL_Point){(int)target_x, (int)target_y}, &objects[0])) {
                //    return std::make_pair(objects[0], depth);
                //}
            }
        }
        return {NULL, {target_x, target_y}};

    }
    void draw(SDL_Renderer *renderer, std::vector<Wall> walls) {
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
private:
    Player& player;

};

#endif //MULTIHORROR_ENEMY_H
