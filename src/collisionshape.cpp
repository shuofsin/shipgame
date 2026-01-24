//
// Created by shu on 1/22/26.
//

#include "headers/global.h"
#include "headers/collisionshape.h"

CollisionShape::CollisionShape() : Node() {
    position = {0, 0};
    shape = {};
    isDisabled = false; 
    isVisible = true;
}

CollisionShape::CollisionShape(Vector2 _position, Circle _shape) : Node() {
    position = _position;
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

void CollisionShape::setPosition(Vector2 _position) {
    position = _position; 
    shape.x = position.x;
    shape.y = position.y;
}

Vector2 CollisionShape::getPosition() {
    return position;
}

void CollisionShape::draw() {
    Node::draw();
    if (!isVisible) return; 
    Color color = (isDisabled ? Color({255, 255, 255, 100}) : Color({0, 255, 0, 110}));
    DrawCircle(shape.x, shape.y, shape.radius, color);
}