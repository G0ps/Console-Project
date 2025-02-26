#ifndef INDEX_H
#define INDEX_H

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <tuple>
#include <stdexcept>
#include <fstream>
#include <limits>

#include "UserCredentials.h"
#include "userRegister.h"
#include "Profile.h"
#include "user_login.h"

using namespace std;

map<string, Profile> UserCredentials::Login_credentials;
namespace register1{
    class index {
        int option;
    public:
        index() {
            // File processing (Reading from UserCredentials.txt)
            ifstream infile("UserCredentials.txt");
            if (!infile) {
                cerr << "Error opening file for reading!\n";
            } else {
                string line;
                while (getline(infile, line)) {
                    if (line.empty() || line[0] == '~') {
                        break;
                    }

                    Profile p;
                    string name, mobile, email, upi, account, password;
                    int age = 0;
                    tuple<int, int, int> DOB = make_tuple(1, 1, 1);

                    int ind = 0;
                    int size = line.size();

                    for (int i = 1; i <= 11; i++) {
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
                            case 11: p.update_customer_type(data); break;
                        }
                        
                    }

                    p.create_profile(name, age, DOB, mobile, email, upi, account, password);
                    UserCredentials::update_Login_credendials(email, p);
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
                cin >> option;

                if (cin.fail()) {  // Check if input is invalid (non-integer)
                    cin.clear();    // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input! Please enter a valid option (1, 2, or 3).\n";
                    continue;  // Restart loop without processing invalid input
                }

                cout << "\n";

                if (option == 2) {
                    userRegister u;
                } else if (option == 1) {
                    user_login u;
                } else if (option != 3) {
                    cout << "Invalid option! Please enter 1, 2, or 3.\n";
                }

            } while (option != 3);

            // File processing (Writing to UserCredentials.txt)
            ofstream outfile("UserCredentials.txt", ios::trunc);
            if (!outfile) {
                cerr << "Error opening file for writing!\n";
            } else {
                outfile << stringify(UserCredentials::get_login_credentials_for_storing());
                outfile.close();
                cout << "File overwritten successfully.\n";
            }
        }

        string stringify(map<string, Profile> alpha) {
            string data;
            for (auto& a : alpha) {
                data += a.second.get_data_string();
            }
            data += "~\n";
            return data;
        }
    };
}
#endif
