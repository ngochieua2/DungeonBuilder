#ifndef ROCKCHAMBER_H
#define ROCKCHAMBER_H
#include <room.h>
#include <string>

namespace core::dungeon::basic
{

class RockChamber : public Room
{
public:
    RockChamber(int id);
    ~RockChamber();

    std::string description() override;
};

}

#endif // ROCKCHAMBER_H
