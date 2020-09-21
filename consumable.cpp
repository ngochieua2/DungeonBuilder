#include "consumable.h"

Consumable::Consumable(std::string name)
{}

Consumable::~Consumable()
{}

Consumable *Consumable::clone()
{
    return new Consumable(*this);
}
