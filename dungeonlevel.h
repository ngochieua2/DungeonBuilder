#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H
#include<string>
#include<room.h>

class DungeonLevel
{
public:
    DungeonLevel();
    DungeonLevel(std::string name, int width, int height);
    //DungeonLevel(const DungeonLevel &other) = default;
    ~DungeonLevel();

    bool addRoom(Room);
    Room retrieveRoom(int);

    int width();
    int height();
    int numberOfRooms();
    std::string name();
    std::string description();
    //std::string[] display();

private:
    std::string _name;
    int _width;
    int _height;
};

#endif // DUNGEONLEVEL_H
