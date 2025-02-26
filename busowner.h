#ifndef BUSOWENER_H
#define BUSOWENER_H
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <tuple>
#include <stdexcept>
#include "Profile.h"

using namespace std;

class Busowner : public Profile{
    
    public:
    Busowner(Profile &p)
    {
        if(
            p.update_customer_type("Busowner")
            &&
            p.update_profile_details("0BUSOWNER-STATUS",{
                {"0Buscount","0"},
                {"1Busname","place-holder"},
                {"2Busnumbers","place-holder"},
                {"3Busseats","0"},
                {"4Busstatus","inactive"}, //active or inactive
                {"5Busdriver_count","0"},
                {"6Busowner_name",p.get_name()},
                {"7Busowner_mobilenumber",p.mobilenumber()}

            })    
        )
        {
            cout << "sucessfully became a BusOwerner Profile\n";
        }
        else{
            cout << "Process Lost try again later ...";
        }
    }

};
#endif