#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H
#include <memory>
#include <string>
#include <room.h>
#include <vector>

namespace core::dungeon
{

class DungeonLevel
{
public:
    DungeonLevel();
    DungeonLevel(std::string &name, int &width, int &height);
    //DungeonLevel(const DungeonLevel &other) = default;
    virtual ~DungeonLevel();

    bool addRoom(std::shared_ptr<Room> room);
    std::shared_ptr<Room> retrieveRoom(int i);

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
    std::vector<std::shared_ptr<Room>> allRoom{};

};

}

#endif // DUNGEONLEVEL_H
