#ifndef booking_H
#define booking_H

#include <iostream>
#include <set>

using namespace std;
    class booking{
        public:
        booking(){
            
        }
        void run(){
            int option = 9;
            do{
                cout << R"(
                Option 1 - Enter routes
                Option 9 - exit
                )";
                cin >> option;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
            }while(option !=9 );
        }
    };

#endif