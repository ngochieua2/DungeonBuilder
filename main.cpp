#include <iostream>
#include "menuinterface.h"
#include<game.h>

using namespace std;

using core::MenuInterface;

/*!
 * @mainpage
 * This game allows to generate random map with specific name, width, height
 * and type. all doorways, entrance, exit,creatures and items can appear randomly
 */

int main()
{
    core::MenuInterface menu;
    menu.welcome(cout, cin,"app game","hieu");
    menu.run(cout, cin);

    return 0;
}
