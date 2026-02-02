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

        float distanceBetweenCenters = Vector2Distance(neighbour->getPosition(), collisionShape->getPosition());
        bool isColliding = (distanceBetweenCenters < (neighbour->getRadius() + collisionShape->getRadius()));

        // TODO: Collisions between two kinematic bodies
        // Currently, this works only for two cases: 
        // - collision between a moving kinematic body and a static body
        // - collision between two moving kinematic bodies
        // Cases to account more
        // - collision between a moving kinematic body and a stationary kinematic body
        if (isColliding) {
            this->collide(neighbourCenter.x, neighbourCenter.y);
        }
           
    }
}

void KinematicBody::collide(int x, int y) {
    Vector2 collisionVector = Vector2Subtract(position, {x, y});
    velocity = Vector2Add(velocity, collisionVector * 2);
}

CollisionShape* KinematicBody::getCollisionShape() {
    return collisionShape;
}