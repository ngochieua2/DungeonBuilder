#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H
#include<doorway.h>
#include<string>

namespace core::dungeon::common
{

class BlockedDoorWay: public Doorway
{
public:
    BlockedDoorWay();
    ~BlockedDoorWay();

    std::string description()override;

    /*!
     * Function displayCharacter use to print correct character.
     * In this case, it will need to check the opposite doorway is onewaydoor
     * or not. if yes, it will print character of onewaydoor.
     * if no, print character of blockedDoorway.
     */
    char displayCharacter() override;

    /*!
     * BlockedDoorway will not be entrance or exit.
     */
    void setEntrance() override;

    void setExit()override;

};

}

#endif // BLOCKEDDOORWAY_H
