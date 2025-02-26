#ifndef USER_REGISTER_BUS_REGISTER_H
#define USER_REGISTER_BUS_REGISTER_H

#include <iostream>
#include "UserCredentials.h"
#include "Profile.h"

using namespace std;

class userRegister_busRegister {
public:
    userRegister_busRegister() {}

    userRegister_busRegister(Profile &p) {
        bool type_updated = p.update_customer_type("Collaborator");
        bool details_updated = p.update_profile_details("DBuses", map<string, string>());

        if (type_updated && details_updated) {
            cout << "Successfully became a Collaborator\n";
        } else {
            cout << "Process failed, try again later...\n";
        }
    }
};

#endif
