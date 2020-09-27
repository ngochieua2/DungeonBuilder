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

    /*
     * Function isPassage is used to distinguish wall,
     * entrance, exit (false) or a normal doorway (true)
     */
    bool isPassage()override;

};

}

#endif // WALL_H
