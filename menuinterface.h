#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include <ostream>
#include <istream>
#include<game.h>

namespace core {



class MenuInterface
{
public:
    MenuInterface();
    ~MenuInterface();
    void welcome(std::ostream &output, std::istream &input, std::string title, std::string author);
    bool mainMenu(std::ostream &output, std::istream &input);
    void viewMenu(std::ostream &output, std::istream &input);
    void explorationMenu(std::ostream &output, std::istream &input);
    void run(std::ostream &output, std::istream &input);
};

}
#endif // MENUINTERFACE_H
