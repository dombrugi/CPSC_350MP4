#include "ServiceCenter.h"

ServiceCenter::ServiceCenter(){
    mTick = 1;
    inputFile = nullptr;
    allOffices = nullptr;
    allCusts = nullptr;
}

ServiceCenter::ServiceCenter(char* centerSpecs){
    mTick = 1;
    inputFile = centerSpecs;
    allOffices = new Office*[3];
    allCusts = new DblList<ListQueue<Customer*>*>;
}

ServiceCenter::~ServiceCenter(){}


bool ServiceCenter::simulateDay(){
    bool open = true;

    while(true){
        ListQueue<Customer*>* centerCustomers = nullptr; //initialized queue of customers to be populated and then seen

        while(centerCustomers->size() != 0){ //there is at least one customer still left
            Customer* student = centerCustomers->remove();
            addCustomer(student);
        }

        //If there are any customers that finished their business (were served) the previous tick, move them to their next office
        for(int i = 0; i < 3; ++i){                
            ListQueue<Customer*>* seen = allOffices[i]->getFinished();                 
            int numFinished = seen->size();
            for(int j = 0; j < numFinished; ++j){
                addCustomer(seen->remove());
            }
        }

        //All variations taken care of. See the customers
        for(int i = 0; i < 3; ++i){            
            allOffices[i]->seeCustomer();
        }
        ++mTick;
    }
    return open;
}


void ServiceCenter::printCenterStats(){
    int totalWaitOverTen = 0;
    int totalIdleOverFive = 0;

    //loops through all offices, prints their stats, and adds their wait over 10 and idle over 5 stats to total variables
    for(int i = 0; i < 3; ++i){
        if (i == 0)
            cout << "Registrar's ";
        else if (i == 1)
            cout << "Cashier's ";
        else if (i == 2)
            cout << "Financial Aid ";
        
    
        cout << "Office:" << endl;
        allOffices[i]->printOfficeStats();

        totalWaitOverTen += allOffices[i]->getWaitOverTen();
        totalIdleOverFive += allOffices[i]->getIdleOverFive();
    }

    cout << "Number of students waiting over 10 minutes across all offices: " << totalWaitOverTen << " tick(s)" << endl;
    cout << "Number of windows idle for over 5 minutes across all offices: " << totalIdleOverFive << " tick(s)" << endl;
}


void ServiceCenter::addCustomer(Customer* c){
    if(!c->isDone()){
        Visit* visit = c->getVisit();
        char temp = visit->getOffice();
        if (temp == 'R')
            allOffices[0]->enterCustomer(c);
        else if (temp == 'C')
            allOffices[1]->enterCustomer(c);
        else if (temp == 'F')
            allOffices[2]->enterCustomer(c);
        else
            cerr << "Office doesn't exist." << endl;
    }
}


bool ServiceCenter::newCenter(){
    bool newCenter = true;
    int officeSpecs[3] = {0, 0, 0};

    allOffices[0] = new Office(officeSpecs[0]); //Registrar
    allOffices[1] = new Office(officeSpecs[1]); //Cashier
    allOffices[2] = new Office(officeSpecs[2]); //Financial Aid

    return newCenter;
}