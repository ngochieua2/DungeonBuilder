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




