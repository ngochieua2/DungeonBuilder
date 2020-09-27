#ifndef ROCKCHAMBER_H
#define ROCKCHAMBER_H
#include <room.h>
#include <string>

namespace core::dungeon::basic
{

class RockChamber : public Room
{
public:

    /*!
     * Constructor RockChamber is used to created room with given id
     * and create default vector of room edges, there are four directions(south, east,
     * north, east), so need to assign 4 first values in vector.
     */
    RockChamber(int id);

    /*!
     * Destructor RockChamber is used to delete null pointer _roomedge
     * and delete all members of EdgesVector.
     */
    ~RockChamber();

    /*!
     * Function description uses to describe details of the room
     * include in 4 edges and monster and items.
     */
    std::string description() override;
};

}

#endif // ROCKCHAMBER_H
