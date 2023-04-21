#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "ListQueue.h"
#include "Visit.h"
#include <iostream>

class Customer{
    public:
        Customer();
        Customer(int* times, char* offices);
        virtual ~Customer();

        void increaseWait();
        void setWait(int wait);
        void decreaseOfficeTime();
        void finishVisit();

        Visit* getVisit();
        int getWait();
        bool isDone();

    private:
        int mWait;
        bool mDone;
        ListQueue<Visit*> *ToDo; //list queue of visits that represents the customer's itinerary
};


#endif