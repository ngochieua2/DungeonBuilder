#include "dungeonlevelbuilder.h"

DungeonLevelBuilder::DungeonLevelBuilder(){}

DungeonLevelBuilder::~DungeonLevelBuilder(){
    delete _Dungeonlevel;
}

void DungeonLevelBuilder::buildungeonLevel(std::string name,int width, int height){}
std::shared_ptr<Room> DungeonLevelBuilder::buildRoom(int id){}
void DungeonLevelBuilder::builDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Room::Direction direction, DungeonLevelBuilder::MoveConstraints constraints){}
void DungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> room, Room::Direction direction){}
void DungeonLevelBuilder::buildExit(std::shared_ptr<Room> room, Room::Direction direction){}
//    virtual void buildItem(Room);
//    virtual void buildCreature(Room);

DungeonLevel *DungeonLevelBuilder::getDungeonLevel()
{
    return _Dungeonlevel;
}

Room::Direction DungeonLevelBuilder::getOppositeDirection(Room::Direction direction)
{
    if (direction == Room::Direction::North){
        return Room::Direction::South;
    }
    else if (direction == Room::Direction::South) {
        return Room::Direction::North;
    }
    else if (direction == Room::Direction::West) {
        return Room::Direction::East;
    }
    else{
        return Room::Direction::West;
    }
}







