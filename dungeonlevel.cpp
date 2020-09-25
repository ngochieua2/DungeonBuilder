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

std::string DungeonLevel::display()
{
    dungeonMap = "";
    for(int i = 0; i < numberOfRooms(); i = i + width())
    {
        for(int j = 0; j < 6; ++j)
        {
           for(int k = 1; k <= width(); ++k)
           {
               if(j == 2) // check connection in the east
               {
                    if(retrieveRoom(k+i)->edgeAt(Room::Direction::East)->isPassage()){
                        dungeonMap += retrieveRoom(k+i)->display().at(j);
                        dungeonMap += "--";
                    }
                    else {
                        dungeonMap += retrieveRoom(k+i)->display().at(j);
                        dungeonMap += "  ";
                    }
               }
               else if (j == 5) // check connection in the south
               {
                   dungeonMap += "     "; // 5 chars
                   if(retrieveRoom(k+i)->edgeAt(Room::Direction::South)->isPassage()){
                       dungeonMap += "|";
                   }
                   else {
                       dungeonMap += " "; // 1 char
                   }
                   dungeonMap += "       "; // 7 chars
               }
               else {
                   dungeonMap += retrieveRoom(k+i)->display().at(j);
                   dungeonMap += "  ";
               }

           }
           dungeonMap += "\n";
        }
    }

    return dungeonMap;
}



