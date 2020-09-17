#include "basicdungeonlevelbuilder.h"

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder(){}

BasicDungeonLevelBuilder::~BasicDungeonLevelBuilder(){

}


void BasicDungeonLevelBuilder::buildungeonLevel(std::string name,int width, int height)
{
    _name = name;
    _width = width;
    _height = height;
}

Room BasicDungeonLevelBuilder::buildRoom(int id){
    //create pointer for new room to access edges
    auto ptrRoom = std::make_shared<Room>(id);

    //Build walls and add to 4 edges
    RoomEdge *edge;
    edge = new Wall();
    ptrRoom->setNorth(edge);
    edge = new Wall();
    ptrRoom->setEast(edge);
    edge = new Wall();
    ptrRoom->setSouth(edge);
    edge = new Wall();
    ptrRoom->setWest(edge);

    //Delete all created pointer
    delete edge;

    return *ptrRoom;
}

