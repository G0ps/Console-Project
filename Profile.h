#ifndef Profile_H
#define Profile_H
#include <iostream>
#include<map>
#include<vector>
#include<unordered_map>
#include <string>
using namespace std;
class Profile{
    map<string , map<string,string>> details=
    {
        {"APERSONAL",
            {{"0NAME","place-holder" },
            {"1AGE " , "place-holder" },
            {"2DOB ", "place-holder" },
        }},
        {"BCONTACT" ,
            {{"0MOBILE", "place-holder" },
            {"1EMAIL ",  "place-holder" }}
        },
        {"CBANK",
            {{"0UPI-ID        ",   "place-holder" } ,
            {"1ACCOUNT-NO    ",   "place-holder" },
            {"2ACCOUNT-BRANCH",   "place-holder" }} 
        },
        {"DVEHICLES",
            {{"iter-can_push_count_based" , "name ||| vehicle_unique_ID"}}
        }
    }
    ;
    public:
    customer(){
    }
    void print_details(){    
        for(int i=0;i<50;i++)
            {
                cout <<"==";
            }
            cout<<"\n";
            for(auto it:details)
            {
                cout << it.first.substr(1)<<":\n";
                for(auto it2 : it.second)
                {
                    cout <<"\t"<<it2.first.substr(1)<<": "<<it2.second<<"\n";
                }
            }
            cout<<"\n";
            for(int i=0;i<50;i++)
            {
                cout <<"==";
            }
            cout<<"\n";
    }    
};
#endif