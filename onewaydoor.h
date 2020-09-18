#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H
#include<doorway.h>
#include<string>

class OneWayDoor: public Doorway
{
public:
    OneWayDoor();
    ~OneWayDoor();

    void setEntrance() override;

    void setExit() override;

    std::string description();
};

#endif // ONEWAYDOOR_H
