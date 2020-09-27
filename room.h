#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <vector>
#include <roomedge.h>
#include <monster.h>
#include <weapon.h>
#include <consumable.h>

namespace core::dungeon
{

class Room
{
public:
    Room();

    /*
     * Constructor Room is used to created a room with given id
     * and create default vector of room edges, there are four directions(south, east,
     * north, east), so need to assign 4 first values in vector.
     * However, it will not be used anymore because when create new roomm, it will
     * use some class roomtypes like RockChamber or quartzChamber.
     */
    Room(int id);

    /*
     * Destructor Room is used to delete null pointer _roomedge
     * and delete all members of EdgesVector
     */
    ~Room();

    /*
     * Function description will be overrided into other class roomtype
     * so, this virtual function maybe empty
     */
    virtual std::string description();

    int id();

    core::items::Item* item();

    void setItem(core::items::Item* newItem);

    core::creatures::AbstractCreature* creature();

    void setCreature(core::creatures::AbstractCreature* newCreature);


    enum class Direction : unsigned {
        North, South, East, West
    };

    /*
     * Function setEdge uses to set objects into vector roomedge
     * Each direction will have specific index in that vector
     * namely, North is 0, East is 1, South is 2 and West is 3
     * @param edge is value will be store in vector
     * @param direction is used as index to store in vector
     */
    void setEdge(RoomEdge *edge, Direction direction);

    /*
     * Function edgeAt will return value in vector roomedge
     * depending on index as direction.
     * @param direction is used as index to access into vectors
     */
    RoomEdge* edgeAt(Direction direction);

    std::string edgeDescription(Direction direction);

    /*
     * Function creatureDescription uses to check data member creature
     * before return it. If creature is nullptr, function will returen
     * different message
     */
    std::string creatureDescription();

    /*
     * Function itemDescription uses to check data member item
     * before return it. If item is nullptr, function will returen
     * different message
     */
    std::string itemDescription();

    /*
     * Function display uses to collect all necassary characters
     * and create a string to store them. Each string will be a row,
     * then pushing them into a string vector
     */
    std::vector<std::string> display();

    /*
     * Function doorwayCount uses to count the number of door in
     * this room and return it value. It will exclude entrance and exit
     */
    int doorwayCount();

    /*
     * Function hasEntrance uses to check this room have
     * entrance (true) or not(false)
     */
    bool hasEntrance();

    /*
     * Function hasExit uses to check this room have
     * exit (true) or not(false)
     */
    bool hasExit();

protected:
    int _id{};

    RoomEdge *_roomEdge{nullptr};

    std::vector <std::string> roomMap{};

    std::vector <RoomEdge*> EdgesVector{nullptr};

    core::creatures::AbstractCreature *_abstractCreature{nullptr};
    core::items::Item *_item{nullptr};

    int doorwayNumber{0};

};

}

#endif // ROOM_H
