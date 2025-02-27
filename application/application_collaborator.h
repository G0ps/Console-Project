#ifndef application_collaborator_H
#define application_collaborator_H

#include <iostream>
#include <set>
#include<bits/stdc++.h>

#include "../register/UserCredentials.h"

using namespace std;
    class application_collaborator{
        public:
        application_collaborator(){
            
        }
        pair<bool,int> add_busses()
        {
            cout << "\t\t Enter bus name : ";
            string name;
            if (!(cin >> name)) { 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number." << endl;
            }
            cout << "\t\t Enter bus id : ";
            string bus_id;
            cin >> bus_id;
            int k = 0;
            while(k != 1)
            {   
                 cout << "\t\tAdd a bus cred : \n";
                 cout << "Enter time : (number) :";
                 int time;
                 if (!(cin >> time)) { 
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a number." << endl;
                   
                 } 
                 string location;
                 cin >> location;
                 UserCredentials::bus_credentials[name].push_back({location , time});
                 cout << "\n";
                 cout <<"\t\t Enter 1 to terminate , or enter any key to add unique bus time and location : ";
                 if (!(cin >> k)) { 
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a number." << endl;
                   
                 }   
                 if(k == 1)
                 {
                    break;
                 } 

             }
        }
        pair<bool,int> remove_busses()
        {}
    };

#endif