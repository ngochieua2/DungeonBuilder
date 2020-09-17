#ifndef WALL_H
#define WALL_H
#include <roomedge.h>

class Wall : public RoomEdge
{
public:
    Wall();
    ~Wall();

    bool isPassage();



};

#endif // WALL_H
