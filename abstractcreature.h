#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H
#include <string>

namespace core::creatures
{

class AbstractCreature
{
public:

    AbstractCreature();

    /*!
     * Constructor is used to get name of monster when create new monster object.
     * However, in this assignment, it will not be used because it will required
     * declare many same objects with different name and then clone it. So that,
     * to achieve prototype design, I decide to avoid calling as many similar objects
     * as possible.
     * @param name is variable to get name of monster directly and store it into
     * data member _name
     */
    AbstractCreature(std::string name);

    /*!
     * Destructor of AbstractCreature
     * There is no pointer in class to delete
     * Just need to set boss variable to default - false
     */
    virtual ~AbstractCreature();

    virtual AbstractCreature *clone() = 0;

    /*!
     * setName function is used to change name of objects before clone it.
     * It is also used to create the differences of name to distinguish monster types.
     * @param name is variable to get name from outside to this class
     */
    void setName(std::string name);

    /*!
     * Function name uses to print description of the monster.
     * Including normal and boss monster.
     */
    std::string name();

    /*!
     * Function displayCharacter uses to print symbol
     * of the monster when display all room.
     */
    char displayCharacter();

    /*!
     * Function setBoss is use to change attitude of monster.
     * It can make monster become boss or be normal.
     */
    void setBoss(bool value);

protected:
    std::string _name{};
    bool Boss{false};
};

}

#endif // ABSTRACTCREATURE_H
