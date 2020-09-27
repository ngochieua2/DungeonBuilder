#ifndef WEAPON_H
#define WEAPON_H
#include <item.h>
#include <string>

namespace core::items{

class Weapon : public Item
{
public:

    Weapon();

    ~Weapon();

    /*!
     * Function clone uses to copy object of Weapon
     */
    Weapon* clone() override;

};

}

#endif // WEAPON_H
