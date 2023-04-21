#include <iostream>
#include "ServiceCenter.h"

int main(int argc, char* argv[]){
    ServiceCenter SSC(argv[1]);
    SSC.simulateDay();
    SSC.printCenterStats(); 
}