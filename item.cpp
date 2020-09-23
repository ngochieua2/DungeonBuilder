#include "item.h"

using core::items::Item;

Item::Item()
{}

Item::Item(std::string name) : _name{name}
{}

Item::~Item()
{}

void Item::setName(std::string name)
{
    _name = name;
}

std::string Item::name()
{
     return "There is a " + _name + " to pick up.\n";
}

char Item::displayCharacter()
{
    return 'L';
}


