#ifndef application_index_H
#define application_index_H

#include <iostream>
#include <set>

#include "../register/UserCredentials.h"
#include "../register/Profile.h"

#include "application_premium_user.h"
#include "application_user.h"
#include "application_collaborator.h"

using namespace std;
namespace application{
    class application_index :public UserCredentials{
        public:
        application_index(){
           
        }
        application_index(string user_type , string user_id)
        {
            cout << "type - "<<user_type << " "<<"user id - "<<user_id<<"\n";
            if(user_type == "premiumCustomer") application_premium_user p(UserCredentials::get_data_for_process(user_id));
            if(user_type == "collaborator")
        }




        void build_bus_route()
        {
            map<string , Profile>* Login_credentials = get_login_credentials_for_storing(1);
            // now the values are changable 
        }

    };
}
#endif