//
// Created by znak zapytania on 27.06.2023.
//
#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "Vector2f.h"
#include "Window.h"
#include "Rect.h"
#include "RectBlock.h"

#ifndef MULTIHORROR_WALL_H
#define MULTIHORROR_WALL_H
class Wall : public RectBlock
{
public:

    Wall(Vector2f locaction, Vector2f size) : RectBlock(locaction, size) {}

};
#endif //MULTIHORROR_WALL_H
