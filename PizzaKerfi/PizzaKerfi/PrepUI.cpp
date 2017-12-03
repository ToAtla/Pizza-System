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
    string waitFile = "waiting.dat";
    string prepFile = "prepping.dat";
    PizzaRepo pr;
    
    int sizeOfWaitingPizzaList;
    Pizza* waitPizzas = pr.retrievePizzaArray(waitFile, sizeOfWaitingPizzaList);
    for (int i = 0; i < sizeOfWaitingPizzaList; i++) {
        cout << "[" << i+1 << "] " << waitPizzas[i] << endl;
    }
    cout << endl;
    int input = '\0';
    while(input != '0'){
        cout << "Pick a number to mark for prep or 0 to exit: ";
        cin >> input;
        if(input != 0){
            if(input <= sizeOfWaitingPizzaList && input > 0){
                pr.moveBetween(waitFile, prepFile, input-1);
                cout << "Pizza number " << input << " marked prepared" << endl;
            }
        }else{
            break;
        }
    }
}


void PrepUI::preppingOverview(){
    string prepFile = "prepping.dat";
    string readyFile = "ready.dat";
    PizzaRepo pr;
    
    int sizeOfPreppingList;
    Pizza* prepPizzas = pr.retrievePizzaArray(prepFile, sizeOfPreppingList);
    for (int i = 0; i < sizeOfPreppingList; i++) {
        cout << "[" << i+1 << "] " << prepPizzas[i] << endl;
    }
    cout << endl;
    int input = '\0';
    while(input != '0'){
        cout << "Pick a number to mark ready or 0 to exit: ";
        cin >> input;
        if(input != 0){
            if(input <= sizeOfPreppingList && input > 0){
                pr.moveBetween(prepFile, readyFile, input-1);
                cout << "Pizza number " << input << " marked ready" << endl;
            }
        }else{
            break;
        }
    }
}

void PrepUI::readyOverview(){
    
}
