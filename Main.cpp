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
    bool flag = p.create_profile(
        "Gopinath S",
        19,
        k,
        "9344848312",
        "Gopinathshanmugavel@gmail.com",
        "sdasdasd",
        "129310238109283"

    );
    premiumCustomer p2(p);

    p.print_details();
    int a;
    cin >> a;
    return 0;
}

/*compile statement
g++ Main.cpp -o output
*/