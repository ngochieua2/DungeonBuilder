#include "item.h"

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
    return _name;
}

char Item::displayCharacter()
{
    return 'a';
}


