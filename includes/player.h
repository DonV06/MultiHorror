//
// Created by DonV06 on 21.06.2023.
//

#ifndef MULTIHORROR_PLAYER_H
#define MULTIHORROR_PLAYER_H
#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "vector2f.h"
#include "window.h"
#include "Rect.h"
class player : public Rect
{
public:
    void teleport(vector2f new_cords);
    void move(float x, float y);
    void draw(SDL_Renderer* renderer);
    player(vector2f _loc, vector2f _size);
private:
    vector2f loc;
    vector2f size;

};

#endif //MULTIHORROR_PLAYER_H
