#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H
#include <dungeonlevelbuilder.h>
#include <basicdungeonlevel.h>
#include<wall.h>

class BasicDungeonLevelBuilder : public DungeonLevelBuilder
{
public:
    BasicDungeonLevelBuilder();
    ~BasicDungeonLevelBuilder();

      void buildungeonLevel(std::string name,int width, int height) override;
      Room buildRoom(int id) override;
      Room builDoorway(Room origin, Room destination, Room::Direction direction, MoveConstraints constraints) override;
      void buildEntrance(Room room, Room::Direction direction) override;
      void buildExit(Room room, Room::Direction direction) override;

//    void buildItem(Room) const override;
//    void buildCreature(Room) const override;


};

#endif // BASICDUINGEONLEVELBUILDER_H
