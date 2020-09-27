#ifndef ROOMEDGE_H
#define ROOMEDGE_H
#include<string>
#include<vector>

namespace core::dungeon
{

class Room;

class RoomEdge
{
public:

    RoomEdge();

    virtual ~RoomEdge();

    virtual std::string description();

    /*!
     * Function setChar uses to access value of data member character.
     * Depending direction and object roomedge type, it will be have
     * different character.
     * @param char is value to set.
     */
    void setChar(char sChar);

    virtual char displayCharacter();

    /*!
     * Function is Passage is used to check what roomedge type.
     * Because it is virtual function, it will be overrided in
     * other class like wall or doorway.
     */
    virtual bool isPassage();

    virtual bool isEntrance();

    virtual bool isExit();

    virtual void setEntrance();

    virtual void setExit();

protected:
    bool Entrance{false};
    bool Exit{false};
    char character{};
};

}

#endif // ROOMEDGE_H
