//
// created by shu 1/27/26
//

#include "collisionmanager.h"

extern Node *collisionManager;
extern int windowWidth;
extern int windowHeight;
extern int spacing;

CollisionManager::CollisionManager() {
    numX = windowWidth / spacing;
    numY = windowHeight / spacing; 
    const int listSize = numX * numY;
    collisionGridList = new std::list<Node*>[numX * numY];
    collisionManager = this; 
}

void CollisionManager::setCell(int x, int y, Node *collisionShape) {
    int size = sizeof(collisionGridList) / sizeof(std::list<Node*>);
    for (int i = 0; i < size; i++) {
        collisionGridList[i].remove(collisionShape);
    }
    int index = calculateListIndex(x, y);
    collisionGridList[index].push_back(collisionShape);
}

std::list<Node*> *CollisionManager::getNeighbours(int x, int y) {
    int index = calculateListIndex(x, y);
    return &collisionGridList[index];
}


int CollisionManager::calculateListIndex(int x, int y) {
    int xi = std::floor(x / spacing);
    int yi = std::floor(y / spacing);
    return xi * numY + yi;
}