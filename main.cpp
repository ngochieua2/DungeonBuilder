#include <iostream>

using namespace std;

int main()
{
    // Intro
    cout << "Welcome to: So you built your first dungeon? Well then, build another!" << endl;
    cout << "\t\t\tDeveloped by Ngoc Hieu Nguyen" << endl;
    cout << "\t\tCOMP 3023 Software Development with C++\n" << endl;
    cout << "*Press Enter to Continue*";
    cin.ignore();

    //Start with some option
    bool quit{false};
    while (!quit){
        cout << "What would you like to do?" << endl;
        cout << " (g)enerate the example level" << endl;
        cout << " (r)andom dungeon level" << endl;
        cout << " (q)uit" << endl;

        //Options event
        char input;
        cin >> input;
        switch (input) {
            case 'g':{
                cout << "Creating Example Dungeon Level..." << endl;
                cout << "Dungeon level created!\n" << endl;

                while(true){
                    cout << "What would you like to do?" << endl;
                    cout << " (d)escribe the dungeon level" << endl;
                    cout << " (v)iew the dungeon level" << endl;
                    cout << " (r)eturn to the main menu" << endl;
                    cin >> input;
                    if (input == 'd'){
                        cout << "Event for describe\n" << endl;
                    }
                    else if (input == 'v'){
                        cout << "Event for view\n" << endl;
                    }
                    else if (input == 'r'){
                        cout << "return to the main menu\n" << endl;
                        break;
                    }
                    else cout << "Unvalid option, please choose again!\n" << endl;

                }
                break;
            }
            case 'r':{
                cout << "Event for random\n" << endl;
                break;
            }
            case 'q':{
               while (true){
                   cout << "*Are you sure you want to quit? (y/n)*" << endl;
                   cin >> input;
                   if (input == 'y'){
                       cout << "Goodbye!" << endl;
                       quit = true;
                       break;
                   }
                   else if (input == 'n') {
                       cout << "Return to menu" << endl;
                       break;
                   }
                   else cout << "Unvalid option, please choose again!\n" << endl;
               }
               break;
            }
            default:
                cout << "Unvalid option, please choose again!\n" << endl;
                break;
        }
    }


    return 0;
}
