//
// created by shu on 2/3/25
//

#ifndef SHIPGAME_STATICBODY_H
#define SHIPGAME_STATICBODY_H

#include "physicsnode.h"

extern Node* collisionManager;

class StaticBody : public PhysicsNode {
    public:
        StaticBody();
        StaticBody(Vector2 _position, Circle _shape);
        CollisionShape* getCollisionShape();
    protected:
        CollisionShape *collisionShape;
};

#endif // SHIPGAME_STATICBODY_H
