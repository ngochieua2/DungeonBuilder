#ifndef WEAPON_H
#define WEAPON_H
#include <item.h>
#include <string>

class Weapon : public Item
{
public:
    Weapon(std::string name);
    ~Weapon();

    Weapon* clone() override;

};

#endif // WEAPON_H
