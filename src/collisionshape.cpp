//
// Created by shu on 1/22/26.
//

#include "headers/global.h"
#include "headers/collisionshape.h"

CollisionShape::CollisionShape() {
    PhysicsNode::PhysicsNode();
    Shape shape = NULL;
    isDisabled = true; 
}

CollisionShape::CollisionShape(Vector2 _velocity, Vector2 _position, Shape _shape) {
    PhysicsNode::PhysicsNode(_velocity, _position);
    shape = _shape;
    isDisabled = false;
}

void setDisabled(bool _isDisabled) {
    isDisabled = _isDisabled;
}

bool getDisabled() {
    return isDisabled; 
}
