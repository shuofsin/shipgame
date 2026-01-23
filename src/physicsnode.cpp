//
// Created by shu on 1/21/26.
//

#include "headers/physicsnode.h"

PhysicsNode::PhysicsNode() {
    children = std::list<Node>();
    position = Vector2();
    velocity = Vector2();
}

PhysicsNode::PhysicsNode(const Vector2 _position, const Vector2 _velocity) {
    children = std::list<Node>();
    position = _position;
    velocity = _velocity;
}

Node& PhysicsNode::getParent() {
    return parent;
}

Vector2 PhysicsNode::getPosition() const {
    return position;
}

Vector2 PhysicsNode::getVelocity() const {
    return velocity;
}