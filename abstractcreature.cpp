#include "abstractcreature.h"

AbstractCreature::AbstractCreature()
{}

AbstractCreature::AbstractCreature(std::string name): _name{name}
{}

AbstractCreature::~AbstractCreature()
{}

void AbstractCreature::setName(std::string name)
{
    _name = name;
}

std::string AbstractCreature::name()
{
    return _name;
}

char AbstractCreature::displayCharacter()
{
    return 'b';
}
