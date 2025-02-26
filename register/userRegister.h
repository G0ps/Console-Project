#ifndef USER_REGISTER_H
#define USER_REGISTER_H

#include <iostream>
#include <limits>
#include <algorithm>
#include "UserCredentials.h"
#include "Profile.h"
#include "userRegister_busRegister.h"

using namespace std;

class userRegister : public Profile {
    int options = 3;
public:
    userRegister() {
        do {
            cout << R"(
            REGISTRATION PORTAL
            userREGISTER AS
            option 1 -> User
            option 2 -> Collaborator
            option 3 -> Exit

            Enter option:
            )";
            cin >> options;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush input buffer

            if (options == 1 || options == 2) {
                try {
                    string name, mobile, email, upi, account, password, confirm_password;
                    int age = 0, day, month, year;

                    // Name input
                    while (name.empty()) {
                        cout << "\t\tName: ";
                        getline(cin, name);
                        if (name.size() > 20) {
                            cout << "\t\tReduce length (max 20 characters)\n";
                            name.clear();
                        }
                    }

                    // Age input
                    while (true) {
                        cout << "\t\tAge: ";
                        if (cin >> age && age > 0 && age < 150)
                            break;
                        cout << "\t\tInvalid age, try again\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    // Date of Birth input
                    while (true) {
                        cout << "\t\tEnter Birth Day (1-31): ";
                        if (cin >> day && day > 0 && day <= 31)
                            break;
                        cout << "\t\tInvalid day, try again\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    while (true) {
                        cout << "\t\tEnter Birth Month (1-12): ";
                        if (cin >> month && month > 0 && month <= 12)
                            break;
                        cout << "\t\tInvalid month, try again\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    while (true) {
                        cout << "\t\tEnter Birth Year (>1900): ";
                        if (cin >> year && year > 1900)
                            break;
                        cout << "\t\tInvalid year, try again\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush input buffer

                    // Mobile number input
                    while (mobile.length() != 10) {
                        cout << "\t\t10-digit Mobile Number: ";
                        cin >> mobile;
                        if (mobile.length() != 10 || !all_of(mobile.begin(), mobile.end(), ::isdigit)) {
                            cout << "\t\tInvalid number, try again\n";
                            mobile.clear();
                        }
                    }

                    // Email input (Ensuring uniqueness)
                    cout << "\t\tEnter a unique Email ID (User ID): ";
                    cin >> email;
                    while (UserCredentials::check_Login_credentials(email)) {
                        cout << "\t\tID already exists, enter another Email ID: ";
                        cin >> email;
                    }

                    // UPI & Account inputs
                    while (upi.empty()) {
                        cout << "\t\tEnter UPI ID: ";
                        cin >> upi;
                    }

                    while (account.empty()) {
                        cout << "\t\tEnter Account Number: ";
                        cin >> account;
                    }

                    // Password input & confirmation
                    while (true) {
                        cout << "\t\tEnter Password: ";
                        cin >> password;
                        cout << "\t\tConfirm Password: ";
                        cin >> confirm_password;

                        if (password == confirm_password)
                            break;
                        cout << "\t\tPasswords do not match, try again\n";
                    }

                    // Create Profile
                    pair<string, Profile> user_cred = create_profile(
                        name, age, make_tuple(day, month, year), mobile, email, upi, account, password
                    );

                    // Store credentials
                    UserCredentials::update_Login_credendials(user_cred.first, user_cred.second);

                    // Register as Collaborator if selected
                    if (options == 2) {
                        userRegister_busRegister(user_cred.second);
                    }

                    cout << "Login enabled\n";
                    break;
                }
                catch (exception &e) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\t\tAn error occurred, please try again.\n";
                    break;  // Instead of `continue`, exit the loop on error
                }
            }
        } while (options != 3);
    }
};

#endif
