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
    void teleport(Vector2f new_cords);
    void move(float x, float y);
    void draw(SDL_Renderer* renderer);
    Player(Vector2f _loc, Vector2f _size);
    Rect rect;
private:
};

#endif //MULTIHORROR_PLAYER_H
