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
        collisionGridList[i] = new Node*[cellVolume];
        for (int j = 0; j < cellVolume; j++) {
            collisionGridList[i][j] = nullptr;
        }
    }
    collisionManager = this; 
}

void CollisionManager::setCell(int x, int y, Node *collisionShape) {
    if (!collisionShape)
        return;

    for (int i = 0; i < listSize; i++) {
        for (int j = 0; j < cellVolume; j++) {
            if (collisionGridList[i][j] == collisionShape)
                collisionGridList[i][j] = nullptr;
        }
    }

    int index = calculateListIndex(x, y);

    if (index < 0 || index >= listSize)
        return; 

    for (int j = 0; j < cellVolume; j++) {
        if (collisionGridList[index][j] == nullptr) {
            collisionGridList[index][j] = collisionShape; //is not being set properly
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