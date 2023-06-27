//
// Created by DonV06 on 18.06.2023.
//

#ifndef HORRORGAME_VECTOR2F_H
#define HORRORGAME_VECTOR2F_H

class Vector2f
{
public:
    float getY();
    float getX();
    void setY(float _y);
    void setX(float _x);
    void addX(float _x);
    void addY(float _y);
    Vector2f(float _x, float _y);
    float x;
    float y;
private:
};

#endif //HORRORGAME_VECTOR2F_H
