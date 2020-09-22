#include "dungeonlevel.h"

using core::dungeon::Room;
using core::dungeon::DungeonLevel;

DungeonLevel::DungeonLevel()
{}

DungeonLevel::DungeonLevel(std::string &name, int &width, int &height): _name{name}, _width{width}, _height{height}
{}

DungeonLevel::~DungeonLevel(){}

bool DungeonLevel::addRoom(std::shared_ptr<Room> room){

    allRoom.push_back(room);
    return true;
}

std::shared_ptr<Room> DungeonLevel::retrieveRoom(int i)
{
    return allRoom.at(i-1);
}


int DungeonLevel::width(){
    return _width;
}
int DungeonLevel::height(){
    return _height;
}
int DungeonLevel::numberOfRooms(){
    return width()*height();
}
std::string DungeonLevel::name(){
    return _name;
}

std::string DungeonLevel::description(){
    return "this is DungeonLevel description";
}


//std::string[] display();
