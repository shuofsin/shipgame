//
// Created by shu on 1/15/26.
//
#include "node.h"
#include <raylib.h>

#ifndef SHIPGAME_NODE2D_H
#define SHIPGAME_NODE2D_H


class Node2D : public Node {
    public:
        Vector2 position;
        Vector2 velocity;
        Vector2 scale;
        float rotation;
        Node2D();
        Node2D(Vector2 _position, Vector2 _velocity, Vector2 _scale, float _rotation);
        void init();
        void update(float deltaTime);
        void draw();
};


#endif //SHIPGAME_NODE2D_H