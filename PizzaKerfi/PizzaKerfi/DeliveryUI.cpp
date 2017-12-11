//
//  DeliveryUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "DeliveryUI.hpp"
#include "OrderRepo.hpp"
#include "LocationRepo.hpp"
#include <iostream>

using namespace std;

void DeliveryUI::startDeliveryUI(){
    char input = '\0';
    string sInput;
    bool cont = true;
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
            cout << "1: List all orders" << endl;
            cout << "2: List all unpaid orders" << endl;
            cout << "3: List all paid orders" << endl;
            cout << "4: List all legacy orders" << endl;
            cout << "b: back" << endl;
            cin >> input;
            cout << endl;
            
            if(input == '1'){
                displayAllOrders();
            }
            else if(input == '2'){
                displayUnpaidOrders();
            }
            else if(input == '3'){
                displayPaidOrders();
            }
            else if(input == '4'){
                displayLegacyOrders();
            }
        }
    }
}

void DeliveryUI::chooseYourLocation(){
    
    vector<Location> locations;
    LocationRepo lr;
    locations = lr.getVectorOfLocations();
    
    cout << "- - - - - - Choose your location - - - - - - -" << endl;
    for(int i = 0; i < locations.size(); i++){
        cout << "Location number: " << i+1 << endl;
        cout << locations[i] << endl << endl;
    }
    cout << "Choose location (no whitespaces): ";
    string input;
    cin >> input;
    
    if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), locations.size())){
        
        int intInput = stoi(input);
    
        for(int i = 0; i < locations.size(); i++){
            if(intInput == i+1){
                this->locationOfDelivery = locations[i];
            }
        }
    }
}

void DeliveryUI::displayAllOrders(){
    string orderFile = "orders.dat";
    OrderRepo ordRep;
    int sizeOfOrderList;
    Order* orders = ordRep.retrieveOrderArray(orderFile, sizeOfOrderList);
    //Kominn með allar pantanir
    //þarf núna að sigta út virkar pantanir þeas þær sem er ekki búið að afgreiða
    int amountOfUndeliveredOrdersAtThisLocation = 0;
    for (int i = 0; i < sizeOfOrderList; i++) {
        if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && orders[i].getStatusOfOrder() != DELIVERED){
            amountOfUndeliveredOrdersAtThisLocation++;
        }
    }
    cout << " - - - - - - - - - - Listing All Active Orders in " << locationOfDelivery << " - - - - - - - - - - " << endl;
    if(ordRep.fileExists(orderFile) && amountOfUndeliveredOrdersAtThisLocation != 0){
        for (int i = 0; i < sizeOfOrderList; i++) {
            if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && orders[i].getStatusOfOrder() != DELIVERED){
                cout << orders[i] << endl;
            }
        }
        cout << endl;
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
    delete [] orders;
}

void DeliveryUI::displayUnpaidOrders(){
    string orderFile = "orders.dat";
    OrderRepo ordRep;
    int sizeOfOrderList;
    Order* orders = ordRep.retrieveOrderArray(orderFile, sizeOfOrderList);
    //Kominn með allar pantanir
    //þarf núna að sigta út ógreiddar
    int amountOfUnpaidUndeliveredOrdersAtThisLocation = 0;
    for (int i = 0; i < sizeOfOrderList; i++) {
        if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && orders[i].getStatusOfOrder() != PAID && orders[i].getStatusOfOrder() != DELIVERED){
            amountOfUnpaidUndeliveredOrdersAtThisLocation++;
        }
    }
    cout << " - - - - - - - - - - Listing Unpaid Orders in " << locationOfDelivery << " - - - - - - - - - - " << endl;
    if(ordRep.fileExists(orderFile) && amountOfUnpaidUndeliveredOrdersAtThisLocation != 0){
        for (int i = 0; i < sizeOfOrderList; i++) {
            if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && orders[i].getStatusOfOrder() != PAID && orders[i].getStatusOfOrder() != DELIVERED){
                cout << orders[i] << endl;
            }
        }
        cout << endl;
    
    
        int input = 1;
        while(input != 0){
            cout << "Enter order number to mark as paid or 0 to exit (no whitespaces): ";
            cin >> input;
            if(input != 0 && bizniz.getOrderNumber(input).getStatusOfOrder() == UNPAID){
                bizniz.setOrderStatus(ORDERFILE, input, PAID);
                cout << "Order number " << input << " has been marked as ready" << endl;
                input = 0;
            }
        }
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
    delete [] orders;
}

void DeliveryUI::displayPaidOrders(){
    string orderFile = "orders.dat";
    OrderRepo ordRep;
    int sizeOfOrderList;
    Order* orders = ordRep.retrieveOrderArray(orderFile, sizeOfOrderList);
    //Kominn með allar pantanir
    //þarf núna að sigta út greiddar
    int amountOfPaidUndeliveredOrdersAtThisLocation = 0;
    for (int i = 0; i < sizeOfOrderList; i++) {
        if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && orders[i].getStatusOfOrder() == PAID && orders[i].getStatusOfOrder() != DELIVERED){
            amountOfPaidUndeliveredOrdersAtThisLocation++;
        }
    }
    cout << " - - - - - - - - - - Listing Paid Orders in " << locationOfDelivery << " - - - - - - - - - - " << endl;
    if(ordRep.fileExists(orderFile) && amountOfPaidUndeliveredOrdersAtThisLocation != 0){
        for (int i = 0; i < sizeOfOrderList; i++) {
            if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && orders[i].getStatusOfOrder() == PAID && orders[i].getStatusOfOrder() != DELIVERED){
                cout << orders[i] << endl;
            }
        }
        cout << endl;
    
    
        int input = 1;
        while(input != 0){
            cout << "Enter number of order to mark delivered or 0 to exit (no whitespaces): ";
            cin >> input;
            if((input != 0) && bizniz.getOrderNumber(input).getStatusOfOrder() == PAID){
                if(!bizniz.allPizzasInOrderReady(bizniz.getOrderNumber(input))){
                    cout << "Not all items in that order are ready" << endl;
                }else{
                    bizniz.setOrderStatus(ORDERFILE, input, DELIVERED);
                    cout << "Order number " << input << " has been marked delivered" << endl;
                    input = 0;
                }
            }
        }
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
    delete [] orders;
}


void DeliveryUI::displayLegacyOrders(){
    string orderFile = "orders.dat";
    OrderRepo ordRep;
    int sizeOfOrderList;
    Order* orders = ordRep.retrieveOrderArray(orderFile, sizeOfOrderList);
    //Kominn með allar pantanir
    //þarf núna að sigta út óvirkar pantanir þeas þær sem er  bið að afgreiða
    int amountOfDeliveredOrdersAtThisLocation = 0;
    for (int i = 0; i < sizeOfOrderList; i++) {
        if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && orders[i].getStatusOfOrder() == DELIVERED){
            amountOfDeliveredOrdersAtThisLocation++;
        }
    }
    
    cout << " - - - - - - - - - - Listing All Legacy Orders in " << locationOfDelivery << " - - - - - - - - - - " << endl;
    if(ordRep.fileExists(orderFile) && amountOfDeliveredOrdersAtThisLocation != 0){
        for (int i = 0; i < sizeOfOrderList; i++) {
            if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && orders[i].getStatusOfOrder() == DELIVERED){
                cout << orders[i] << endl;
            }
        }
        cout << endl;
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
    delete [] orders;
}
