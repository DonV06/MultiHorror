//
// Created by DonV06 on 25.06.2023.
//
#include "Rect.h"

#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "vector2f.h"
#include "window.h"

Rect::Rect(vector2f _loc, vector2f _size) : loc(_loc), size(_size) {

}

bool Rect::isCollidingRect(vector2f __loc, vector2f __size) {
    if (Rect::isCollidingPoint(vector2f(__loc.getX(), __loc.getY()))) return true;
    if (Rect::isCollidingPoint(vector2f(__loc.getX()+__size.getX(), __loc.getY()))) return true;
    if (Rect::isCollidingPoint(vector2f(__loc.getX(), loc.getY()+__size.getY()))) return true;
    if (Rect::isCollidingPoint(vector2f(__loc.getX()+__size.getX(), __loc.getY()+__size.getY()))) return true;

    return false;
}

vector2f Rect::getloc() {
    return loc;
}

vector2f Rect::getsize() {
    return size;
}

bool Rect::isCollidingPoint(vector2f point) {
    if (loc.getX() < point.getX() && point.getX() < (loc.getX() + size.getX()) && loc.getY() < point.getY() && point.getY() < (loc.getY() + size.getY())) return true;
    return false;
}

