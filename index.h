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
map<string, string> UserCredentials::Login_credentials;

class index {
    int option;
    public:
    index(){
        do{
        cout << R"(
        
        TRAVELLER APPLICATION : 

        option 1    login
        option 2    register
        option 3    exit
        Enter the option number to trigger the process
        for example (enter 3) to process exit operation
    
        )";
        cout << "Enter option : ";
        cin >> this->option;
        cout << "\n";
        if(this->option == 2)
        {
            userRegister u;
        }
    }
        while(this->option != 3);
        // cout << Login_credentials.empty()<<"\n";
    }

};

#endif