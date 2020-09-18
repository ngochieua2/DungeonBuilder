#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H
#include <dungeonlevelbuilder.h>
#include <basicdungeonlevel.h>
#include <rockwall.h>
#include <onewaydoor.h>

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

//    void buildItem(Room) const override;
//    void buildCreature(Room) const override;

protected:
      //RoomEdge *edge;
      Wall *_wall;
      Doorway *_door;

};

#endif // BASICDUINGEONLEVELBUILDER_H
