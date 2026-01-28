//
// created by shu 1/27/26
//

#ifndef SHIPGAME_PTRGLOBAL_H
#define SHIPGAME_PTRGLOBAL_H

#include "libs.h"
#include "node.h"

int windowWidth = 640;
int windowHeight = 480;
Color backgroundColor = DARKBLUE;  

int spacing = 40;
int numX = windowWidth / spacing;
int numY = windowHeight / spacing; 
const int listSize = numX * numY;

std::list<Node*> *collisionGridList = new std::list<Node*>[numX * numY];
Node *collisionManager;

#endif //SHIPGAME_PTRGLOBAL_H