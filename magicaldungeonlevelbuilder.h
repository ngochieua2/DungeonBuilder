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
    ~MagicalDungeonLevelBuilder();

    void buildungeonLevel(std::string name,int width, int height) override;
    std::shared_ptr<Room> buildRoom(int id) override;
    void builDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Room::Direction direction, MoveConstraints constraints) override;
    void buildEntrance(std::shared_ptr<Room> room, Room::Direction direction) override;
    void buildExit(std::shared_ptr<Room> room, Room::Direction direction) override;
    void buildItem(std::shared_ptr<Room> room)  override;
    void buildCreature(std::shared_ptr<Room> room)  override;

protected:
    Wall *_wall{nullptr};
    Doorway *_door{nullptr};
    Doorway *_oppositeDoor{nullptr};

};

}
#endif // MAGICALDUNGEONLEVELBUILDER_H
