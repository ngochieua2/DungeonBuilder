#include "basicdungeonlevelbuilder.h"

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder(){}

BasicDungeonLevelBuilder::~BasicDungeonLevelBuilder(){
    delete[] _wall;
    delete[] _door;
}


void BasicDungeonLevelBuilder::buildungeonLevel(std::string name,int width, int height)
{
     _Dungeonlevel = new BasicDungeonLevel(name, width, height);
}

std::shared_ptr<Room> BasicDungeonLevelBuilder::buildRoom(int id){
    //create pointer for new room to access edges
     std::shared_ptr<Room> Aroom = std::make_shared<Room>(id);

    //Build walls and add to 4 edges
    _wall = new RockWall();
    Aroom->setNorth(_wall);
    _wall = new RockWall();
    Aroom->setEast(_wall);
    _wall = new RockWall();
    Aroom->setSouth(_wall);
    _wall = new RockWall();
    Aroom->setWest(_wall);

    return Aroom;

}

void BasicDungeonLevelBuilder::builDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Room::Direction direction, MoveConstraints constraints){

}

void BasicDungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> room, Room::Direction direction){
    _door = new OneWayDoor();
    _door->setEntrance();
    if (direction == Room::Direction::North){
        room->setNorth(_door);
    }
    else if (direction == Room::Direction::East){
        room->setEast(_door);
    }
    else if (direction == Room::Direction::South){
        room->setSouth(_door);
    }
    else {
        room->setWest(_door);
    }
}

void BasicDungeonLevelBuilder::buildExit(std::shared_ptr<Room> room, Room::Direction direction){
    _door = new OneWayDoor();
    _door->setExit();
    if (direction == Room::Direction::North){
        room->setNorth(_door);
    }
    else if (direction == Room::Direction::East){
        room->setEast(_door);
    }
    else if (direction == Room::Direction::South){
        room->setSouth(_door);
    }
    else {
        room->setWest(_door);
    }
}

