#include<bits/stdc++.h>

#include "Profile.h"
#include "premiumCustomer.h"
#include "busowner.h"
using namespace std;
//temperory database
unordered_map<string , int> Login_credentials;
//rows and columns in db
//temperory database ends
int main()
{
    
    Profile p;
   
    premiumCustomer p2(p);
    Busowner p3(p);
    p.print_details();
    // cout << k.first"-"<<k.second<<"\n";
    int a;
    cin >> a;
    return 0;
}

/*compile statement
g++ Main.cpp -o output
*/