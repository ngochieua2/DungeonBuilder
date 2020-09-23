#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H
#include<doorway.h>
#include<string>

namespace core::dungeon::common
{

class OneWayDoor: public Doorway
{
public:
    OneWayDoor();
    ~OneWayDoor();

    std::string description()override;

    void setEntrance() override;

    void setExit() override;

};

}

#endif // ONEWAYDOOR_H
