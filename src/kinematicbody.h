//
// created by shu on 1/23/25
//

#ifndef SHIPGAME_KINEMATICBODY_H
#define SHIPGAME_KINEMATICBODY_H

#include "physicsnode.h"

extern Node* collisionManager;

class KinematicBody : public PhysicsNode {
    public:
        KinematicBody();
        KinematicBody(Vector2 _position, Vector2 _velocity, Circle _shape);
        void moveAndCollide(float deltaTime);
        CollisionShape* getCollisionShape();
        void collide(int otherX, int otherY);
    protected:
        CollisionShape *collisionShape;
};



#endif // SHIPGAME_KINEMATICBODY_H
