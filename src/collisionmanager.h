//
// created by shu on 1/25/26 
//

#include "managernode.h"

class CollisionManager : public Node {
    public: 
        CollisionManager();
        void setCell(int x, int y, float radius, Node *collisionShape);
        Node** getNeighbours(int x, int y);
        int getListSize();
        int getCellVolume();
    private:
        int calculateListIndex(int x, int y); 
        int numX;
        int numY;
        int listSize;
        int cellVolume;
        Node*** collisionGridList;
};