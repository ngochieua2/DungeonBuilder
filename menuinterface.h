#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include <ostream>
#include <istream>

using namespace std;

class MenuInterface
{
public:
    MenuInterface();
    void welcome(ostream &output, istream &input);
    void mainMenu(ostream &output, istream &input);
    void viewMenu(ostream &output, istream &input);
    void explorationMenu(ostream &output, istream &input);
};

#endif // MENUINTERFACE_H
