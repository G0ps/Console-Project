#ifndef premiumCustomer_H
#define premiumCustomer_H

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

class premiumCustomer{
    
    public:
    premiumCustomer()
    {}
    premiumCustomer(Profile &p)
    {
        if(
            p.update_customer_type("premiumCustomer")
            &&
            p.update_profile_details("DPREMIUM-ATTRIBUTES",{
                {"0points","0"},
                {"1medal","bronze"},
            })    
        )
        {
            cout << "sucessfully became a Premium Customer\n";
        }
        else{
            cout << "Process Lost try again later ...";
        }
    }
};
#endif