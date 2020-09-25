#include "abstractcreature.h"

using core::creatures::AbstractCreature;

/*
 * Constructor default of class AbstractCreature
 */
AbstractCreature::AbstractCreature()
{
}

/*
 * Constructor is used to get name of monster when create new monster object
 * @param name is variable to get name of monster directly and store it into
 * data member _name
 * However, in this assignment, it will not be used because it will required
 * declare many same objects with different name and then clone it. So that,
 * to achieve prototype design, we should avoid to call as many similar objects
 * as possible.
 */
AbstractCreature::AbstractCreature(std::string name): _name{name}
{
}

/*
 * Destructor of AbstractCreature
 * There is no pointer in class to delete
 * Just need to set boss variable to default - false
 */
AbstractCreature::~AbstractCreature()
{
    Boss = false;
}

/*
 * setName function is used to change name of objects before clone it
 * It is also used to create the differences of name.
 * @param name is variable to get name from outside to this class
 */
void AbstractCreature::setName(std::string name)
{
    _name = name;
}

/*
 * Function name uses to print description of the monster
 * Including normal and boss monster.
 */
std::string AbstractCreature::name()
{
    if (isBoss()){
        return "There is an Elite " + _name + " to fight.\n";
    }
    else {
        return "There is a " + _name + " to fight.\n";
    }
}

/*
 * Function displayCharacter uses to print symbol
 * of the monster when display all room
 */
char AbstractCreature::displayCharacter()
{
    return 'M';
}

/*
 * Function setBoss is use to change attitude of monster
 * it can make monster become boss or be normal
 */

void AbstractCreature::setBoss(bool value)
{
    Boss = value;
}

/*
 * Function isBoss uses to check the monster is boss or not
 * It will be used when display * symbol in dungeon map
 */
bool AbstractCreature::isBoss()
{
    return Boss;
}
