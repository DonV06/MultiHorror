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

class Enemy
{
public:
    Enemy(Vector2f _loc, Vector2f _size, Player& player);
    void draw(SDL_Renderer* renderer, std::vector<Wall> walls);
    Rect rect;
private:
    std::pair<Wall*, std::pair<float, float>> cast_rays(float angle, std::vector<Wall> walls, int RANGE);
    Player& player;

};

#endif //MULTIHORROR_ENEMY_H
