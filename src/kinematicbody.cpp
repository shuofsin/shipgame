//
// Created by shu on 1/21/26.
//

#include "kinematicbody.h"

KinematicBody::KinematicBody() : PhysicsNode() {
    collisionShape = new CollisionShape();
    children.push_back(collisionShape);
}

KinematicBody::KinematicBody(Vector2 _position, Vector2 _velocity, Circle _shape) : PhysicsNode(_position, _velocity) {
    collisionShape = new CollisionShape(_position, _shape);
    children.push_back(collisionShape);
}

void KinematicBody::moveAndCollide(float deltaTime) {
    // If not moving, don't move or collide
    if (velocity.x == 0 && velocity.y == 0)
        return;

    // NOTE: Not sure if we want to do deltaTime here, or in update functions. Probably update? 
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;

    // Check collisions
    collisionShape->setPosition(position);

    CollisionManager *manager = (CollisionManager*)collisionManager;

    // Set index
    manager->setCell(collisionShape->getPosition().x, collisionShape->getPosition().y, collisionShape);

    // Get neighbours
    auto neighbours = manager->getNeighbours(collisionShape->getPosition().x, collisionShape->getPosition().y);

    // Check collisions
    for (Node *it : neighbours) {
        CollisionShape *neighbour = (CollisionShape*)it;
    }
}

CollisionShape* KinematicBody::getCollisionShape() {
    return collisionShape;
}