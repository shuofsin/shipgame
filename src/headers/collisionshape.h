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
        CollisionShape(Vector2 _position, Vector2 _velocity, Shape _shape);
        void setDisabled(bool _isDisabled);
        bool getDisabled();
        void setVisible(bool _isVisible);
        bool getVisible();
    private: 
        bool isDisabled;
        bool isVisible;
        Shape shape; 
};



#endif // SHIPGAME_COLLISIONSHAPE_H