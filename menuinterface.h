#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include <ostream>
#include <istream>
#include <game.h>
#include <algorithm>

namespace core
{

class MenuInterface
{
public:

    MenuInterface();

    ~MenuInterface();

    /*!
     * Function welcome is used to print the title
     * and basic information of game
     * @param title is title of same
     * @param author is student name
     */
    void welcome(std::ostream &output, std::istream &input, std::string title, std::string author);

    /*!
     * Function mainMenu is the first menu of game, which is used to
     * access main features like example dungeon or random dungeon or exit game
     */
    bool mainMenu(std::ostream &output, std::istream &input);

    /*!
     * Function viewmenu provide more information about current dungeon like
     * view each room or view map dungeon
     */
    void viewMenu(std::ostream &output, std::istream &input);

    /*!
     * Function explorationMenu provide interface to describe any room
     * of dungeon level
     */
    void explorationMenu(std::ostream &output, std::istream &input);

    /*!
     * Function run is used to run wellcome and mainMenu of the game.
     * It will be call in main class
     */
    void run(std::ostream &output, std::istream &input);

};

}
#endif // MENUINTERFACE_H
