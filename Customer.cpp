#include "Customer.h"


Customer::Customer(){
    mWait = 0;
    mDone = false;
    ToDo = nullptr;
}

Customer::Customer(int* times, char* offices){
    ToDo = new ListQueue<Visit*>;
    for(int i = 0; i < 3; ++i){
            Visit* visit = new Visit(offices[i], times[i]);
            ToDo->insert(visit);
    }
    mWait = 0;
    mDone = false;
}

Customer::~Customer(){
    if(ToDo != nullptr){
        delete ToDo;
    }
}

void Customer::increaseWait(){
    mWait++;
}

void Customer::setWait(int wait){
    mWait = wait;
}

int Customer::getWait(){
    return mWait;
}

void Customer::decreaseOfficeTime(){
    ToDo->peek()->decreaseTime();
}

void Customer::finishVisit(){
    if(!ToDo->isEmpty())
        ToDo->remove();
    if(ToDo->isEmpty())
        mDone = true;
}

Visit* Customer::getVisit(){
    return ToDo->peek();
}

bool Customer::isDone(){
    return mDone;
}