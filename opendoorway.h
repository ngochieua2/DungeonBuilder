#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H
#include<doorway.h>
#include<string>

class OpenDoorWay: public Doorway
{
public:
    OpenDoorWay();
    ~OpenDoorWay();

    std::string description()override;

    void setEntrance() override;

    void setExit() override;

    DoorwayType getDoorwayType()override;
};

#endif // OPENDOORWAY_H
