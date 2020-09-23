#include "abstractcreature.h"

using core::creatures::AbstractCreature;

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
    if (isBoss){
        return "There is an Elite " + _name + " to fight.\n";
    }
    else {
        return "There is a " + _name + " to fight.\n";
    }
}

char AbstractCreature::displayCharacter()
{
    return 'M';
}

void AbstractCreature::setBoss()
{
    isBoss = true;
}
