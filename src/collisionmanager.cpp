//
// created by shu 1/27/26
//

#include "collisionmanager.h"

CollisionManager::CollisionManager() {
    collisionManager = this; 
}

void CollisionManager::setCell(CollisionShape *collisionShape) {
    int index = calculateListIndex(collisionShape->getPosition().x, collisionShape->getPosition().y);
    collisionGridList[index].push_back(collisionShape);
}

std::list<Node*> *CollisionManager::collidingNeighbours(CollisionShape *collisionShape) {
    int index = calculateListIndex(collisionShape->getPosition().x, collisionShape->getPosition().y);
    std::list<Node*> *collidingList = new std::list<Node*>();
    for (Node *shape : collisionGridList[index]) {
        CollisionShape *otherShape = (CollisionShape*)shape;
        if (otherShape == collisionShape)
            continue;



        Vector2 centerOne = {collisionShape->getShape().x, collisionShape->getShape().y};
        float radiusOne = collisionShape->getShape().radius;
        Vector2 centerTwo = {otherShape->getShape().x, otherShape->getShape().y};
        float radiusTwo = collisionShape->getShape().radius;
        if (CheckCollisionCircles(centerOne, radiusOne, centerTwo, radiusTwo)) {
            collidingList->push_back(shape);
        }
    }

    return collidingList;
}


int calculateListIndex(int x, int y) {
    return x * numY + y;
}