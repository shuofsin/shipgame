//
// created by shu 1/24/26
//

#ifndef SHIPGAME_PLAYER_H
#define SHIPGAME_PLAYER_H

#include "kinematicbody.h"

class Player : public KinematicBody {
    public:
        Player();
        Player(Vector2 _position, Vector2 _velocity, Circle _shape, Rectangle _texture, float _maxSpeed, float _turnSpeed);
        void init() override;
        void update(float deltaTime) override;
        void draw() override;
    private:
        Rectangle texture;
        float maxSpeed;
        float turnSpeed;
        float angle;
};

#endif // SHIPGAME_PLAYER_H