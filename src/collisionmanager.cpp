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
    listSize = numX * numY;
    cellVolume = 16;
    collisionGridList = new Node**[listSize];
    for (int i = 0; i < listSize; i++) {
        collisionGridList[i] = new Node*[cellVolume]; // Assuming more than 16 objects won't share a space
    }
    collisionManager = this; 
}

void CollisionManager::setCell(int x, int y, Node *collisionShape) {
    for (int i = 0; i < listSize; i++) {
        for (int j = 0; j < cellVolume; j++) {
            if (collisionGridList[i][j] == collisionShape)
                collisionGridList[i][j] = NULL;
        }
    }
    int index = calculateListIndex(x, y);
    for (int j = 0; j < cellVolume; j++) {
        if (collisionGridList[index][j] == NULL) {
            collisionGridList[index][j] = collisionShape;
            break;
        } 
    }
}

Node** CollisionManager::getNeighbours(int x, int y) {
    int index = calculateListIndex(x, y);
    return collisionGridList[index];
}


int CollisionManager::calculateListIndex(int x, int y) {
    int xi = std::floor(x / spacing);
    int yi = std::floor(y / spacing);
    return xi * numY + yi;
}

int CollisionManager::getListSize() {
    return listSize;
}

int CollisionManager::getCellVolume() {
    return cellVolume;
}