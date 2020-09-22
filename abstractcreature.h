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

    void setName(std::string name);

    std::string name();

    char displayCharacter();

    void setBoss();

protected:
    std::string _name{};
    bool isBoss{false};
};

#endif // ABSTRACTCREATURE_H
