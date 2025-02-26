#include<bits/stdc++.h>

#include "Profile.h"
#include "premiumCustomer.h"

using namespace std;
//temperory database
unordered_map<string , int> Login_credentials;
//rows and columns in db
//temperory database ends
int main()
{
    
    auto k = make_tuple(14, 10, 2005);
    Profile p;
    pair<string , string> k1 = p.create_profile(
        "Gopinath S",
        19,
        k,
        "9344848312",
        "Gopinathshanmugavel@gmail.com",
        "sdasdasd",
        "129310238109283",
        "asdhajgshdhasgdh"
    );
    cout << k1.first<<"-"<<k1.second<<"\n";
    Profile p8;
    k1 = p8.create_profile(
        "Gopinath S",
        19,
        k,
        "9344848312",
        "Gopinathshanmugavel@gmail.com",
        "sdasdasd",
        "129310238109283",
        "asdhajgshdhaasasdasdsgdh"
    );
    cout << k1.first<<"-"<<k1.second<<"\n";
    premiumCustomer p2(p);
    
    p.print_details();
    // cout << k.first"-"<<k.second<<"\n";
    int a;
    cin >> a;
    return 0;
}

/*compile statement
g++ Main.cpp -o output
*/