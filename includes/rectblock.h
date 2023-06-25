//
// Created by DonV06 on 24.06.2023.
//

#ifndef MULTIHORROR_RECTBLOCK_H
#define MULTIHORROR_RECTBLOCK_H

#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "vector2f.h"
#include "window.h"
#include "Rect.h"

class rectblock : public Rect
{
public:
    void draw(SDL_Renderer* renderer);
    rectblock(vector2f _loc, vector2f _size);
private:

};
#endif //MULTIHORROR_RECTBLOCK_H
