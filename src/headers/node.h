//
// Created by shu on 1/14/26.
//

#ifndef SHIPGAME_NODE_H
#define SHIPGAME_NODE_H

#include "global.h"

/**
 * @class Node
 * @brief This is the parent node of all objects in the game.
 * All other classes inherit from it, and the root node at the
 * top of the scene tree is of its type.
 */
class Node {
    public:
        Node();
        void init();
        void update(float deltaTime);
        void draw();
        std::list<Node>& getChildren();
    protected:
        std::list<Node> children;
};

#endif //SHIPGAME_NODE_H