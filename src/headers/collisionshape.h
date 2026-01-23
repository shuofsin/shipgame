//
// created by shu on 1/22/26
//

#ifndef SHIPGAME_COLLISIONSHAPE_H
#define SHIPGAME_COLLISIONSHAPE_H

#include "global.h"
#include "physicsnode.h"

class CollisionShape : public PhysicsNode {
    public: 
        CollisionShape();
        CollisionShipe(Vector2 _velocity, Vector2 _position, Shape _shape);
        void setDisabled(bool _isDisabled);
        bool getDisabled();
    private: 
        bool isDisabled
        Shape shape; 
}



#endif // SHIPGAME_COLLISIONSHAPE_H