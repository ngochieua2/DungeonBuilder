#ifndef MONSTER_H
#define MONSTER_H
#include <abstractcreature.h>
#include <string>

class Monster : public AbstractCreature
{
public:
    Monster(std::string name);
    ~Monster();

    Monster *clone() override;
};

#endif // MONSTER_H
