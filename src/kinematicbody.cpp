//
// Created by shu on 1/21/26.
//

#include "kinematicbody.h"

KinematicBody::KinematicBody() : PhysicsNode() {
    collisionShape = new CollisionShape();
    children.push_back(collisionShape);

    CollisionManager *manager = (CollisionManager*)collisionManager;
    manager->setCell(collisionShape->getPosition().x, collisionShape->getPosition().y, collisionShape);
}

KinematicBody::KinematicBody(Vector2 _position, Vector2 _velocity, Circle _shape) : PhysicsNode(_position, _velocity) {
    collisionShape = new CollisionShape(_position, _shape);
    children.push_back(collisionShape);

    CollisionManager *manager = (CollisionManager*)collisionManager;
    manager->setCell(collisionShape->getPosition().x, collisionShape->getPosition().y, collisionShape);
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
    Node** neighbours = manager->getNeighbours(collisionShape->getPosition().x, collisionShape->getPosition().y);

    // Check collisions
    for (int i = 0; i < manager->getCellVolume(); i++) {
        CollisionShape *neighbour = (CollisionShape*)neighbours[i];
        if (neighbour == collisionShape || neighbour == nullptr)
            continue;

        Vector2 neighbourCenter = {neighbour->getPosition().x, neighbour->getPosition().y};
        Vector2 center = {collisionShape->getPosition().x, collisionShape->getPosition().x};

        if (CheckCollisionCircles(neighbourCenter, neighbour->getRadius(), center, collisionShape->getRadius()))
            collide(neighbourCenter.x, neighbourCenter.y);
    }
}

void KinematicBody::collide(int x, int y) {
    printf("Colliding!\n");
}

CollisionShape* KinematicBody::getCollisionShape() {
    return collisionShape;
}