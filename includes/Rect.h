//
// Created by DonV06 on 25.06.2023.
//

#ifndef MULTIHORROR_RECT_H
#define MULTIHORROR_RECT_H

#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "Vector2f.h"
#include "Window.h"

class Rect
{
public:
    Rect(Vector2f loc, Vector2f size);
    bool isCollidingVectors(Vector2f __loc, Vector2f __size);
    bool isCollidingRect(Rect rect);
    bool isCollidingPoint(Vector2f point);
    float angleBetweenRect(Rect rect);
    float x;
    float y;
    float width;
    float height;

private:


};

#endif //MULTIHORROR_RECT_H
