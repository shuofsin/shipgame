//
// created by shu on 1/22/26
//

#ifndef SHIPGAME_COLLISIONSHAPE_H
#define SHIPGAME_COLLISIONSHAPE_H

#include "node.h"
#include "structglobal.h"

class CollisionShape : public Node {
    public: 
        CollisionShape();
        CollisionShape(Vector2 _position, Circle _shape);
        void setDisabled(bool _isDisabled);
        bool getDisabled();
        void setVisible(bool _isVisible);
        bool getVisible();
        void setPosition(Vector2 _position);
        Vector2 getPosition();
        void setRadius(float _radius);
        float getRadius();
        void draw() override;
        Circle getShape();
    private: 
        Vector2 position;
        bool isDisabled;
        bool isVisible;
        Circle shape; 
};



#endif // SHIPGAME_COLLISIONSHAPE_H