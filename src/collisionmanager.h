//
// created by shu on 1/25/26 
//

#include "managernode.h"
#include "collisionshape.h"
#include "globalvars.h"

class CollisionManager : public Node {
    public: 
        CollisionManager();
        void setCell(CollisionShape *collisionShape);
        std::list<Node*> *collidingNeighbours(CollisionShape *collisionShape);
    private:
        int calculateListIndex(int x, int y); 
};