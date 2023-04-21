#include "Office.h"
#include "Window.h"

Office::Office(){
    mWindows = nullptr;
    officeCustomers = nullptr;
    finishedCustomers = nullptr;
    numWindows = 0;
    numCustomers = 0;
    maxWait = 0;
    totalWait = 0;
    waitOverTen = 0;
    maxIdle = 0;
    totalIdle = 0;
    idleOverFive = 0;
}

Office::Office(int w){
    mWindows = new Window*[w];

    for (int i = 0; i < w; ++i)
        mWindows[i] = new Window();

    officeCustomers = new ListQueue<Customer*>();
    finishedCustomers = new ListQueue<Customer*>();

    numWindows = w;
    numCustomers = 0;
    maxWait = 0;
    totalWait = 0;
    waitOverTen = 0;
    maxIdle = 0;
    totalIdle = 0;
    idleOverFive = 0;
}

Office::~Office(){
    if(mWindows != nullptr){
        for (int i = 0; i < numWindows; ++i)
            delete mWindows[i];
    }
    if(officeCustomers != nullptr)
        delete officeCustomers;
    if(finishedCustomers != nullptr)
        delete finishedCustomers;
}

void Office::enterCustomer(Customer* c){
    officeCustomers->insert(c);
    ++numCustomers;
}

void Office::seeCustomer(){
    for(int i = 0; i < numWindows; ++i){
        //Take customer out of office line and put them at an open window
        if(!(officeCustomers->isEmpty()) && !(mWindows[i]->inUse())){            
            updateWaitTimes(officeCustomers->peek());
            mWindows[i]->windowCustomer(officeCustomers->remove());
        }

        //Serve customer at the window
        if(mWindows[i]->inUse()){
            if(mWindows[i]->seeCustomer()){ //if customer is done (will return true)
                finishedCustomers->insert(mWindows[i]->getCustomer());
                mWindows[i]->doneSeeing();
            }
        }
        else
            updateIdleTimes(mWindows[i]);
    }
    //There are still customers in the office queue
    if(!officeCustomers->isEmpty())     
        updateAllWait();
}


//accessors and mutators
void Office::setNumWindows(int w){
    numWindows = w;
}

void Office::setNumCustomers(int c){
    numCustomers = c;
}

ListQueue<Customer*>* Office::getFinished(){
    return finishedCustomers;
}

int Office::getMaxWait(){
    return maxWait;
}

int Office::getTotalWait(){
    return totalWait;
}

int Office::getWaitOverTen(){
    return waitOverTen;
}

int Office::getMaxIdle(){
    return maxIdle;
}

int Office::getTotalIdle(){
    return totalIdle;
}

int Office::getIdleOverFive(){
    return idleOverFive;
}


//methods to update all idle/wait times to keep track on each clock tick
void Office::updateWaitTimes(Customer* customer){
    int customerWait = customer->getWait();
    totalWait += customerWait;

    if(customerWait > maxWait)
        maxWait = customerWait;
    if(customerWait > 10)
        ++waitOverTen;
}


void Office::updateIdleTimes(Window *window){
    ++totalIdle;
    window->increaseIdle();
    if(window->getIdle() > maxIdle)
        maxIdle = window->getIdle();
    if(window->getIdle() > 5)
        ++idleOverFive;
}


void Office::updateAllWait(){
    int numCustomers = officeCustomers->size();
    //increase wait times for all the customers in the office queue
    for(int i = 0; i < numCustomers; ++i){
        Customer* temp = officeCustomers->remove();
        temp->increaseWait();
        officeCustomers->insert(temp);
    }
}

//print the office stats according to specifications
void Office::printOfficeStats(){
    cout << "Mean student wait time: " << (totalWait/numCustomers) << " tick(s)" << endl;
    cout << "Mean window idle time: " << (totalIdle/numWindows) << " tick(s)" << endl; 
    cout << "Longest student wait time: " << maxWait << " tick(s)" << endl;
    cout << "Longest window idle time: " << maxIdle << " tick(s)" << endl;
    cout << endl;
}