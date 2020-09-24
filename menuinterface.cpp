#include "menuinterface.h"
#include <ostream>
#include <string>

using core::MenuInterface;
using core::Game;

MenuInterface::MenuInterface(){}
MenuInterface::~MenuInterface(){};

Game* Game::theInstance= nullptr;

void MenuInterface::welcome(std::ostream &output, std::istream &input, std::string title, std::string author){
    // Intro
    output << "Welcome to: " << title << std::endl;
    output << "Developed by " << author << std::endl;
    output << "COMP 3023 Software Development with C++\n" << std::endl;
    output << "*Press Enter to Continue*";
    input.ignore();
}

bool MenuInterface::mainMenu(std::ostream &output, std::istream &input){

    output << "What would you like to do?" << std::endl;
    output << " (g)enerate the example level" << std::endl;
    output << " (r)andom dungeon level" << std::endl;
    output << " (q)uit" << std::endl;


    std::string stringInput;

    input >> stringInput;
    if ( stringInput == "g"){
        output << "Creating Example Dungeon Level..." << std::endl;
        output << "Dungeon level created!\n" << std::endl;

        Game::getInstance()->createExampleLevel();

        viewMenu(output, input);
        return true;
        //break;
    }
    else if (stringInput == "r"){
        std::string name;
        int width{0};
        int height{0};
        output << "What would you like to call the level?" << std::endl;
        input >> name;
        output << "How many rows in *"+name+"*?" << std::endl;
        input >> width;
        while (input.fail() ||width > 4 || width < 1) {
            output << "input should be a number in range 1 to 4, please enter again!" << std::endl;
            output << "How many rows in *"+name+"*?" << std::endl;
            input.clear();
            input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            input >> width;
        }
        output << "How many columns in *"+name+"*?" << std::endl;
        input >> height;
        while (input.fail() ||height > 4 || height < 1) {
            output << "input should be a number in range 1 to 4, please enter again!" << std::endl;
            output << "How many columns in *"+name+"*?" << std::endl;
            input.clear();
            input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            input >> height;
        }
        output << "What type of dungeon level is it? (b)asic or (m)agical" << std::endl;
        input >> stringInput;
        while (stringInput != "b" || stringInput != "m") {
            output << "input should be a (b) or (m)" << std::endl;
            input >> stringInput;
        }

        viewMenu(output, input);
        return true;
        //break;
    }
    else if ( stringInput == "q"){
       while (true){
           output << "*Are you sure you want to quit? (y/n)*" << std::endl;
           input >> stringInput;
           if (stringInput == "y"){
               output << "Goodbye!" << std::endl;
               //quit = true;
               return false;
               break;
           }
           else if (stringInput == "n") {
               output << "Return to menu" << std::endl;
               return true;
               break;
           }
           else output << "Unvalid option, please choose again!\n" << std::endl;
       }
       //break;
    }
    else {
        output << "Unvalid option, please choose again!\n" << std::endl;
        return true;
    }


}

void MenuInterface::viewMenu(std::ostream &output, std::istream &input){
    while(true){
        output << "What would you like to do?" << std::endl;
        output << " (d)escribe the dungeon level" << std::endl;
        output << " (v)iew the dungeon level" << std::endl;
        output << " (r)eturn to the main menu" << std::endl;

        std::string stringInput;
        input >> stringInput;
        if (stringInput == "d"){
            output << Game::getInstance()->getDungeon()->description();
            explorationMenu(output, input);
        }
        else if (stringInput == "v"){
            output << Game::getInstance()->getDungeon()->name() << std::endl;
            output << std::endl;

            //output << Game::getInstance()->getDungeon()->display() << std::endl;
            Game::getInstance()->displayLevel(output);
        }
        else if (stringInput == "r"){
            output << "return to the main menu\n" << std::endl;
            break;
        }
        else output << "Unvalid option, please choose again!\n" << std::endl;
    }
}

void MenuInterface::explorationMenu(std::ostream &output, std::istream &input){
    while(true){
        output << "What would you like to do?" << std::endl;
        output << " (d)escribe a room" << std::endl;
        output << " (r)eturn to to previous menu" << std::endl;

        std::string stringInput;
        input >> stringInput;
        if (stringInput == "d"){
            int number{};
            output << "Which room would you like to describe? (1-" <<
                      Game::getInstance()->getDungeon()->numberOfRooms() << ")" << std::endl;
            input >> number;
            while (input.fail() ||number > Game::getInstance()->getDungeon()->numberOfRooms() || number < 1) {
                output << "input should be a number in range 1 to " << Game::getInstance()->getDungeon()->numberOfRooms() << std::endl;
                input.clear();
                input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                input >> number;
            }

            output << "Room *" << number << "* is..." << std::endl;
            output << Game::getInstance()->getDungeon()->retrieveRoom(number)->description();
        }
        else if (stringInput == "r"){
            output << "return to the main menu\n" << std::endl;
            break;
        }
        else output << "Unvalid option, please choose again!\n" << std::endl;

    }
}

void MenuInterface::run(std::ostream &output, std::istream &input){

    //mainMenu(output, input);
    while (true) {
        if (!mainMenu(output, input)) break;
    }

}

