//
// Created by shu on 1/21/26.
//

#include "headers/physicsnode.h"

PhysicsNode::PhysicsNode() : Node () {
    position = Vector2Zero();
    velocity = Vector2Zero();
}

PhysicsNode::PhysicsNode(Vector2 _position, Vector2 _velocity) : Node() {
    position = _position;
    velocity = _velocity;
}

Node& PhysicsNode::getParent() {
    return parent;
}

void PhysicsNode::setPosition(Vector2 _position) {
    position = _position;
}

Vector2 PhysicsNode::getPosition() const {
    return position;
}

void PhysicsNode::setVelocity(Vector2 _velocity) {
    velocity = _velocity;
}

Vector2 PhysicsNode::getVelocity() const {
    return velocity;
}