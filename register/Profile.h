#ifndef PROFILE_H
#define PROFILE_H

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <tuple>
#include <stdexcept>

#include "UserCredentials.h"

using namespace std;

// A profile class to store user details and maintain profile type

class Profile {
    string data_for_DB = "";
    string user_id;
    string password;
    string customer_type = "User";

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

    string get_data_string() {
        return data_for_DB;
    }

    pair<string, Profile> create_profile(
        string name = "",
        int age = 0,
        tuple<int, int, int> DOB = make_tuple(1, 1, 1),
        string mobile = "",
        string email = "",
        string upi = "",
        string account = "",
        string password = ""
    ) {
        try {
            user_id = email;
            this->password = password;

            details["APERSONAL"]["0NAME"] = name;
            details["APERSONAL"]["1AGE"] = to_string(age);
            details["APERSONAL"]["2DOB"] = to_string(get<0>(DOB)) + "-" + to_string(get<1>(DOB)) + "-" + to_string(get<2>(DOB));

            details["BCONTACT"]["0MOBILE"] = mobile;
            details["BCONTACT"]["1EMAIL"] = email;

            details["CBANK"]["0UPI-ID"] = upi;
            details["CBANK"]["1ACCOUNT"] = account;

            // Format data for storage
            data_for_DB = name + "~" + to_string(age) + "~" + to_string(get<0>(DOB)) + "~" +
                          to_string(get<1>(DOB)) + "~" + to_string(get<2>(DOB)) + "~" + mobile + "~" +
                          email + "~" + upi + "~" + account + "~" + password + "~\n";

            return {user_id, *this};
        } catch (exception& e) {
            cerr << "Error creating profile: " << e.what() << endl;
            return {"", Profile()}; // Return empty pair on failure
        }
    }

    void print_details() { 
        cout << string(50, '=') << "\n";
        cout << "Customer Type: " << customer_type << "\n";

        for (const auto& section : details) {
            cout << section.first.substr(1) << ":\n"; 
            for (const auto& field : section.second) {
                cout << "\t" << field.first.substr(1) << ": " << field.second << "\n";
            }
            cout << "\n";
        }

        cout << string(50, '=') << "\n";
    }

    // Update customer type
    bool update_customer_type(const string& s) {
        try {
            customer_type = s;
            return true;
        } catch (exception& e) {
            cerr << "Error updating customer type: " << e.what() << endl;
            return false;
        }
    }

    bool update_profile_details(const string& key, const map<string, string>& mp) {
        try {
            details[key] = mp;
            return true;
        } catch (exception& e) {
            cerr << "Error updating profile details: " << e.what() << endl;
            return false;
        }
    }

    bool update_password(const string& old_password, const string& new_password) {
        if (old_password == password) {
            password = new_password;
            return true;
        } else {
            return false;
        }
    }

    string get_password() {
        return password;
    }
};  

#endif
