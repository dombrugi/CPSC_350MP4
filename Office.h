#ifndef OFFICE_H
#define OFFICE_H

#include "Window.h"
#include <iostream>

class Office{
    public:
        Office();
        Office(int w);
        virtual ~Office();

        void enterCustomer(Customer* c); //creates an instance of a customer and adds them to the office queue
        void seeCustomer();

        void setNumWindows(int w);
        void setNumCustomers(int c);
        ListQueue<Customer*>* getFinished();

        int getMaxWait();
        int getTotalWait();
        int getWaitOverTen();
        void updateWaitTimes(Customer* customer);
        void updateAllWait();

        int getMaxIdle();
        int getTotalIdle();
        int getIdleOverFive();
        void updateIdleTimes(Window *window);

        void printOfficeStats();
        


    private:
        Window** mWindows; //array of windows for the office
        ListQueue<Customer*> *officeCustomers; //the queue for each office's windows
        ListQueue<Customer*> *finishedCustomers; //the "line" of customers exiting the office (allows me to store them and check their final stats)

        int numWindows; 
        int numCustomers;

        int maxWait; 
        int totalWait; 
        int waitOverTen; 
        
        int maxIdle; 
        int totalIdle; 
        int idleOverFive; 
};




#endif