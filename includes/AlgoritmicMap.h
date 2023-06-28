//
// Created by znak zapytania on 28.06.2023.
//

#ifndef MULTIHORROR_ALGORITMICMAP_H
#define MULTIHORROR_ALGORITMICMAP_H

#include "AstarNode.h"
#include "Vector2f.h"

class AlgoritmicMap  {
public:
    AlgoritmicMap();
    std::vector<AstarNode> nodes;
    void draw(SDL_Renderer* renderer);
private:

};

#endif //MULTIHORROR_ALGORITMICMAP_H
