#include <iostream>
#include "menuinterface.h"

using namespace std;

int main()
{

    MenuInterface menu;
    menu.welcome(cout, cin);
    menu.mainMenu(cout, cin);

    return 0;
}
