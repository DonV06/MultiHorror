//
// Created by znak zapytania on 28.06.2023.
//

#include "AlgoritmicMap.h"
#include "AstarNode.h"

AlgoritmicMap::AlgoritmicMap() {

}

void AlgoritmicMap::draw(SDL_Renderer *renderer) {

    for (AstarNode node: nodes) {
        float offset = node.rect.width/2/2;
        SDL_Rect rectangle;
        rectangle.x = node.rect.x+offset;  // the x coordinate
        rectangle.y = node.rect.y+offset;  // the y coordinate
        rectangle.w = node.rect.width-node.rect.width/2; // the width of the rectangle
        rectangle.h = node.rect.height-node.rect.height/2;  // the height of the rectangle

// Set draw color (RGBA)
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Red color

// Draw filled rectangle
        SDL_RenderFillRect(renderer, &rectangle);

    }
}