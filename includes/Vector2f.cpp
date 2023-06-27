//
// Created by DonV06 on 18.06.2023.
//

#include "iostream"
#include "Vector2f.h"

float Vector2f::getX() {
    return x;
}

float Vector2f::getY() {
    return y;
}

void Vector2f::setX(float _x) {
    x = _x;
}

void Vector2f::setY(float _y) {
    y = _y;
}

Vector2f::Vector2f(float _x, float _y): x(_x), y(_y) {
}



void Vector2f::addX(float _x) {
    x += _x;

}

void Vector2f::addY(float _y) {
    y += _y;
    std::cout << "Adding: " << _y << " Result: " << y << std::endl;
}
