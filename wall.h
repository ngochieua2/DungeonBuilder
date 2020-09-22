#ifndef WALL_H
#define WALL_H
#include <roomedge.h>
#include <string>

namespace core::dungeon{

class Wall : public RoomEdge
{
public:
    Wall();
    ~Wall();

    std::string description() override;

    bool isPassage()override;

};

}

#endif // WALL_H
