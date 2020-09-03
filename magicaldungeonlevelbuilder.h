#ifndef MAGICALDUNGEONLEVELBUILDER_H
#define MAGICALDUNGEONLEVELBUILDER_H
#include <DungeonLevelBuilder.h>

class MagicalDungeonLevelBuilder: public DungeonLevelBuilder
{
public:
    MagicalDungeonLevelBuilder();
    ~MagicalDungeonLevelBuilder();

    virtual void builđungeonLevel(std::string name,int width, int height);
    virtual Room buildRoom(int id);
    virtual Room builDoorway(Room origin, Room destination, Direction direction, MoveConstraints constraints);
    virtual void buildEntrance(Room room, Room direction);
    virtual void buildExit(Room room, Direction direction);
    virtual void buildItem(Room);
    virtual void buildCreature(Room);
    virtual DungeonLevel getDungeonLevel();

};

#endif // MAGICALDUNGEONLEVELBUILDER_H
