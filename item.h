#ifndef ITEM_H
#define ITEM_H
#include <string>

namespace core::items{

class Item
{
public:
    Item();
    Item(std::string name);
    ~Item();

    virtual Item* clone() = 0;

    void setName(std::string name);

    std::string name();

    char displayCharacter();

protected:
    std::string _name{};

};

}

#endif // ITEM_H
