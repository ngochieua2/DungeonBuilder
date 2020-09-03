#ifndef BASICDUINGEONLEVELBUILDER_H
#define BASICDUINGEONLEVELBUILDER_H
#include <DungeonLevelBuilder.h>

class BasicDuingeonLevelBuilder : public DungeonLevelBuilder
{
public:
    BasicDuingeonLevelBuilder();
    ~BasicDuingeonLevelBuilder();

    virtual void builđungeonLevel(std::string name,int width, int height) const override;
    virtual Room buildRoom(int id) const override;
    virtual Room builDoorway(Room origin, Room destination, Direction direction, MoveConstraints constraints) const override;
    virtual void buildEntrance(Room room, Room direction) const override;
    virtual void buildExit(Room room, Direction direction) const override;
    virtual void buildItem(Room) const override;
    virtual void buildCreature(Room) const override;
};

#endif // BASICDUINGEONLEVELBUILDER_H
