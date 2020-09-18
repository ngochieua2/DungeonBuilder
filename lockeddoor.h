#ifndef LOCKEDDOOR_H
#define LOCKEDDOOR_H
#include <doorway.h>
#include <string>

class LockedDoor: public Doorway
{
public:
    LockedDoor();
    ~LockedDoor();
     std::string description();

     void setEntrance()override;

     void setExit() override;
};

#endif // LOCKEDDOOR_H