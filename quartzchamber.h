#ifndef QUARTZCHAMBER_H
#define QUARTZCHAMBER_H
#include <room.h>
#include <string>

class QuartzChamber : public Room
{
public:
    QuartzChamber(int id);
    ~QuartzChamber();

    std::string description() override;

};

#endif // QUARTZCHAMBER_H
