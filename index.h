#ifndef index_H
#define index_H

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <tuple>
#include <stdexcept>
#include <fstream>

#include "UserCredentials.h"
#include "userRegister.h"
#include "Profile.h"

using namespace std;

map<string, Profile> UserCredentials::Login_credentials;
map<string, string> UserCredentials::premium_credentials;
map<string, string> UserCredentials::owner_credentials;

class index {
    int option;
public:
    index() {
        // File processing (Reading from DB.txt)
        ifstream infile("DB.txt");
        if (!infile) {
            cerr << "Error opening file for reading!\n";
        } else {
            string line;
            while (getline(infile, line)) {
                if (line.empty()) {
                    break;
                }

                Profile p;
                string name, mobile, email, upi, account, password;
                int age = 0;
                tuple<int, int, int> DOB = make_tuple(1, 1, 1);

                int ind = 0;
                int size = line.size();

                for (int i = 1; i <= 10; i++) {
                    string data;
                    while (ind < size && line[ind] != '~') {
                        data += line[ind++];
                    }
                    ind++; // Move past '~'

                    switch (i) {
                        case 1: name = data; break;
                        case 2: age = stoi(data); break;
                        case 3: get<0>(DOB) = stoi(data); break;
                        case 4: get<1>(DOB) = stoi(data); break;
                        case 5: get<2>(DOB) = stoi(data); break;
                        case 6: mobile = data; break;
                        case 7: email = data; break;
                        case 8: upi = data; break;
                        case 9: account = data; break;
                        case 10: password = data; break;
                    }
                }

                p.create_profile(name, age, DOB, mobile, email, upi, account, password);
                UserCredentials::update_Login_credendials(email , p);
            }
            infile.close();
        }

        // Main menu loop
        do {
            cout << R"(

            TRAVELLER APPLICATION:

            1 - Login
            2 - Register
            3 - Exit

            Enter the option number to trigger the process.
            Example: Enter '3' to exit.

            )";

            cout << "Enter option: ";
            cin >> this->option;
            cout << "\n";

            if (this->option == 2) {
                userRegister u;
            }
        } while (this->option != 3);

        // File processing (Writing to DB.txt)
        ofstream outfile("DB.txt", ios::trunc);
        if (!outfile) {
            cerr << "Error opening file for writing!\n";
        } else {
            outfile << stringify(UserCredentials::get_login_credentials_for_storing());
            outfile.close();
            cout << "File overwritten successfully.\n";
        }
    }

    string stringify(const map<string, Profile>& alpha) {
        string data;
        for (auto a : alpha) {
            data += a.second.get_data_string();
        }
        return data;
    }
};

#endif
