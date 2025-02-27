#ifndef APPLICATION_PREMIUM_USER_H
#define APPLICATION_PREMIUM_USER_H

#include <iostream>
#include <set>
#include "application_interface.h"
#include "booking/booking.h"

using namespace std;

class application_premium_user : public application_interface {
public:
    // Constructor calling Base Class Constructor
    application_premium_user() : application_interface() {}

    application_premium_user(Profile p) : application_interface() {
        p.print_details();
        application_premium_user:run();
    }

    void print_options() override {
        cout << R"(
        Option 1 - Book vehicle with discount
        Option 2 - Spot Booking
        Option 3 - Free Cancellation
        Option 4 - Call Driver through Application
        Option 9 - Exit
        )";
    }

    void perform_option(int option) override {
        switch (option) {
            case 1: {
                booking b; 
                break;
            }
            default:
                cout << "Invalid Option" << endl;
                break;
        }
    }
};

#endif
