#include "dungeonlevel.h"

using core::dungeon::Room;
using core::dungeon::DungeonLevel;

DungeonLevel::DungeonLevel()
{
}

DungeonLevel::DungeonLevel(std::string &name, int &width, int &height)
    : _name{name}, _width{width}, _height{height}
{
}

DungeonLevel::~DungeonLevel()
{
}

/*
 * Function addRoom uses to collect room in to
 * the given vector allRoom.
 * Return value is not used in assignment
 * @param room is the room will be pushed
 */
bool DungeonLevel::addRoom(std::shared_ptr<Room> room){

    allRoom.push_back(room);
    return true;
}

/*
 * Function retrieveRoom is used to get the room from vector
 * thank to index i.Because all room will be pushed by order
 * from 0 to width*height-1, real index of each room will be bigger
 * than index of wector by 1.
 * @param i is index of room want to get from vector
 */
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

/*
 * Function display uses to print the map of dungeon
 * It will use string vector of each room, which has been
 * created before and arrange in order to become completed
 * dungeon map
 */

std::string DungeonLevel::display()
{
    dungeonMap = "";
    for(int i = 0; i < numberOfRooms(); i = i + width()) // arrange rooms by rows
    {
        for(int j = 0; j < 6; ++j) // in a room row, arrange each string vector value by rows
        {
           for(int k = 1; k <= width(); ++k) // add space or connect between 2 rooms
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



