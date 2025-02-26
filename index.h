#ifndef index_H
#define index_H

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <tuple>
#include <stdexcept>

#include "UserCredentials.h"
#include "userRegister.h"

using namespace std;

class index:public userRegister{
    int option = 3;
    public:
    index(){
        do{
        cout << R"(
        
        WELCOME TO THE TRAVELLER APPLICATION : 

        option 1    login
        option 2    register
        option 3    exit
        Enter the option number to trigger the process
        for example (enter 3) to process exit operation
    
        )";
        cout << "Enter option : ";
        cin >> this->option;
        cout << "\n";
        // if(this->option == 2)
        //     {
        //         try{
        //                 userRegister();
        //                 cout << "sucessfully created profile\n";
        //                 break;
        //             }
        //             catch(exception &e)
        //             {
        //                 cout << "creation failed for some reason\n";
        //                 continue;
        //             }
        //     }
    }while(this->option != 3);
        // cout << Login_credentials.empty()<<"\n";
    }

};

#endif