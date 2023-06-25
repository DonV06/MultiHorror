//
// Created by DonV06 on 25.06.2023.
//

#ifndef MULTIHORROR_RECT_H
#define MULTIHORROR_RECT_H

#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "vector2f.h"
#include "window.h"

class Rect
{
public:
    Rect(vector2f loc, vector2f size);
    bool isCollidingRect(vector2f __loc, vector2f __size);
    bool isCollidingPoint(vector2f point);
    vector2f getloc();
    vector2f getsize();
private:
   vector2f loc;
   vector2f size;

};

#endif //MULTIHORROR_RECT_H
