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
    
    if(bizniz.isValidLocationFile()){
    
        char input = '\0';
        string sInput;
        bool cont = true;
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        cout << setfill(CHARFORSPACE) << setw(SIZEOFCENTERHEADING+2) << " " << "    Preparation    " << endl;
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl << endl;
        cout << setfill(' ');
        try {
            chooseYourLocation();
        } catch (InvalidInputException) {
            cout << endl << "Invalid input! (input can't be a character and has to match a number on the list) Try again" << endl << endl;
            cout << "Press any key to continue: ";
            cin.ignore();
            getline(cin, sInput);
            cont = false;
        }
        
        
        if(cont){
            while(input != 'b'){
                magic.clearScreen();
                cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << setfill(' ') << endl;
                cout << setfill(' ') << setw(SIZEOFCENTERHEADING-3) << " " << "Preparation line in " << locationOfPrep << endl;
                cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << setfill(' ') << endl << endl;
                cout << setfill(' ') << setw(SIZEFORSETWSPACE) << " "  << "1: List all pizzas in house" << endl;
                uiItemSeparator();
                cout << setfill(' ') << setw(SIZEFORSETWSPACE) << " " << "2: List waiting pizzas and sides" << endl;
                uiItemSeparator();
                cout << setfill(' ') << setw(SIZEFORSETWSPACE) << " "  << "3: List pizzas and sides in preparation" << endl;
                uiItemSeparator();
                cout << setfill(' ') << setw(SIZEFORSETWSPACE) << " " << "4: List ready pizzas and sides" << endl;
                uiItemSeparator();
                cout << setfill(' ') << setw(SIZEFORSETWSPACE) << " "  << "b: back" << endl;
                uiItemSeparator();
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
    }
}


void PrepUI::allActiveOverview(){
    //Fylki af öllum
    //ýtra í gegnum það og birta þær
    string input;
    input[0] = '\0';
    magic.clearScreen();
    while(input != "0"){
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << setfill(' ') << endl;
        cout <<  setfill(CHARFORSPACE) << setw(SIZEOFCENTERHEADING+1) << " " <<  "All pizzas in " << locationOfPrep.getLocation() << endl;
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << setfill(CHARFORSPACE) << endl << endl;
        if (bizniz.thereExistsOrderAtLocationWithApplicablePizza(OUTOFSHOP, locationOfPrep, false)) {
            displayOrdersAtLocationWithApplicablePizzas(locationOfPrep, OUTOFSHOP, false);
        }else{
            cout << endl;
            cout << "List is empty" << endl;
            cout << endl;
        }
        cout << "Enter any key to continue: ";
        cin >> input;
        input = "0";
    }
}

void PrepUI::waitingOverview(){
    status currentStatus = WAITING;
    status nextStatus = PREPPING;
    string input;
    input[0] = '\0';
    magic.clearScreen();
    
    while(input != "0"){
         cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << setfill(CHARFORSPACE) << endl;
         cout <<  setfill(CHARFORSPACE) << setw(SIZEOFCENTERHEADING+1) << " " << "Pizzas with status " << bizniz.statusToString(currentStatus) << "in " << locationOfPrep.getLocation() << endl;
         cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << setfill(CHARFORSPACE) << endl << endl;
        
        if(bizniz.thereExistsOrderAtLocationWithApplicablePizza(currentStatus, locationOfPrep, true)){
            displayOrdersAtLocationWithApplicablePizzas(locationOfPrep, currentStatus, true);
            cout << endl << "Enter any key to mark top pizza in preparation or 0 to exit: ";
            cin >> input;
            if(input != "0"){
                int orderNum;
                int pizzaNum;
                bizniz.locateFirstOrderWithPizzaWithStatusAtLocation(currentStatus, locationOfPrep, orderNum, pizzaNum);
                bizniz.changeStatusOfPizzaInOrder(orderNum, pizzaNum, nextStatus);
                cout << "Top pizza marked in preparation" << endl;
                magic.clearScreen();
            }else{
                break;
            }
        }else{
            cout << endl;
            cout << "List is empty" << endl;
            cout << endl;
            cout << "Enter any key to continue: ";
            cin >> input;
            input = "0";
        }
    }
    
}

void PrepUI::preppingOverview(){
    status currentStatus = PREPPING;
    status nextStatus = READY;
    string input;
    input[0] = '\0';
    magic.clearScreen();
    //Ef ég get prentað út
    //prenta út
    
    
    while(input != "0"){
        
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << setfill(CHARFORSPACE) << endl;
        cout << setfill(CHARFORSPACE) << setw(SIZEOFCENTERHEADING+1) << " " << "Pizzas with status " << bizniz.statusToString(currentStatus) << " in " << locationOfPrep.getLocation() << endl;
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << setfill(CHARFORSPACE) << endl << endl;
        
        if(bizniz.thereExistsOrderAtLocationWithApplicablePizza(currentStatus, locationOfPrep, true)){
            displayOrdersAtLocationWithApplicablePizzas(locationOfPrep, currentStatus, true);
            cout << endl << "Enter any key to mark top pizza ready or 0 to exit: ";
            cin >> input;
            if(input != "0"){
                int orderNum;
                int pizzaNum;
                bizniz.locateFirstOrderWithPizzaWithStatusAtLocation(currentStatus, locationOfPrep, orderNum, pizzaNum);
                bizniz.changeStatusOfPizzaInOrder(orderNum, pizzaNum, nextStatus);
                cout << "Top pizza marked ready" << endl;
                magic.clearScreen();
            }else{
                break;
            }
        }else{
            cout << endl;
            cout << "List is empty" << endl;
            cout << endl;
            cout << "Enter any key to continue: ";
            cin >> input;
            input = "0";
        }
    }
}


void PrepUI::readyOverview(){
    string input;
    input[0] = '\0';
    magic.clearScreen();
    status currentStatus = READY;
    
    cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << setfill(' ') << endl;
    cout <<  setfill(CHARFORSPACE) << setw(SIZEOFCENTERHEADING+1) << " " <<  "Pizzas without status " << bizniz.statusToString(currentStatus) << " in " << locationOfPrep.getLocation() << endl;
    cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << setfill(CHARFORSPACE) << endl << endl;
    while(input != "0"){
        if (bizniz.thereExistsOrderAtLocationWithApplicablePizza(READY, locationOfPrep, true)) {
            displayOrdersAtLocationWithApplicablePizzas(locationOfPrep, READY, true);
        }else{
            cout << endl;
            cout << "List is empty" << endl;
            cout << endl;
        }
        cout << endl << "Enter any key to continue: ";
        cin >> input;
        input = "0";
    }
}

void PrepUI::displayOrdersAtLocationWithApplicablePizzas(Location location, status status, bool onlyWith){
    int size;
    Order* orderList = bizniz.getArrayOfOrdersAtLocationWithApplicablePizzas(status, location, onlyWith, size);
    for (int i = 0; i < size; i++) {
        cout << "#" << orderList[i].getID() << endl;
        int howManyPizzasApply;
        Pizza* pizzasThatApply = bizniz.extractApplicablePizzasFromOrder(orderList[i], status, onlyWith, howManyPizzasApply);
        for (int c = 0; c < howManyPizzasApply; c++) {
            cout << pizzasThatApply[c];
        }
        delete [] pizzasThatApply;
    }
    delete [] orderList;
}

void PrepUI::chooseYourLocation(){
    
    vector<Location> locations;
    LocationRepo lr;
    locations = lr.getVectorOfLocations();
    
    cout << setfill(CHARFORSETFILL) << setw(SIZEOFCENTERHEADING-2) << "-" << "    Choose your location    " << setfill(CHARFORSETFILL) << setw(SIZEOFCENTERHEADING-2) << "-";
    cout << setfill(' ') << endl << endl;
    for(int i = 0; i < locations.size(); i++){
        cout << setfill(' ') << setw(SIZEFORSETWSPACE) << " " << "Location number: " << i+1 << endl;
        cout << setfill(' ') << setw(SIZEFORSETWSPACE) << " " << locations[i] << endl;
        uiItemSeparator();
    }
    cout << "Choose location (no whitespaces): ";
    string input;
    cin >> input;
    
    
    if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), locations.size())){
    
        int intInput = stoi(input);
        
        for(int i = 0; i < locations.size(); i++){
            if(intInput == i+1){
                this->locationOfPrep = locations[i];
            }
        }
    }
}


void PrepUI::uiItemSeparator () {
    cout << setw(SIZEFORSETWSPACE) << " " << setfill(CHARFORSETFILL) << setw(SIZEOFSETW-41) << "-" << endl << endl;
    cout << setfill(' ');
}
