//
// Created by shu on 1/15/26.
//

#include "node2d.h"

Node2D::Node2D() = default;

Node2D::Node2D(Vector2 _position, Vector2 _velocity, Vector2 _scale, float _rotation) {
    position = _position;
    velocity = _velocity;
    scale = _scale;
    rotation = _rotation;
}

void Node2D::init() {
    Node::init();
}

void Node2D::update(float deltaTime) {
    Node::update(deltaTime);
}

void Node2D::draw() {
    Node::draw();
}