//
// Created by znak zapytania on 28.06.2023.
//

#include "Rect.h"
#include "Vector2f.h"


#ifndef MULTIHORROR_ASTARNODES_H
#define MULTIHORROR_ASTARNODES_H

class AstarNode {
public:
    AstarNode(Vector2f location, Vector2f virtualLoaction, int size);
    Rect rect;
    bool obstructed = false;
private:
    Vector2f virtualLoaction;
};

#endif //MULTIHORROR_ASTARNODES_H
