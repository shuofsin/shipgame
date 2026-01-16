//
// Created by shu on 1/15/26.
//

#ifndef SHIPGAME_CHARACTER_H
#define SHIPGAME_CHARACTER_H
#include "node2d.h"

// TODO: Figure out what the fuck the character actually needs to do and also member variables

class Character : public Node2D{
    public:
        Character();
        void init();
        void update(float deltaTime);
        void draw();
};


#endif //SHIPGAME_CHARACTER_H