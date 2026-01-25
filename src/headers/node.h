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
        virtual void init();
        virtual void update(float deltaTime);
        virtual void draw();
        std::list<Node*>& getChildren();
        void addChild(Node *child);
        void removeChild(Node *child);
        Node *getParent();
        void setParent(Node *_parent);
    protected:
        std::list<Node*> children;
        Node *parent;
};

#endif //SHIPGAME_NODE_H