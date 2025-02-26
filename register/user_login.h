#ifndef USER_LOGIN_H
#define USER_LOGIN_H

#include <iostream>
#include "UserCredentials.h"
#include "Profile.h"

using namespace std;

class user_login {
public:
    user_login() {
        while (true) {
            string email, password;
            
            cout << "\t\tEnter User ID (Email ID): ";
            cin >> email;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
            
            auto it = UserCredentials::can_login(email);
            if (!it.first) {
                cout << "\t\tInvalid Email ID! Try again.\n";
            } else {
                string actual_password = it.second.get_password();
                int retry_attempts = 3;

                while (retry_attempts > 0) {
                    cout << "\t\tEnter Password: ";
                    cin >> password;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

                    if (password == actual_password) {
                        cout << "\n\t\tLogged in successfully!\n";
                        return;
                    } else {
                        retry_attempts--;
                        cout << "\t\tIncorrect password! Attempts left: " << retry_attempts << "\n";
                    }
                }

                cout << "\n\t\tToo many failed attempts! Returning to main menu.\n";
            }

            int choice;
            cout << "\t\tEnter 0 to exit, 1 to retry: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

            if (choice == 0) {
                break;
            }
        }
    }
};

#endif
