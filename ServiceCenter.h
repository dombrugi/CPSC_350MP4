#ifndef SERVICECENTER_H
#define SERVICECENTER_H

#include "Office.h"
#include "FileProcessor.h"

class ServiceCenter{
    public:
        ServiceCenter();
        ServiceCenter(char* centerSpecs);
        ~ServiceCenter();

        void addCustomer(Customer* c);
        bool newCenter();

        bool simulateDay();
        void printCenterStats();

    private:
        int mTick; //The global simulation tick
        char* inputFile; //The name of the input file to be read into constructor
        Office** allOffices; //All the offices in the center in the order given in the file
        DblList<ListQueue<Customer*>*>* allCusts; //A linked list of the queues of customers for the day 
};

#endif