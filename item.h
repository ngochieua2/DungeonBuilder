#ifndef ITEM_H
#define ITEM_H
#include <string>

namespace core::items{

class Item
{
public:

    Item();

    /*
     * Constructor is used to get name of monster when create new monster object
     * @param name is variable to get name of monster directly and store it into
     * data member _name
     * However, in this assignment, it will not be used because it will required
     * declare many same objects with different name and then clone it. So that,
     * to achieve prototype design, I decide to avoid calling as many similar objects
     * as possible.
     */
    Item(std::string name);

    virtual ~Item();

    virtual Item* clone() = 0;

    /*
     * setName function is used to change name of objects before clone it
     * It is also used to create the differences of name to distinguish item types
     * @param name is variable to get name from outside to this class
     */
    void setName(std::string name);

    /*
     * Function name uses to print description of the item
     */
    std::string name();

    /*
     * Function displayCharacter uses to print symbol
     * of the item when display all room
     */
    char displayCharacter();

protected:
    std::string _name{};

};

}

#endif // ITEM_H
