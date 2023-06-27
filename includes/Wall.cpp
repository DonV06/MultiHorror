//
// Created by znak zapytania on 27.06.2023.
//
#include "../libs/SDL2_base/include/SDL2/SDL.h"
#include <vector>
#include "Vector2f.h"
#include "Window.h"
#include "Rect.h"
#include "RectBlock.h"
#include "Wall.h"

Wall::Wall(Vector2f locaction, Vector2f size) : RectBlock(locaction, size) {}