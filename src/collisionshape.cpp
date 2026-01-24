//
// Created by shu on 1/22/26.
//

#include "headers/global.h"
#include "headers/collisionshape.h"

CollisionShape::CollisionShape() : PhysicsNode() {
    Shape shape = {};
    isDisabled = false; 
    isVisible = true;
}

CollisionShape::CollisionShape(Vector2 _position, Vector2 _velocity, Shape _shape) : PhysicsNode(_position, _velocity){
    shape = _shape;
    isDisabled = false;
    isVisible = true; 
}

void CollisionShape::setDisabled(bool _isDisabled) {
    isDisabled = _isDisabled;
}

bool CollisionShape::getDisabled() {
    return isDisabled; 
}

void CollisionShape::setVisible(bool _isVisible) {
    isVisible = _isVisible;
}

bool CollisionShape::getVisible() {
    return isVisible; 
}