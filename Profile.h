#ifndef PROFILE_H
#define PROFILE_H

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <tuple>
#include <stdexcept>

using namespace std;

//this is a basic probile outlet , a class need to be uniting this and a complete profile class so that the profile will have a type

static long long id = 1;
class Profile {
    
    string user_id;
    string password;
    string customer_type = "place-holder";
    map<string, map<string, string>> details = {
        {"APERSONAL", {
            {"0NAME", "place-holder"},
            {"1AGE", "place-holder"},
            {"2DOB", "place-holder"}
        }},
        {"BCONTACT", {
            {"0MOBILE", "place-holder"},
            {"1EMAIL", "place-holder"}
        }},
        {"CBANK", {
            {"0UPI-ID", "place-holder"},
            {"1ACCOUNT", "place-holder"}
        }},
        
    };
    public:
    Profile() {}

    pair<string,string> create_profile(
        string name,
        int age,
        tuple<int, int, int> DOB,
        string mobile,
        string email,
        string upi,
        string account,
        string password
    ) {
        try{

            string id1 = name+to_string(id ++);
            this->user_id = id1;
            this->password = password;
            this->details["APERSONAL"]["0NAME"] = name;
            this->details["APERSONAL"]["1AGE"] = to_string(age);
            this->details["APERSONAL"]["2DOB"] = to_string(get<0>(DOB)) + "-" + to_string(get<1>(DOB)) + "-" + to_string(get<2>(DOB));
            this->details["BCONTACT"]["0MOBILE"] = mobile;
            this->details["BCONTACT"]["1EMAIL"] = email;
            this->details["CBANK"]["0UPI-ID"] = upi;
            this->details["CBANK"]["1ACCOUNT"] = account;  
            return {id1 , password};
        }
        catch(exception e)
        {
            return {};
        }  
    }

    //print the details of the user
    //getting  the details of the Name 
    string get_name() {
        return details["APERSONAL"]["0NAME"];
    }
    //getting the details of the mobile number;
    string mobilenumber() {
        return details["BCONTACT"]["0MOBILE"];
    }
    void print_details() { 
           
        for (int i = 0; i < 50; i++) {
            cout << "==";
        }
        cout << "\n";
        cout << customer_type<<"\n";
        for (auto it : details) {
            cout << it.first.substr(1) << ":\n"; 

            for (auto it2 : it.second) {
                cout << "\t" << it2.first.substr(1) << ": " << it2.second << "\n";
            }
            cout << "\n";
        }

        
        for (int i = 0; i < 50; i++) {
            cout << "==";
        }
        cout << "\n";
    }

    //update status of user
    bool update_customer_type(string s)
    {
        try{
            this->customer_type = s;
            return true;
        }
        catch(exception e)
        {
            return false;
        }
    }
    bool update_profile_details(string key , map<string,string> mp)
    {
        try{
            this -> details[key] = mp;
            return true;
        }
        catch(exception &e)
        {
            return false;
        }
    }
};  

#endif
