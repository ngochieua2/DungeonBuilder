#ifndef QUARTZCHAMBER_H
#define QUARTZCHAMBER_H
#include <room.h>
#include <string>

namespace core::dungeon::basic{

class QuartzChamber : public Room
{
public:

    /*
     * Constructor QuartzChamber is used to created room with given id
     * and create default vector of room edges, there are four directions(south, east,
     * north, east), so need to assign 4 first values in vector
     */
    QuartzChamber(int id);

    /*
     * Destructor QuartzChamber is used to delete null pointer _roomedge
     * and delete all members of EdgesVector
     */
    ~QuartzChamber();

    /*
     * Function description uses to describe details of the room
     * include in 4 edges and monster and items
     */
    std::string description() override;

};

}

#endif // QUARTZCHAMBER_H
