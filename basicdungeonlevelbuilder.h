#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H
#include <dungeonlevelbuilder.h>
#include <basicdungeonlevel.h>
#include <rockwall.h>
#include <quartzchamber.h>
#include <rockchamber.h>

class BasicDungeonLevelBuilder : public DungeonLevelBuilder
{
public:
    BasicDungeonLevelBuilder();
    ~BasicDungeonLevelBuilder();

      void buildungeonLevel(std::string name,int width, int height) override;
      std::shared_ptr<Room> buildRoom(int id) override;
      void builDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Room::Direction direction, MoveConstraints constraints) override;
      void buildEntrance(std::shared_ptr<Room> room, Room::Direction direction) override;
      void buildExit(std::shared_ptr<Room> room, Room::Direction direction) override;
      void buildItem(std::shared_ptr<Room> room)  override;
      void buildCreature(std::shared_ptr<Room> room)  override;

protected:
      RoomEdge *_edge;
      //Wall *_wall{nullptr};
      //Doorway *_door{nullptr};

};

#endif // BASICDUINGEONLEVELBUILDER_H
