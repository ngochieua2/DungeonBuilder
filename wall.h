#ifndef WALL_H
#define WALL_H
#include <roomedge.h>
#include <string>

class Wall : public RoomEdge
{
public:
    Wall();
    ~Wall();

    std::string description() override;

    bool isPassage();



};

#endif // WALL_H
