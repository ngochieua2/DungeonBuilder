#ifndef MAGICALDUNGEONLEVELBUILDER_H
#define MAGICALDUNGEONLEVELBUILDER_H
#include <dungeonlevelbuilder.h>
#include <magicaldungeonlevel.h>
#include <magicwall.h>
#include <enchantedlibrary.h>
#include <alchemistslaboratory.h>

namespace core::dungeon::magical
{

class MagicalDungeonLevelBuilder : public DungeonLevelBuilder
{
public:

    MagicalDungeonLevelBuilder();

    /*!
     * Destructor BasicDungeonLevelBuilder is used to
     * to delete some used pointer in this class like
     * Wall, Doorway...
     */
    ~MagicalDungeonLevelBuilder();

    /*!
     * Function buildungeonLevel uses to create s new MagicalDungeonLevel
     * Parameter will transfer into new object
     * @param name, width, height are name of dungeon, number of columns and
     * number of rows, respectively
     */
    void buildungeonLevel(std::string name,int width, int height) override;

    /*!
     * Function buildRoom is used to build a room with specific id
     * This room can be enchantedlibrary(50%) or alchemistslaboratory(50%)
     * When create new room, wall object will be add into 4 edges of
     * room before build doorway, entrance or exit
     * @param id is id of room required to create
     */
    std::shared_ptr<Room> buildRoom(int id) override;

    /*!
     * Function builDoorway is used to create specific doorway from one room
     * to other room. In this function, 2 new doorway object will be created,
     * make connection and add to the edge of origin room and destination depending
     * on its direction
     * @param origin is the room need to build doorway
     * @param destination is the room doorway will go to
     * @param direction is the direction of origin having doorway
     * @param constraints is used to recognize what type of doorway will build
     */
    void builDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Room::Direction direction, MoveConstraints constraints) override;

    /*!
     * Function buildEntrance is used to create a entrance in anyroom.
     * A onewaydoor object will be required to create, then change it become
     * a entrance instead of onewaydoor and add it to the room depending
     * on direction.
     * @param room is the room will have Entrance at @param direction
     */
    void buildEntrance(std::shared_ptr<Room> room, Room::Direction direction) override;

    /*!
     * Function buildExit is used to create a exit in anyroom.
     * A onewaydoor object will be required to create, then change it become
     * a exit instead of onewaydoor and add it to the room depending
     * on direction.
     * @param room is the room will have buildExit at @param direction
     */
    void buildExit(std::shared_ptr<Room> room, Room::Direction direction) override;

    /*!
     * Function buildItem uses to create item randomly in a room
     * There is 65% chance that the Item is a Consumable and a 35% chance that it is a Weapon.
     * Random number range is 0.0 to 6.0
     * So, when random number < 6*35% = 2.1, weapon will appear in this room
     * And the remaining random number will respond consumable
     * Only a weapon or a consumable can appear in a room
     * Object will be set name to recognize types and be added the clone
     * if it into room
     * @param room is the room will have Item
     */
    void buildItem(std::shared_ptr<Room> room)  override;

    /*!
     * Function buildCreature uses to create monster randomly in a room
     * Only one monster can appear in a room
     * The room have monster and exit will contain boss
     * After set monster become boss, clone and add it to room, it need
     * to convert to normal to make sure next clone of object will
     * be a normal monster in other room
     * There is 1/3 chance to appear a type of monster
     * @param room is the room will have monster
     */
    void buildCreature(std::shared_ptr<Room> room)  override;

private:
    Wall *_wall{nullptr};
    Doorway *_door{nullptr};
    Doorway *_oppositeDoor{nullptr};

};

}
#endif // MAGICALDUNGEONLEVELBUILDER_H
