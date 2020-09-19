#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H
#include<doorway.h>
#include<string>

class OneWayDoor: public Doorway
{
public:
    OneWayDoor();
    ~OneWayDoor();

    std::string description()override;

    void setEntrance() override;

    void setExit() override;

    DoorwayType getDoorwayType()override;
};

#endif // ONEWAYDOOR_H
