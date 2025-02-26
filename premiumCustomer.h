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

using namespace std;

class premiumCustomer : public Profile{
    
    public:
    premiumCustomer(Profile &p)
    {
        if(p.update_customer_type("premiumCustomer"))
        {
            cout << "sucessfully became a Premium Customer\n";
        }
        else{
            cout << "Process Lost try again later ...";
        }
    }
};
#endif