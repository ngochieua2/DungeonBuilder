#ifndef DOORWAY_H
#define DOORWAY_H
#include<roomedge.h>

class Doorway : public RoomEdge
{
public:
    Doorway();
    ~Doorway();

    void connect (Doorway opposite);

    bool isEntrance();
    bool isExit();
};

#endif // DOORWAY_H
