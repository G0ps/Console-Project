#ifndef UserCredentials_H
#define UserCredentials_H

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <tuple>
#include <stdexcept>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
//this is a global class for user credential acess
#include "Profile.h"

class UserCredentials{
    static map<string , Profile> Login_credentials;
    
    //rows and columns in db row meant for type and column will be updated 
    //type is like premium , worker , bla bla bla
    public:
    static map<string , vector<pair<string,int>>> bus_credentials;
    static bool check_Login_credentials(string &user_id)
    {
        return (Login_credentials.find(user_id) != Login_credentials.end());
    }
    static Profile get_data_for_process(string id)
    {
        return Login_credentials[id];
    }
    static pair<bool,Profile> can_login(string user_id)
    {
        auto it = Login_credentials.find(user_id);
        if(it == Login_credentials.end())
        {
            return {false , {}};
        }
        else{
            return{true , it->second};
        }
        return {false , {}};
    }
    static void update_Login_credendials(string ID , Profile pass){
        Login_credentials[ID] = pass;
    }


    //used in application
    static map<string , Profile> get_login_credentials_for_storing()
    {
        return Login_credentials;
    }
    static map<string , Profile>* get_login_credentials_for_storing(int n)
    {
        return &Login_credentials;
    }
};

#endif
