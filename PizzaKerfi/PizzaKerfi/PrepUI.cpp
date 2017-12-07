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
    
    chooseYourLocation();
    
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

void PrepUI::chooseYourLocation(){
    
    vector<Location> locations;
    LocationRepo lr;
    locations = lr.getVectorOfLocations();
    bool goodInput = true;
    
    while(goodInput) {
        cout << "- - - - - - Choose your location - - - - - - -" << endl;
        for(int i = 0; i < locations.size(); i++){
            cout << "Location number: " << i+1 << endl;
            cout << locations[i] << endl << endl;
        }
        cout << "Choose location: ";
        char input = 0;
        cin >> input;
        
        //Herna athuga eg hvort að input se bokstafur og ef það er bokstafur þa breyti eg good input i false.
        if(!isdigit(input)){
            cout << "Please enter a valid input" << endl;
            goodInput = false;
        }
        
        //Ef að inputið er ekki bokstafur þa fer fer maður í for loopuna og gefur private breytunni locationOfPrep gildid sem þu valdir.
        //Og goodInput er sett false og while loopan hættir að loopa.
        if(goodInput)
        {
            for(int i = 0; i < locations.size(); i++){
                if(input-48 == i+1){
                    this->locationOfPrep = locations[i];
                    goodInput = false;
                }
            }
        }
    }
    
}

void PrepUI::waitingOverview(){
    
    //Fylki af öllum biðpizzum
    //ýtra í gegnum það og birta þær
    string waitFile = "waiting.dat";
    string prepFile = "prepping.dat";
    PizzaRepo pr;
    
    int sizeOfWaitingPizzaList;
    int sizeOfWaitingPizzaListLocation;
    Pizza* waitPizzas = pr.retrievePizzaArray(waitFile, sizeOfWaitingPizzaList);
    Pizza* waitPizzasInLocation;
    
    cout << " - - - - Pizzas not yet started - - - - " << endl;
    
    if(pr.fileExists(waitFile) && sizeOfWaitingPizzaList != 0){
        
     /*   for(int i = 0; i < sizeOfWaitingPizzaList; i++){
            if(waitPizzas[i].getLocation().getLocation() == locationOfPrep.getLocation()){
                sizeOfWaitingPizzaListLocation++;
                waitPizzasInLocation[sizeOfWaitingPizzaListLocation] = waitPizzas[i];
            }
        }
        */
        for (int i = 0; i < sizeOfWaitingPizzaList; i++) {
            cout << "[" << i+1 << "] " << waitPizzas[i] << endl;
        }
        cout << endl;
        int input = '\0';
        while(input != '0'){
            cout << "Pick a number to mark for prep or 0 to exit: ";
            cin >> input;
            if(input != 0){
                if(input <= sizeOfWaitingPizzaListLocation && input > 0){
                    pr.moveBetween(waitFile, prepFile, input-1);
                    cout << "Pizza number " << input << " marked prepared" << endl;
                }
            }else{
                break;
            }
        }
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
}


void PrepUI::preppingOverview(){
    string prepFile = "prepping.dat";
    string readyFile = "ready.dat";
    PizzaRepo pr;
    int sizeOfPreppingList;
    Pizza* prepPizzas = pr.retrievePizzaArray(prepFile, sizeOfPreppingList);
    
    cout << " - - - - Pizzas being prepared - - - - " << endl;
    if(pr.fileExists(prepFile) && sizeOfPreppingList != 0){
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
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
}


void PrepUI::readyOverview(){
    string readyFile = "ready.dat";
    PizzaRepo pr;
    int sizeOfReadyList;
    Pizza* readyPizzas = pr.retrievePizzaArray(readyFile, sizeOfReadyList);
    cout << " - - - - Ready pizzas - - - - " << endl;
    if(pr.fileExists(readyFile) && sizeOfReadyList != 0){
        for (int i = 0; i < sizeOfReadyList; i++) {
            cout << "[" << i+1 << "] " << readyPizzas[i] << endl;
        }
        cout << endl;
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
}


