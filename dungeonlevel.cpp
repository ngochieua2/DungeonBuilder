#include "dungeonlevel.h"
#include <vector>

std::vector <Room> RoomStore(16);

DungeonLevel::DungeonLevel(std::string name, int width, int height): _name{name}, _width{width}, _height{height}
{
}

DungeonLevel::~DungeonLevel(){}

bool addRoom(Room){}

Room retrieveRoom(int){}


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
    return "-------";
}

//std::string[] display();
