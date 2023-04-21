#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include "Customer.h"
#include "Window.h"
#include "Office.h"

class FileProcessor{
    public:
        FileProcessor();
        ~FileProcessor();

        void readFile(char* inputFileName, int* officeSize, DblList<ListQueue<Customer*>*>* allCustomers);
};

#endif