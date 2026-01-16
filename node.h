//
// Created by shu on 1/14/26.
//

#include <list>

#ifndef SHIPGAME_NODE_H
#define SHIPGAME_NODE_H

class Node {
    public:
        std::list<Node> children;
        Node();
        void init();
        void update(float deltaTime);
        void draw();
};

#endif //SHIPGAME_NODE_H