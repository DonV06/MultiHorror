//
// Created by DonV06 on 25.06.2023.
//
#include "Rect.h"

#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "vector2f.h"
#include "window.h"

Rect::Rect(vector2f _loc, vector2f _size) : x(_loc.getX()),y(_loc.getY()), width(_size.getX()), height(_size.getY()) {

}

bool Rect::isCollidingRect(vector2f __loc, vector2f __size) {
    if (Rect::isCollidingPoint(vector2f(__loc.getX(), __loc.getY()))) return true;
    if (Rect::isCollidingPoint(vector2f(__loc.getX()+__size.getX(), __loc.getY()))) return true;
    if (Rect::isCollidingPoint(vector2f(__loc.getX(), __loc.getY()+__size.getY()))) return true;
    if (Rect::isCollidingPoint(vector2f(__loc.getX()+__size.getX(), __loc.getY()+__size.getY()))) return true;

    return false;
}


bool Rect::isCollidingPoint(vector2f point) {
    if (x <= point.getX() && point.getX() <= (x + width) && y <= point.getY() && point.getY() <= (y + height)) return true;
    return false;
}

