//
// created by shu 1/24/26
//

#ifndef SHIPGAME_PLAYER_H
#define SHIPGAME_PLAYER_H

#include "global.h"
#include "kinematicbody.h"

class Player : public KinematicBody {
    public:
        Player();
        Player(Vector2 _position, Vector2 _velocity, Shape _shape, Rectangle _texture, float _maxSpeed, float _turnSpeed);
        void init();
        void update(float deltaTime);
        void draw();
    private:
        Rectangle texture;
        float maxSpeed;
        float turnSpeed;
        float angle;
};

#endif // SHIPGAME_PLAYER_H