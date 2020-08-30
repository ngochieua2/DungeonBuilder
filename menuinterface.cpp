#include "menuinterface.h"
#include <ostream>

using namespace std;

MenuInterface::MenuInterface(){

}

void MenuInterface::welcome(ostream &output, istream &input, string title, string author){
    // Intro
    output << "Welcome to: " << title << endl;
    output << "Developed by " << author << endl;
    output << "COMP 3023 Software Development with C++\n" << endl;
    output << "*Press Enter to Continue*";
    input.ignore();
}

bool MenuInterface::mainMenu(ostream &output, istream &input){

    output << "What would you like to do?" << endl;
    output << " (g)enerate the example level" << endl;
    output << " (r)andom dungeon level" << endl;
    output << " (q)uit" << endl;

    char a;
    input >> a;
    switch (a) {
        case 'g':
            output << "Creating Example Dungeon Level..." << endl;
            output << "Dungeon level created!\n" << endl;
            viewMenu(output, input);
            return true;
            break;
        case 'r':
            viewMenu(output, input);
            return true;

            break;
    case 'q':
       while (true){
           output << "*Are you sure you want to quit? (y/n)*" << endl;
           input >> a;
           if (a == 'y'){
               output << "Goodbye!" << endl;
               //quit = true;
               return false;
               break;
           }
           else if (a == 'n') {
               output << "Return to menu" << endl;
               return true;
               break;
           }
           else output << "Unvalid option, please choose again!\n" << endl;
       }
       break;
    default:
        output << "Unvalid option, please choose again!\n" << endl;
        return true;
        break;

    }
}

void MenuInterface::viewMenu(ostream &output, istream &input){
    while(true){
        output << "What would you like to do?" << endl;
        output << " (d)escribe the dungeon level" << endl;
        output << " (v)iew the dungeon level" << endl;
        output << " (r)eturn to the main menu" << endl;

       char a;
        input >> a;
        if (a == 'd'){
            output << "Event for describe\n" << endl;
        }
        else if (a == 'v'){
            output << "Event for view\n" << endl;
        }
        else if (a == 'r'){
            output << "return to the main menu\n" << endl;
            break;
        }
        else output << "Unvalid option, please choose again!\n" << endl;

    }
}

void MenuInterface::explorationMenu(ostream &output, istream &input){
    while(true){
        output << "What would you like to do?" << endl;
        output << " (d)escribe a room" << endl;
        output << " (r)eturn to to previous menu" << endl;

        char a;
        input >> a;
        if (a == 'd'){
            output << "Event for describe\n" << endl;
        }
        else if (a == 'r'){
            output << "return to the main menu\n" << endl;
            break;
        }
        else output << "Unvalid option, please choose again!\n" << endl;

    }
}

void MenuInterface::run(ostream &output, istream &input){

    while (true) {
        if (!mainMenu(output, input)) break;
    }

}

