//
// created by shu on 1/25/26 
//

#include "managernode.h"

class CollisionManager : public Node {
    public: 
        CollisionManager();
        void setCell(int x, int y, Node *collisionShape);
        std::list<Node*> *collidingNeighbours(int x, int y);
    private:
        int calculateListIndex(int x, int y); 
        std::list<Node*> *collisionGridList;
        int numX;
        int numY;
};