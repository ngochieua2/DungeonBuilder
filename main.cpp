#include <iostream>
#include "menuinterface.h"

using namespace std;

int main()
{

    MenuInterface menu;
    menu.welcome(cout, cin,"app game","hieu");
    menu.run(cout, cin);

    return 0;
}
