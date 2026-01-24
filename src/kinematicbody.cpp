//
// Created by shu on 1/21/26.
//

#include "headers/kinematicbody.h"

KinematicBody::KinematicBody() : PhysicsNode() {
    collisionShape = new CollisionShape();
}

KinematicBody::KinematicBody(Vector2 _position, Vector2 _velocity, Shape _shape) : PhysicsNode(_position, _velocity) {
    collisionShape = new CollisionShape(_position, _velocity, _shape);
}

void KinematicBody::moveAndCollide(float deltaTime) {
    // If not moving, don't move or collide
    if (velocity.x == 0 && velocity.y == 0)
        return;

    // NOTE: Not sure if we want to do deltaTime here, or in update functions. Probably update? 
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
}

CollisionShape* KinematicBody::getCollisionShape() {
    return collisionShape;
}