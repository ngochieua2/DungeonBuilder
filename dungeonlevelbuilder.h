#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H
#include<string>

class DungeonLevelBuilder
{
public:
    DungeonLevelBuilder();
    ~DungeonLevelBuilder(); // May need virtual

    virtual void builđungeonLevel(std::string name,int width, int height);
    virtual Room buildRoom(int id);
    virtual Room builDoorway(Room origin, Room destination, Direction direction, MoveConstraints constraints);
    virtual void buildEntrance(Room room, Room direction);
    virtual void buildExit(Room room, Direction direction);
    virtual void buildItem(Room);
    virtual void buildCreature(Room);
    virtual DungeonLevel getDungeonLevel();

protected:
    DungeonLevel* _level;
};

#endif // DUNGEONLEVELBUILDER_H
