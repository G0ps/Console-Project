#ifndef PREMIUMCUSTOMER_H
#define PREMIUMCUSTOMER_H

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <tuple>
#include <stdexcept>

#include "Profile.h"
#include "UserCredentials.h"

using namespace std;

class premiumCustomer {
public:
    premiumCustomer() {}

    premiumCustomer(Profile &p) {
        bool typeUpdated = p.update_customer_type("premiumCustomer");
        bool attributesUpdated = p.update_profile_details("DPREMIUM-ATTRIBUTES", {
            {"0points", "0"},
            {"1medal", "bronze"},
        });
        UserCredentials::update_Login_credendials(p.get_user_id() , p);
        if (typeUpdated && attributesUpdated) {
            cout << "Successfully became a Premium Customer\n";
        } else {
            cerr << "Process failed. Please try again later.\n";
            if (!typeUpdated) {
                cerr << "Error: Failed to update customer type.\n";
            }
            if (!attributesUpdated) {
                cerr << "Error: Failed to update premium attributes.\n";
            }
        }
    }
};

#endif
