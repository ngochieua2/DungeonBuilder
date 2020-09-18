#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H
#include<doorway.h>
#include<string>

class OpenDoorWay: public Doorway
{
public:
    OpenDoorWay();
    ~OpenDoorWay();

    std::string description();

    void setEntrance() override;

    void setExit() override;
};

#endif // OPENDOORWAY_H
