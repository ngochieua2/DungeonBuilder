#ifndef ALCHEMISTSLABORATORY_H
#define ALCHEMISTSLABORATORY_H
#include <room.h>
#include <string>

namespace core::dungeon::magical
{

class AlchemistsLaboratory : public Room
{
public:

    /*!
     * Constructor AlchemistsLaboratory is used to created room with given id
     * and create default vector of room edges. There are four directions(south, east,
     * north, east), so need to assign 4 first values in vector.
     */
    AlchemistsLaboratory(int id);

    /*!
     * Destructor AlchemistsLaboratory is used to delete null pointer _roomedge
     * and delete all members of EdgesVector.
     */
    ~AlchemistsLaboratory();

    /*!
     * Function description uses to describe details of the room
     * include in 4 edges and monster and items.
     */
    std::string description() override;

};

}

#endif // ALCHEMISTSLABORATORY_H
