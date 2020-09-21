#include "item.h"

Item::Item()
{}

Item::Item(std::string name) : _name{name}
{}

Item::~Item()
{}

std::string Item::name()
{
    return _name;
}

char Item::displayCharacter()
{
    return 'a';
}


