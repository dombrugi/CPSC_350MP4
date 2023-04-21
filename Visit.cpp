#include "Visit.h"

Visit::Visit(){
    mOffice = '\0';
    mTime = 0;
    mDone = false;
}

Visit::Visit(char office, int time){
    mOffice = office;
    mTime = time;
    mDone = false;
}

Visit::~Visit(){}

void Visit::decreaseTime(){
    --mTime;
    if (mTime == 0)
        mDone = true;
}

void Visit::setOffice(char office){
    mOffice = office;
}

char Visit::getOffice(){
    return mOffice;
}

void Visit::setTime(int time){
    mTime = time;
}

int Visit::getTime(){
    return mTime;
}

bool Visit::isDone(){
    return mDone;
}