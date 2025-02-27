#ifndef APPLICATION_INTERFACE_H
#define APPLICATION_INTERFACE_H

#include <iostream>
#include <limits>

using namespace std;

class application_interface {
public:
    application_interface() {}

    void run() {  
        int option = 9;
        do {
            print_options();
            cout << "Enter your choice: ";
            if (!(cin >> option)) { 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number." << endl;
                continue;
            }
            perform_option(option);
        } while (option != 9);
    }

    virtual void print_options() = 0;
    virtual void perform_option(int option) = 0;
};

#endif
