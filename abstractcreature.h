#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H
#include <string>

class AbstractCreature
{
public:
    AbstractCreature();
    AbstractCreature(std::string name);
    ~AbstractCreature();

    virtual AbstractCreature *clone() = 0;

    std::string name();

    char displayCharacter();

protected:
    std::string _name{};
};

#endif // ABSTRACTCREATURE_H
