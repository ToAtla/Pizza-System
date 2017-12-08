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
        cout << "1: List all pizzas in house" << endl;
        cout << "2: List waiting pizzas and sides" << endl;
        cout << "3: List pizzas and sides in preparation" << endl;
        cout << "4: List ready pizzas and sides" << endl;
        cout << "b: back" << endl;
        cin >> input;
        cout << endl;
        
        if(input == '1'){
            allActiveOverview();
        }
        else if(input == '2'){
            waitingOverview();
            
        }
        else if(input == '3'){
            preppingOverview();
        }
        else if(input == '4'){
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

void PrepUI::allActiveOverview(){
    //Fylki af öllum
    //Fylki af öllum biðpizzum
    //ýtra í gegnum það og birta þær
    int sizeOfActivePizzaList;
    Pizza* activePizzasAtThisLocation = bizniz.getArrayOfPizzasAtLocationWithoutSomeStatus(DELIVERED, locationOfPrep, sizeOfActivePizzaList);
    
    cout << " - - - - All Pizzas in " << locationOfPrep << " - - - - " << endl;
    
    if(sizeOfActivePizzaList != 0){
        for (int i = 0; i < sizeOfActivePizzaList; i++) {
            cout << "[" << i+1 << "] " << activePizzasAtThisLocation[i] << endl;
        }
        cout << endl;
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
    delete [] activePizzasAtThisLocation;
    
}

void PrepUI::waitingOverview(){
    
    //Fylki af öllum biðpizzum
    //ýtra í gegnum það og birta þær
    int sizeOfWaitingPizzaList;
    Pizza* waitPizzasAtThisLocation = bizniz.getArrayOfPizzasAtLocationWithSomeStatus(WAITING, locationOfPrep, sizeOfWaitingPizzaList);
    
    cout << " - - - - Pizzas not yet started - - - - " << endl;
    
    if(sizeOfWaitingPizzaList != 0){
        for (int i = 0; i < sizeOfWaitingPizzaList; i++) {
            cout << "[" << i+1 << "] " << waitPizzasAtThisLocation[i] << endl;
        }
        cout << endl;
        int input = '\0';
        while(input != '0'){
            cout << "Pick a number to mark for prep or 0 to exit: ";
            cin >> input;
            if(input != 0){
                if(input <= sizeOfWaitingPizzaList && input > 0){
                    waitPizzasAtThisLocation[input-1].setStatus(PREPPING);
                    cout << "Pizza number " << input << " now in preparation" << endl;
                }
            }else{
                bizniz.savePizzaArrayInFile(waitPizzasAtThisLocation, sizeOfWaitingPizzaList);
                break;
            }
        }
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
    delete [] waitPizzasAtThisLocation;
}


void PrepUI::preppingOverview(){
    
    //Fylki af öllum vinnslupizzum
    //ýtra í gegnum það og birta þær
    int sizeOfPreppingPizzaList;
    Pizza* preppingPizzasAtThisLocation = bizniz.getArrayOfPizzasAtLocationWithSomeStatus(PREPPING, locationOfPrep, sizeOfPreppingPizzaList);
    cout << " - - - - Pizzas being prepared - - - - " << endl;
    
    if(sizeOfPreppingPizzaList != 0){
        for (int i = 0; i < sizeOfPreppingPizzaList; i++) {
            cout << "[" << i+1 << "] " << preppingPizzasAtThisLocation[i] << endl;
        }
        cout << endl;
        int input = '\0';
        while(input != '0'){
            cout << "Pick a number to mark ready or 0 to exit: ";
            cin >> input;
            if(input != 0){
                if(input <= sizeOfPreppingPizzaList && input > 0){
                    preppingPizzasAtThisLocation[input-1].setStatus(READY);
                    cout << "Pizza number " << input << " marked ready" << endl;
                }
            }else{
                bizniz.savePizzaArrayInFile(preppingPizzasAtThisLocation, sizeOfPreppingPizzaList);
                break;
            }
        }
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
    delete [] preppingPizzasAtThisLocation;
}


void PrepUI::readyOverview(){
    int sizeOfReadyList;
    Pizza* readyPizzasAtThisLocation = bizniz.getArrayOfPizzasAtLocationWithSomeStatus(READY, locationOfPrep, sizeOfReadyList);
    cout << " - - - - Ready pizzas - - - - " << endl;
    if(sizeOfReadyList != 0){
        for (int i = 0; i < sizeOfReadyList; i++) {
            cout << "[" << i+1 << "] " << readyPizzasAtThisLocation[i] << endl;
        }
        cout << endl;
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
}


