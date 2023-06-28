//
// Created by znak zapytania on 28.06.2023.
//
#include "AstarNode.h"


AstarNode::AstarNode(Vector2f location, Vector2f virtualLoaction, int size): virtualLoaction(virtualLoaction), rect(location, Vector2f(size, size)) {

}