//
//  main.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 28/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Order.hpp"
#include "MainUI.hpp"

#include <cstring>
#include <stdlib.h>
#include <cstdio>
using namespace std;

int main(){

    /*
    //Hef streng STATUS
    char* sta = new char[9];
    //char sta[9];
    strcpy(sta, "WAITING   ");
    //Hef string BIL
    char* bil = new char[9];
    strcpy(bil, "          ");
    //Hef int price
    char* priceString = new char[5];
    int price = 4359;
    sprintf(priceString, "%d", price);
    //Vil STATUSBILprice
    strcat(sta, bil);
    strcat(sta, priceString);
    string str = sta;
    
    cout << sta << endl;
    cout << str << endl;
    */
    
    
    MainUI mainUI;
    mainUI.startUI();
    
    
    return 0;
}
