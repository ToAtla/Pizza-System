//
//  PrepUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "PrepUI.hpp"
#include "PizzaRepo.hpp"
#include <iostream>

using namespace std;

void PrepUI::startPrepUI(){
    char input = '\0';
    while(input != 'b'){
        cout << "1: List waiting pizzas and sides" << endl;
        cout << "2: List pizzas and sides in preparation" << endl;
        cout << "3: List ready pizzas and sides" << endl;
        cout << "b: back" << endl;
        cin >> input;
        cout << endl;
        
        if(input == '1'){
            waitingOverview();
        }
        else if(input == '2'){
            preppingOverview();
        }
        else if(input == '3'){
            readyOverview();
        }
    }
}

void PrepUI::waitingOverview(){
    string file = "waiting.dat";
    PizzaRepo pr;
    
    int size;
    Pizza* waitPizzas = pr.retrievePizzaArray(file, size);
    for (int i = 0; i < size; i++) {
        cout << "[" << i+1 << "] " << waitPizzas[i] << endl;
    }
    cout << endl;
    int input = '\0';
    while(input != '0'){
        cout << "Pick a number to mark for prep or 0 to exit: ";
        cin >> input;
        if(input != 0){
            pr.moveBetween(file, "prepping.dat", input);
            cout << "Pizza number " << input << " marked prepared" << endl;
        }else{
            break;
        }
    }
    
    
    
}


void PrepUI::preppingOverview(){
    
}

void PrepUI::readyOverview(){
    
}
