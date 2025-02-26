#ifndef application_index_H
#define application_index_H

#include <iostream>
#include <set>

#include "../register/UserCredentials.h"
#include "../register/Profile.h"

using namespace std;
namespace application{
    class application_index :public UserCredentials{
        public:
        application_index(){
            build_bus_route();
            cout << "route builded\n";
        }



        void build_bus_route()
        {
            map<string , Profile>* Login_credentials = get_login_credentials_for_storing(1);
            // now the values are changable 
        }

    };
}
#endif