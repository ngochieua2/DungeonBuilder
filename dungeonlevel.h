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

    /*
     * Function addRoom uses to collect room into
     * the given vector allRoom.
     * Return true or false value is not used in assignment
     * @param room is the room will be pushed
     */
    bool addRoom(std::shared_ptr<Room> room);

    /*
     * Function retrieveRoom is used to get the room from vector
     * thank to index i.Because all room will be pushed by order
     * from 0 to width*height-1, real index of each room will be bigger
     * than index of wector by 1.
     * @param i is index of room want to get from vector
     */
    std::shared_ptr<Room> retrieveRoom(int i);

    int width();

    int height();

    int numberOfRooms();

    std::string name();

    virtual std::string description();

    /*
     * Function display uses to print the map of dungeon
     * It will use string vector of each room, which has been
     * created before and arrange in order to become completed
     * dungeon map
     */
    std::string display();

protected:
    std::string _name;
    int _width;
    int _height;

    std::vector<std::shared_ptr<Room>> allRoom{};
    std::string dungeonMap{};

};

}

#endif // DUNGEONLEVEL_H
