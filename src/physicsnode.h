//
// Created by shu on 1/21/26.
//

#ifndef SHIPGAME_PHYSICSNODE_H
#define SHIPGAME_PHYSICSNODE_H

#include "node.h"
#include "global.h"

class PhysicsNode : public Node {
    public:
        PhysicsNode();
        PhysicsNode(Vector2 _position, Vector2 _velocity);
        Node& getParent();
        Vector2 getPosition() const;
        Vector2 getVelocity() const;
    protected:
        Vector2 position{};
        Vector2 velocity{};
        Node parent;
        void moveAndCollide(float deltaTime);
        void moveAndSlide(float deltaTime);
};


#endif //SHIPGAME_PHYSICSNODE_H