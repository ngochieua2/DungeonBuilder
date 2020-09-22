#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H
#include<string>
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
    DungeonLevelBuilder();
    virtual ~DungeonLevelBuilder(); // May need virtual = 0

    enum class MoveConstraints : unsigned;

    virtual void buildungeonLevel(std::string name,int width, int height);
    virtual std::shared_ptr<Room> buildRoom(int id);
    virtual void builDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Room::Direction direction, DungeonLevelBuilder::MoveConstraints constraints);
    virtual void buildEntrance(std::shared_ptr<Room> room, Room::Direction direction);
    virtual void buildExit(std::shared_ptr<Room> room, Room::Direction direction);
    virtual void buildItem(std::shared_ptr<Room> room);
    virtual void buildCreature(std::shared_ptr<Room> room);

    DungeonLevel* getDungeonLevel();

    enum class MoveConstraints : unsigned {
        None = 0,
        OriginImpassable = 1,
        DestinationImpassable = 2,
        OriginLocked = 4,
        DestinationLocked = 8,
    };

    Room::Direction getOppositeDirection(Room::Direction direction);

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
    std::uniform_real_distribution<double> _realDistribution{0.0, 4.0}; //!< For random numbers between 0.0 & 3.0
};

}

#endif // DUNGEONLEVELBUILDER_H
