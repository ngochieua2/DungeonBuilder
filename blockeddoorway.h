#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H
#include<doorway.h>
#include<string>


class BlockedDoorWay: public Doorway
{
public:
    BlockedDoorWay();
    ~BlockedDoorWay();

    std::string description();

    void setEntrance() override;

    void setExit()override;
};

#endif // BLOCKEDDOORWAY_H
