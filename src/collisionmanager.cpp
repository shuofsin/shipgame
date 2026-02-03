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

void CollisionManager::setCell(int x, int y, float radius, Node *collisionShape) {
    if (!collisionShape)
        return;

    for (int i = 0; i < listSize; i++) {
        for (int j = 0; j < cellVolume; j++) {
            if (collisionGridList[i][j] == collisionShape)
                collisionGridList[i][j] = nullptr;
        }
    }

    int indices[5] = {
        calculateListIndex(x, y),
        calculateListIndex(x + radius, y),
        calculateListIndex(x - radius, y),
        calculateListIndex(x, y + radius),
        calculateListIndex(x, y - radius)
    };

    for (int i = 0; i < 5; i++) {
        if (indices[i] < 0 || indices[i] >= listSize)
            continue;
        for (int j = 0; j < cellVolume; j++) {
            if (collisionGridList[indices[i]][j] == collisionShape)
                break;

            if (collisionGridList[indices[i]][j] == nullptr) {
                collisionGridList[indices[i]][j] = collisionShape;
                continue;
            }
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