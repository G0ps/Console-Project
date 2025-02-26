#ifndef userRegister_H
#define userRegister_H

#include <bits/stdc++.h>

#include "UserCredentials.h"
#include "Profile.h"

using namespace std;
class userRegister:public Profile{
    int options;
    public:
    userRegister(){
            do{
            cin >> this->options;
            cout << R"(
            REGISTRATION PORTAL
            userREGISTER AS
            option 1 -> user
            option 2 -> colaburator
            option 3 -> exit

            Enter option :- 
            )";

            if(this->options == 1 || this->options == 2)
            {
                try{
                    pair<string , string> user_cred = create_profile();
                    cout << "id = "<<user_cred.first << " pass = "<<user_cred.second<<"\n";
                    break;
                }
                catch(exception &e){
                    continue;
                }
            }

        }while(this->options != 3);
    }
};
#endif