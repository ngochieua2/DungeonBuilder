#ifndef ENCHANTEDLIBRARY_H
#define ENCHANTEDLIBRARY_H
#include <room.h>
#include <string>

namespace  core::dungeon::magical
{

class EnchantedLibrary : public Room
{
public:

    /*!
     * Constructor EnchantedLibrary is used to created room with given id
     * and create default vector of room edges, there are four directions(south, east,
     * north, east), so need to assign 4 first values in vector
     */
    EnchantedLibrary(int id);

    /*!
     * Destructor EnchantedLibrary is used to delete null pointer _roomedge
     * and delete all members of EdgesVector
     */
    ~EnchantedLibrary();

    /*!
     * Function description uses to describe details of the room
     * include in 4 edges and monster and items
     */
    std::string description() override;

};

}

#endif // ENCHANTEDLIBRARY_H
