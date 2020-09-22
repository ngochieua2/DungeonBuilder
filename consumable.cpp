#include "consumable.h"

Consumable::Consumable(std::string name)
{
    _name = name;
}

Consumable::~Consumable()
{}

Consumable *Consumable::clone()
{
    return new Consumable(*this);
}
