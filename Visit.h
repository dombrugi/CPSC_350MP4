#ifndef VISIT_H
#define VISIT_H

#include <iostream>

using namespace std;

class Visit{
    public:
        Visit();
        Visit(char office, int time);
        virtual ~Visit();

        void decreaseTime();

        void setOffice(char office);
        void setTime(int time);
        char getOffice();
        int getTime();
        bool isDone();

    private:
        char mOffice; //Office the customer is visiting
        int mTime; //Length of visit
        bool mDone; //True when the visit is over
};

#endif