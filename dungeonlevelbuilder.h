#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H
#include <string>
#include <dungeonlevel.h>
#include <random>
#include <ctime>
#include <onewaydoor.h>
#include <opendoorway.h>
#include <blockeddoorway.h>
#include <lockeddoor.h>
#include <monster.h>
#include <consumable.h>
#include <weapon.h>

namespace core::dungeon
{

class DungeonLevelBuilder
{
public:
    /*
     * Constructor DungeonLevelBuilder will create monster,
     * weapon and consumable, so BasicDungeonLevelBuilder and
     * MagicDungeonBuilder can be free to use it, set attritude
     * and clone it
     */
    DungeonLevelBuilder();

    /*
     * Destructor DungeonLevelBuilder will delete all pointers
     * include in monster, weapon, consumable and dungeonLevel
     */
    virtual ~DungeonLevelBuilder();

    enum class MoveConstraints : unsigned;

    /*
     * buildungeonLevel, buildRoom, builDoorway, buildEntrance,
     * buildExit, buildItem, buildCreature is virtual function
     * So, they will be override in BasicDungeonLevelBuilder and
     * MagicalDungeonLevelBuilder. In this class, they could be empty
     */
    virtual void buildungeonLevel(std::string name,int width, int height);
    virtual std::shared_ptr<Room> buildRoom(int id);
    virtual void builDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Room::Direction direction, DungeonLevelBuilder::MoveConstraints constraints);
    virtual void buildEntrance(std::shared_ptr<Room> room, Room::Direction direction);
    virtual void buildExit(std::shared_ptr<Room> room, Room::Direction direction);
    virtual void buildItem(std::shared_ptr<Room> room);
    virtual void buildCreature(std::shared_ptr<Room> room);

    /*
     * Function getDungeonLevel uses to get the result or
     * product after building in builder design
     */
    DungeonLevel* getDungeonLevel();

    enum class MoveConstraints : unsigned {
        None = 0,
        OriginImpassable = 1,
        DestinationImpassable = 2,
        OriginLocked = 4,
        DestinationLocked = 8,
    };

    /*
     * Function getOppositeDirection uses to return the the opposite
     * direction depending on current direction in @param direction
     */
    Room::Direction getOppositeDirection(Room::Direction direction);

    /*
     * Function randomDouble is put in DungeonLevelBuilder to
     * both BasicDungeonLevelBuilder and MagicalDungeonLevelBuider
     * could inherit and use in their class
     */
    double randomDouble();

protected:
    DungeonLevel* _Dungeonlevel;
    std::string _name;
    int _width;
    int _height;

    core::creatures::Monster *aMonster{nullptr};
    core::items::Weapon *aWeapon{nullptr};
    core::items::Consumable *aConsumable{nullptr};

    std::mt19937 _randomGenerator{uint32_t(time(nullptr))}; //!< Mersenne Twister random number generator seeded by current time
    std::uniform_real_distribution<double> _realDistribution{0.0, 6.0}; //!< For random numbers between 0.0 & 6.0
};

}

#endif // DUNGEONLEVELBUILDER_H
