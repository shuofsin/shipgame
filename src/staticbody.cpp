//
// Created by shu on 2/3/26.
//

#include "staticbody.h"

StaticBody::StaticBody() : PhysicsNode() {
    collisionShape = new CollisionShape();
    children.push_back(collisionShape);

    CollisionManager *manager = (CollisionManager*)collisionManager;
    manager->setCell(collisionShape->getPosition().x, collisionShape->getPosition().y, collisionShape);
}

StaticBody::StaticBody(Vector2 _position, Circle _shape) : PhysicsNode(_position, {0, 0}) {
    collisionShape = new CollisionShape(_position, _shape);
    children.push_back(collisionShape);

    CollisionManager *manager = (CollisionManager*)collisionManager;
    manager->setCell(collisionShape->getPosition().x, collisionShape->getPosition().y, collisionShape);
}

CollisionShape* StaticBody::getCollisionShape() {
    return collisionShape;
}