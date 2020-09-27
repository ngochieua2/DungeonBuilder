#include <iostream>
#include "menuinterface.h"
#include<game.h>

using namespace std;

using core::MenuInterface;

/*
 * @mainpage
 */

int main()
{
    core::MenuInterface menu;
    menu.welcome(cout, cin,"app game","hieu");
    menu.run(cout, cin);

    return 0;
}
