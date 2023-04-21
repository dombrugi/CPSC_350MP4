#include "Window.h"

Window::Window(){
    mCustomer = nullptr;
    mInUse = false;
    mIdle = 0;
}

Window::~Window(){
    if(mCustomer != nullptr)
        delete mCustomer;
}

void Window::windowCustomer(Customer* c){
    mCustomer = c;
    mCustomer->setWait(0);
    mInUse = true;
}

bool Window::seeCustomer(){
    bool done = false;
    if(mCustomer != nullptr){
        mCustomer->decreaseOfficeTime();
        if(mCustomer->getVisit()->isDone()){
            done = true;
        }
    }
    return done;
}

void Window::doneSeeing(){
    mCustomer->finishVisit();
    mCustomer = nullptr;
    mInUse = false;
}

void Window::increaseIdle(){
    mIdle++;
}

int Window::getIdle(){
    return mIdle;
}

Customer* Window::getCustomer(){
    return mCustomer;
}

bool Window::inUse(){
    return mInUse;
}

