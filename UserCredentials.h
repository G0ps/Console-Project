#ifndef UserCredentials_H
#define UserCredentials_H

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <tuple>
#include <stdexcept>

using namespace std;
//this is a global class for user credential acess
#include "Profile.h"

class UserCredentials{
    static map<string , Profile> Login_credentials;
    static map<string , string> premium_credentials;
    static map<string , string> owner_credentials;
    //rows and columns in db row meant for type and column will be updated 
    //type is like premium , worker , bla bla bla
    public:
    static bool check_Login_credentials(string &user_id)
    {
        return (Login_credentials.find(user_id) != Login_credentials.end());
    }
    static void update_Login_credendials(string ID , Profile pass){
        Login_credentials[ID] = pass;
    }
    static map<string , Profile> get_login_credentials_for_storing()
    {
        return Login_credentials;
    }
};

#endif
