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

class UserCredentials{
    static unordered_map<string , string> Login_credentials;
    //rows and columns in db row meant for type and column will be updated 
    //type is like premium , worker , bla bla bla
};
#endif
