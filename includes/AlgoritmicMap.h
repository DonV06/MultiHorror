//
// Created by znak zapytania on 28.06.2023.
//

#ifndef MULTIHORROR_ALGORITMICMAP_H
#define MULTIHORROR_ALGORITMICMAP_H

#include "AstarNode.h"
#include "Vector2f.h"
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
int DiagonalCost = 14;
int MovementCost = 10;
class AlgoritmicMap  {
public:
    AlgoritmicMap() {};
    std::vector<std::vector<AstarNode>> originalnodes;
    std::vector<AstarNode*> lastnodes;
    void draw(SDL_Renderer *renderer) {

        for (std::vector<AstarNode> xvector:  originalnodes) {
            for (AstarNode node: xvector) {
                float offset = node.rect.width / 2 / 2;
                SDL_Rect rectangle;
                rectangle.x = node.rect.x + offset;  // the x coordinate
                rectangle.y = node.rect.y + offset;  // the y coordinate
                rectangle.w = node.rect.width - node.rect.width / 2; // the width of the rectangle
                rectangle.h = node.rect.height - node.rect.height / 2;  // the height of the rectangle

                // Set draw color (RGBA)
                if (node.claimed) {


                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Red color
                }
                else if (node.obstructed) {
                    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
                }
                else {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Red color

                }
                // Draw filled rectangle
                SDL_RenderFillRect(renderer, &rectangle);
            }
        }
    }
    std::vector<std::pair<int, int>> GeneratePath(Vector2f start, Vector2f end, int depthLimit, int size) {
        std::vector<std::vector<AstarNode>> nodes;
        nodes = originalnodes;
        std::vector<std::vector<bool>> visited(nodes.size(), std::vector<bool>(nodes[0].size(), false));
        std::priority_queue<AstarNode*, std::vector<AstarNode*>, CompareNode> openList;

        nodes[start.getX()][start.getY()].g_cost = 0;
        nodes[start.getX()][start.getY()].calculateCosts(&nodes[end.getX()][end.getY()]);
        openList.push(&nodes[start.getX()][start.getY()]);

        int depth = 0;
        AstarNode* bestNode = nullptr;
        while (!openList.empty() && depth <= depthLimit) {
            AstarNode* currentNode = openList.top();
            openList.pop();

            if (currentNode->virtualLoaction == end) {  // We found the goal
                bestNode = currentNode;
                break;
            }

            if (bestNode == nullptr || currentNode->f_cost < bestNode->f_cost) {
                bestNode = currentNode;
            }

            visited[currentNode->virtualLoaction.getX()][currentNode->virtualLoaction.getY()] = true;

            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int newX = currentNode->virtualLoaction.getX() + x;
                    int newY = currentNode->virtualLoaction.getY() + y;

                    if (newX >= 0 && newX < nodes.size() - size + 1 && newY >= 0 && newY < nodes[0].size() - size + 1) {
                        bool obstructed = false;
                        for (int xi = 0; xi < size; xi++) {
                            for (int yi = 0; yi < size; yi++) {
                                if (nodes[newX + xi][newY + yi].obstructed) {
                                    obstructed = true;
                                    break;
                                }
                            }
                            if (obstructed) break;
                        }

                        if (!visited[newX][newY] && !obstructed) {
                            if ((x != 0) && (y != 0)) {  // Diagonal move
                                nodes[newX][newY].g_cost = currentNode->g_cost + std::sqrt(2);
                            } else {  // Straight move
                                nodes[newX][newY].g_cost = currentNode->g_cost + 1;
                            }
                            nodes[newX][newY].calculateCosts(&nodes[end.getX()][end.getY()]);
                            nodes[newX][newY].parent = currentNode;
                            openList.push(&nodes[newX][newY]);
                        }
                    }
                }
            }
            depth++;
        }

        std::vector<std::pair<int, int>> path;
        AstarNode* currentNode = bestNode;

        while (currentNode != nullptr) {
            currentNode->claimed = true;
            lastnodes.push_back(currentNode);
            path.push_back({currentNode->virtualLoaction.getX(), currentNode->virtualLoaction.getY()});
            currentNode = currentNode->parent;
        }

        std::reverse(path.begin(), path.end());  // We want the path from start to goal, not the other way around

        return path;
    }
    void bakeMap(std::vector<Rect> rects) {
        for (std::vector<AstarNode>& ynode: originalnodes) {
            for (AstarNode& node : ynode) {

                for (Rect rect : rects) {
                    if (rect.isCollidingPoint(Vector2f(node.rect.x, node.rect.y))) {
                        node.obstructed = true;
                    }
                }
            }
        }
    }
private:


};

#endif //MULTIHORROR_ALGORITMICMAP_H
