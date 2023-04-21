#include "FileProcessor.h"

FileProcessor::FileProcessor(){}

FileProcessor::~FileProcessor(){}

void FileProcessor::readFile(char* inputFileName, int* officeSize, DblList<ListQueue<Customer*>*>* allCustomers){
    ifstream fileIn;
    fileIn.open(inputFileName, ios::in);
    for(int i = 0; i < 3; ++i){
        string l;
        getline(fileIn, l);
        officeSize[i] = stoi(l);
    }

    while(!fileIn.eof()){ //while there is still data in the file
        string tick;
        getline(fileIn, tick); //first line is initial tick

        ListQueue<Customer*>* temp = new ListQueue<Customer*>; //temp customer queue to hold customers while their info is read in

        string nCusts; 
        getline(fileIn, nCusts); //second line is number of customers at that tick

        int times[3] = {0, 0, 0};
        char offices[3] = {'\0', '\0', '\0'};

        //Create a customer and give them their todo list
        for(int i = 0; i < stoi(nCusts); ++i){                
            for(int j = 0; j < 3; ++j){
                string customerTimes;
                getline(fileIn, customerTimes, ' ');
                times[j] = stoi(customerTimes);
            }

            //Put the rest of the info into one string, then iterate through it and assign chars to offices
            string tempOffices;
            getline(fileIn, tempOffices);
            for(int k = 0, l = 0; k < 6, l < 3; k += 2, ++l){
                offices[l] = tempOffices[k];
            }
            Customer* tempCust = new Customer(times, offices);
            temp->insert(tempCust); //add the customer to the temporary list
        }
        allCustomers->insertBack(temp); //take the customer out of the temporary list and add them to the center queue
    }

    fileIn.close();
}