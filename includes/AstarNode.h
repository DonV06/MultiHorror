//
// Created by znak zapytania on 28.06.2023.
//

#include "Rect.h"
#include "Vector2f.h"
#include <iostream>


#ifndef MULTIHORROR_ASTARNODES_H
#define MULTIHORROR_ASTARNODES_H

class AstarNode {
public:
    Vector2f location;
    Vector2f virtualLoaction;
    Rect rect;
    int size;
    int f_cost;
    int g_cost;  // Cost from start to this node
    int h_cost;  // Heuristic cost from this node to the goal
    int cost;  // Total cost (g_cost + h_cost)
    bool claimed = false;
    AstarNode* parent;  // Parent node in the path
    bool obstructed = false;
    std::pair<int, int> fromMove = {-1, -1};

    AstarNode(Vector2f loc, Vector2f virtLoc, int sz)
            : location(loc), virtualLoaction(virtLoc), size(sz), rect(loc, Vector2f(size, size)), g_cost(INT_MAX), h_cost(0), cost(INT_MAX), parent(nullptr) {}

    void calculateCosts(AstarNode* goal) {
        // Use Manhattan distance as heuristic
        h_cost = abs(virtualLoaction.getX() - goal->virtualLoaction.getX()) + abs(virtualLoaction.getY() - goal->virtualLoaction.getY());
        cost = g_cost + h_cost;
    }
};

// Comparator function to sort the nodes by cost in the priority queue
struct CompareNode {
    bool operator()(AstarNode* a, AstarNode* b) {
        return a->cost > b->cost;
    }
};


#endif //MULTIHORROR_ASTARNODES_H
