#ifndef userRegister_H
#define userRegister_H

#include <bits/stdc++.h>

#include "UserCredentials.h"
#include "Profile.h"

using namespace std;
class userRegister:public Profile{
    int options = 3;
    public:
    userRegister(){
            do{
            
            cout << R"(
            REGISTRATION PORTAL
            userREGISTER AS
            option 1 -> user
            option 2 -> colaburator
            option 3 -> exit

            Enter option :- 
            )";
            cin >> this->options;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush input buffer
            
            if(this->options == 1 || this->options == 2)
            {
                try{

                    string name = "";
                    int age = 0;
                    tuple<int, int, int> DOB = make_tuple(1,1,1);
                    string mobile = "";
                    string email = "";
                    string upi = "";
                    string account = "";
                    string password = "";
                    string confirm_password = "";

                    //name
                    while(name.empty())
                    {
                        cout << "\t\tname : ";
                        getline(cin, name);
                        if(name.size() > 20)
                        {
                            cout << "\t\tReduce length\n";
                            name = "";
                        }
                    }
                    //age
                    while(true)
                    {
                        cout << "\t\tage : ";
                        if(cin >> age && age > 0 && age < 150)
                            break;
                        cout << "\t\tInvalid age, try again\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    //dob
                    while(true){
                        cout << "\t\tEnter a valid birth day : ";
                        if(cin >> get<0>(DOB) && get<0>(DOB) > 0 && get<0>(DOB) < 32)
                            break;
                        cout << "\t\tInvalid day, try again\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    while(true)
                    {
                        cout << "\t\tEnter a valid birth month : ";
                        if(cin >> get<1>(DOB) && get<1>(DOB) > 0 && get<1>(DOB) < 13)
                            break;
                        cout << "\t\tInvalid month, try again\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    while(true)
                    {
                        cout << "\t\tEnter a valid birth year : ";
                        if(cin >> get<2>(DOB) && get<2>(DOB) > 1900)
                            break;
                        cout << "\t\tInvalid year, try again\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    
                    while(mobile.length() != 10)
                    {
                        cout << "\t\t10-digit mobile number : ";
                        cin >> mobile;
                        if(mobile.length() != 10 || !all_of(mobile.begin(), mobile.end(), ::isdigit)){
                            cout << "\t\tInvalid number, try again\n";
                            mobile = "";
                        }
                    }
                    
                    cout << "\t\tEnter a unique email id (user id) : ";
                    cin >> email;
                    while(UserCredentials::check(email))
                    {
                        cout << "\t\tID already present\n";
                        cout << "Enter another email id (user id) : ";
                        cin >> email;
                    }
                    
                    cout << "\t\tEnter UPI: ";
                    cin >> upi;
                    cout << "\t\tEnter account no: ";
                    cin >> account;
                    
                    while(true)
                    {
                        cout << "\t\tEnter password: ";
                        cin >> password;
                        cout << "\t\tConfirm password: ";
                        cin >> confirm_password;
                        
                        if(password == confirm_password)
                            break;
                        cout << "\t\tPasswords do not match, try again\n";
                    }
                    
                    pair<string , string> user_cred = create_profile(
                        name,
                        age,
                        DOB,
                        mobile,
                        email,
                        upi,
                        account,
                        password
                    );
                    cout << "\tid = " << user_cred.first << " \n\tpass = " << user_cred.second << "\n";
                    break;
                }
                catch(exception &e){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
            }
        }while(this->options != 3);
    }
    
};
#endif
