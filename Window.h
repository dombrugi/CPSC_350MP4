#ifndef WINDOW_H
#define WINDOW_H

#include "Customer.h"
#include <iostream>

class Window{
    public:
        Window();
        virtual ~Window();

        void windowCustomer(Customer* c);
        bool seeCustomer();
        void doneSeeing();
        void increaseIdle();

        Customer* getCustomer();
        bool inUse();
        int getIdle();

    private:
        Customer *mCustomer;
        bool mInUse;
        int mIdle; 
};

#endif