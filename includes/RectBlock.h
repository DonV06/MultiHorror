//
// Created by DonV06 on 24.06.2023.
//

#ifndef MULTIHORROR_RECTBLOCK_H
#define MULTIHORROR_RECTBLOCK_H

#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "Vector2f.h"
#include "Window.h"
#include "Rect.h"

class RectBlock : public Rect
{
public:
    void draw(SDL_Renderer* renderer);
    RectBlock(Vector2f _loc, Vector2f _size);

private:

};
#endif //MULTIHORROR_RECTBLOCK_H
