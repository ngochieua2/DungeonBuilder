#include "basicdungeonlevelbuilder.h"

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder(){}

BasicDungeonLevelBuilder::~BasicDungeonLevelBuilder(){
    delete[] _edge;
    //delete[] _wall;
    //delete[] _door;
}


void BasicDungeonLevelBuilder::buildungeonLevel(std::string name,int width, int height)
{
     _Dungeonlevel = new BasicDungeonLevel(name, width, height);
}

std::shared_ptr<Room> BasicDungeonLevelBuilder::buildRoom(int id){
    //create pointer for new room to access edges
     std::shared_ptr<Room> Aroom = std::make_shared<QuartzChamber>(id);

    //Build walls and add to 4 edges
    _edge = new RockWall();
    Aroom->setEdge(_edge, Room::Direction::North);
    _edge = new RockWall();
    Aroom->setEdge(_edge, Room::Direction::East);
    _edge = new RockWall();
    Aroom->setEdge(_edge, Room::Direction::South);
    _edge = new RockWall();
    Aroom->setEdge(_edge, Room::Direction::West);

    return Aroom;

}

void BasicDungeonLevelBuilder::builDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination,
                                           Room::Direction direction, MoveConstraints constraints){

    //condition and build an opendoorway
    if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::None)|
                                     static_cast<unsigned>(MoveConstraints::None))){
        _edge = new OpenDoorWay();
        origin->setEdge(_edge,direction);
        //destination->edgeAt(getOppositeDirection(direction))
        //set connect
        _edge = new OpenDoorWay();
        destination->setEdge(_edge, getOppositeDirection(direction));

    }
    //condition and build an onewaydoor from origin to destination
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginImpassable)|
                                     static_cast<unsigned>(MoveConstraints::None))){
        _edge = new OneWayDoor();
        origin->setEdge(_edge,direction);
        //set connect
        _edge = new BlockedDoorWay();
        destination->setEdge(_edge, getOppositeDirection(direction));

    }
    //condition and build an onewaydoor from destination to origin
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::None)|
                                     static_cast<unsigned>(MoveConstraints::DestinationImpassable))){
        _edge = new BlockedDoorWay();
        origin->setEdge(_edge,direction);
        //set connect
        _edge = new OneWayDoor();
        destination->setEdge(_edge, getOppositeDirection(direction));

    }
    //condition and build an blockedDoorway from origin to destination
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginImpassable)|
                                     static_cast<unsigned>(MoveConstraints::DestinationImpassable))){
        _edge = new BlockedDoorWay();
        origin->setEdge(_edge,direction);
        //set connect
        _edge = new BlockedDoorWay();
        destination->setEdge(_edge, getOppositeDirection(direction));

    }
    //condition and build an lockedDoorway from origin to destination
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginLocked)|
                                     static_cast<unsigned>(MoveConstraints::DestinationLocked))){
        _edge = new LockedDoor();
        origin->setEdge(_edge,direction);
        //set connect
        _edge = new LockedDoor();
        destination->setEdge(_edge, getOppositeDirection(direction));

    }
    else{
        //Do nothing
    }
}

void BasicDungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> room, Room::Direction direction){
    _edge = new OneWayDoor();
    _edge->setEntrance();
    room->setEdge(_edge,direction);
}

void BasicDungeonLevelBuilder::buildExit(std::shared_ptr<Room> room, Room::Direction direction){
    _edge = new OneWayDoor();
    _edge->setExit();
    room->setEdge(_edge,direction);
}

