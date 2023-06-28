//
// Created by DonV06 on 25.06.2023.
//
#include "Rect.h"

#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "Vector2f.h"
#include "Window.h"
#include <cmath>

Rect::Rect(Vector2f _loc, Vector2f _size) : x(_loc.getX()), y(_loc.getY()), width(_size.getX()), height(_size.getY()) {

}

bool Rect::isCollidingVectors(Vector2f __loc, Vector2f __size) {
    if (Rect::isCollidingPoint(Vector2f(__loc.getX(), __loc.getY()))) return true;
    if (Rect::isCollidingPoint(Vector2f(__loc.getX() + __size.getX(), __loc.getY()))) return true;
    if (Rect::isCollidingPoint(Vector2f(__loc.getX(), __loc.getY() + __size.getY()))) return true;
    if (Rect::isCollidingPoint(Vector2f(__loc.getX() + __size.getX(), __loc.getY() + __size.getY()))) return true;

    Rect temprect(__loc, __size);


    if (temprect.isCollidingPoint(Vector2f(x, y))) return true;
    if (temprect.isCollidingPoint(Vector2f(x+width, y))) return true;
    if (temprect.isCollidingPoint(Vector2f(x, y+height))) return true;
    if (temprect.isCollidingPoint(Vector2f(x+width, y+height))) return true;

    return false;
}

bool Rect::isCollidingRect(Rect rect) {
    if (Rect::isCollidingPoint(Vector2f(rect.x, rect.y))) return true;
    if (Rect::isCollidingPoint(Vector2f(rect.x + rect.width, rect.y))) return true;
    if (Rect::isCollidingPoint(Vector2f(rect.x, rect.y + rect.height))) return true;
    if (Rect::isCollidingPoint(Vector2f(rect.x + rect.width, rect.y + rect.height))) return true;
    Rect temprect(Vector2f(rect.x, rect.y),Vector2f(rect.width, rect.height));


    if (temprect.isCollidingPoint(Vector2f(x, y))) return true;
    if (temprect.isCollidingPoint(Vector2f(x+width, y))) return true;
    if (temprect.isCollidingPoint(Vector2f(x, y+height))) return true;
    if (temprect.isCollidingPoint(Vector2f(x+width, y+height))) return true;

    return false;
}

bool Rect::isCollidingPoint(Vector2f point) {
    if (x <= point.getX() && point.getX() <= (x + width) && y <= point.getY() && point.getY() <= (y + height)) return true;
    return false;
}



float Rect::angleBetweenRect(Rect rect) {

    float deltaY = rect.y - y;
    float deltaX = rect.x - x;


    deltaY = -deltaY;


    float angleRadians = std::atan2(deltaY, deltaX);


    angleRadians = -angleRadians - M_PI/2;

    return angleRadians;

}


