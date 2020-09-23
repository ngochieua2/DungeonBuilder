#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H
#include<doorway.h>
#include<string>

namespace core::dungeon::common
{

class OpenDoorWay: public Doorway
{
public:
    OpenDoorWay();
    ~OpenDoorWay();

    std::string description()override;

    void setEntrance() override;

    void setExit() override;

};

}

#endif // OPENDOORWAY_H
