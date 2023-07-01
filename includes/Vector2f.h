//
// Created by DonV06 on 18.06.2023.
//

#ifndef HORRORGAME_VECTOR2F_H
#define HORRORGAME_VECTOR2F_H

class Vector2f
{
public:
    float x;
    float y;
    float getX() {return x;}
    float getY() {return y;}
    void setX(float _x) {
        x = _x;
    }
    void setY(float _y) {
        y = _y;
    }
    Vector2f(float _x, float _y): x(_x), y(_y) {
    }
    void addX(float _x) {
        x += _x;

    }
    void addY(float _y) {
        y += _y;
        std::cout << "Adding: " << _y << " Result: " << y << std::endl;
    }
    void addVector(Vector2f vector) {
        x += vector.x;
        y += vector.y;
    }
    bool operator==(const Vector2f& other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Vector2f& other) const {
        return x != other.x || y != other.y;
    }
private:
};

#endif //HORRORGAME_VECTOR2F_H
