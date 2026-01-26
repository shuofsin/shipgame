//
// Created by shu on 1/21/26.
//

#ifndef SHIPGAME_PHYSICSNODE_H
#define SHIPGAME_PHYSICSNODE_H

#include "../globals/node.h"

class PhysicsNode : public Node {
    public:
        PhysicsNode();
        PhysicsNode(Vector2 _position, Vector2 _velocity);
        void setPosition(Vector2 _position);
        Vector2 getPosition() const;
        void setVelocity(Vector2 _velocity);
        Vector2 getVelocity() const;
    protected:
        Vector2 position{};
        Vector2 velocity{};
};


#endif //SHIPGAME_PHYSICSNODE_H