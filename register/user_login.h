#ifndef USER_LOGIN_H
#define USER_LOGIN_H

#include <iostream>
#include <set>
#include "UserCredentials.h"
#include "Profile.h"
#include "premiumCustomer.h"
#include "../application/application_index.h"

using namespace std;

set<string> premium_codes = {"hiiampremiumcode1" , "hiiampremiumcode2" , "hiiampremiumcode3" , "hiiampremiumcode4"};

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
                        string customer_type = it.second.get_type_of_customer();
                        if(customer_type == "user")
                        {
                            cout << "\t\tBecome pro to unlock more features\n";
                            cout << "\t\tpress 1 to turn premium : ";
                            bool flag = 0;
                            cin >> flag;
                            if(flag)
                            {
                                string premiumlode = "";
                            {do{
                                    
                                    cout << "\n\t\t Enter premium code\n";
                                    cout << "\t\t Enter -1 to exit : ";
                                    string premiumlode;
                                    cin >> premiumlode;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    if(premium_codes.find(premiumlode) != premium_codes.end())
                                    {
                                        premium_codes.erase(premiumlode);
                                        premiumCustomer p(it.second);
                                        cout << "became premium successfull\n";
                                        break;
                                    }
                                }while(premiumlode != "-1");}
                            }
                        }
                        // it.second.print_details();
                        application::application_index a(it.second.get_type_of_customer(),it.second.get_user_id());
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
