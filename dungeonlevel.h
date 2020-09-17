#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H
#include<memory>
#include<string>
#include<room.h>
#include<vector>

class DungeonLevel
{
public:
    DungeonLevel() = default;
    DungeonLevel(std::string &name, int &width, int &height);
    //DungeonLevel(const DungeonLevel &other) = default;
    virtual ~DungeonLevel();

    bool addRoom(Room *room);
    Room retrieveRoom(int i);

    int width();
    int height();
    int numberOfRooms();
    std::string name();

    virtual std::string description();

    //std::string[] display();

protected:
    std::string _name;
    int _width;
    int _height;
    std::shared_ptr <Room> ptrRoom{};
    std::vector <Room*> allRoom;
};

#endif // DUNGEONLEVEL_H
