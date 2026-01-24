//
// created by shu on 1/23/25
//

#ifndef SHIPGAME_KINEMATICBODY_H
#define SHIPGAME_KINEMATICBODY_H

#include "global.h"
#include "physicsnode.h"
#include "collisionshape.h"

class KinematicBody : public PhysicsNode {
    public:
        KinematicBody();
        KinematicBody(Vector2 _position, Vector2 _velocity, Circle _shape);
        void moveAndCollide(float deltaTime);
        CollisionShape* getCollisionShape();
    private:
        CollisionShape *collisionShape;
};



#endif // SHIPGAME_KINEMATICBODY_H
