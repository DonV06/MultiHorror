//
// Created by DonV06 on 18.06.2023.
//

#include "iostream"
#include "vector2f.h"

float vector2f::getX() {
    return x;
}

float vector2f::getY() {
    return y;
}

void vector2f::setX(float _x) {
    x = _x;
}

void vector2f::setY(float _y) {
    y = _y;
}

vector2f::vector2f(float _x, float _y): x(_x), y(_y) {
}



void vector2f::addX(float _x) {
    x += _x;

}

void vector2f::addY(float _y) {
    y += _y;
    std::cout << "Adding: " << _y << " Result: " << y << std::endl;
}
