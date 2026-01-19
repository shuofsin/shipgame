//
// Created by shu on 1/14/26.
//

#include <list>

#ifndef SHIPGAME_NODE_H
#define SHIPGAME_NODE_H

/**
 * @class Node
 * @brief This is the parent node of all objects in the game.
 * All other classes inherit from it, and the root node at the
 * top of the scene tree is of its type.
 */
class Node {
    public:
        std::list<Node> children;
        Node();
        void init();
        void update(float deltaTime);
        void draw();
};

#endif //SHIPGAME_NODE_H