#include "consumable.h"

Consumable::Consumable()
{}

Consumable::~Consumable()
{}

Consumable *Consumable::clone()
{
    return new Consumable(*this);
}
