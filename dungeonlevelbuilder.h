#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H
#include<string>
#include <dungeonlevel.h>


class DungeonLevelBuilder
{
public:
    DungeonLevelBuilder();
    virtual ~DungeonLevelBuilder() = 0; // May need virtual

    enum class MoveConstraints : unsigned;

    virtual void buildungeonLevel(std::string name,int width, int height);
    virtual Room buildRoom(int id);
    virtual Room builDoorway(Room origin, Room destination, Room::Direction direction, DungeonLevelBuilder::MoveConstraints constraints);
    virtual void buildEntrance(Room room, Room::Direction direction);
    virtual void buildExit(Room room, Room::Direction direction);

//    virtual void buildItem(Room);
//    virtual void buildCreature(Room);
    DungeonLevel* getDungeonLevel(){
        return _Dungeonlevel;
    };

    enum class MoveConstraints : unsigned {
        None = 0,
        OriginImpassable = 1,
        DestinationImpassable = 2,
        OriginLocked = 4,
        DestinationLocked = 8,
    };


protected:
    DungeonLevel* _Dungeonlevel;
    std::string _name;
    int _width;
    int _height;
};

#endif // DUNGEONLEVELBUILDER_H
