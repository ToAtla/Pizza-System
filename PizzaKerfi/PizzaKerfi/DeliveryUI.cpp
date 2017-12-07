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
    
    chooseYourLocation();
    
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

void DeliveryUI::chooseYourLocation(){
    
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
        
        //Ef að inputið er ekki bokstafur þa fer fer maður í for loopuna og gefur private breytunni locationOfDelivery gildid sem þu valdir.
        //Og goodInput er sett false og while loopan hættir að loopa.
        if(goodInput)
        {
            for(int i = 0; i < locations.size(); i++){
                if(input-48 == i+1){
                    this->locationOfDelivery = locations[i];
                    goodInput = false;
                }
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
        if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && !orders[i].isDelivered()){
            amountOfUndeliveredOrdersAtThisLocation++;
        }
    }
    cout << " - - - - - - - - - - Listing All Active Orders in " << locationOfDelivery << " - - - - - - - - - - " << endl;
    if(ordRep.fileExists(orderFile) && amountOfUndeliveredOrdersAtThisLocation != 0){
        for (int i = 0; i < sizeOfOrderList; i++) {
            if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && !orders[i].isDelivered()){
                cout << orders[i] << endl;
            }
        }
        cout << endl;
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
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
        if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && !orders[i].isPaid() && !orders[i].isDelivered()){
            amountOfUnpaidUndeliveredOrdersAtThisLocation++;
        }
    }
    cout << " - - - - - - - - - - Listing Unpaid Orders in " << locationOfDelivery << " - - - - - - - - - - " << endl;
    if(ordRep.fileExists(orderFile) && amountOfUnpaidUndeliveredOrdersAtThisLocation != 0){
        for (int i = 0; i < sizeOfOrderList; i++) {
            if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && !orders[i].isPaid() && !orders[i].isDelivered()){
                cout << orders[i] << endl;
            }
        }
        cout << endl;
    
    
        int input = '\0';
        while(input != '0'){
            cout << "Pick a number to mark for paid or 0 to exit: ";
            cin >> input;
            if(input != 0){
                if(input <= sizeOfOrderList && input > 0){
                    orderService.setOrderPaidValue(orderFile, input-1, true);
                    cout << "Order number " << input << " is now in preparation" << endl;
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

void DeliveryUI::displayPaidOrders(){
    string orderFile = "orders.dat";
    OrderRepo ordRep;
    int sizeOfOrderList;
    Order* orders = ordRep.retrieveOrderArray(orderFile, sizeOfOrderList);
    //Kominn með allar pantanir
    //þarf núna að sigta út greiddar
    int amountOfPaidUndeliveredOrdersAtThisLocation = 0;
    for (int i = 0; i < sizeOfOrderList; i++) {
        if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && orders[i].isPaid() && !orders[i].isDelivered()){
            cout << "Hér er ég" << endl;
            amountOfPaidUndeliveredOrdersAtThisLocation++;
        }
    }
    cout << " - - - - - - - - - - Listing Paid Orders in " << locationOfDelivery << " - - - - - - - - - - " << endl;
    if(ordRep.fileExists(orderFile) && amountOfPaidUndeliveredOrdersAtThisLocation != 0){
        for (int i = 0; i < sizeOfOrderList; i++) {
            if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && orders[i].isPaid() && !orders[i].isDelivered()){
                cout << orders[i] << endl;
            }
        }
        cout << endl;
    
    
        int input = '\0';
        while(input != '0'){
            cout << "Pick a number to mark for delivery or 0 to exit: ";
            cin >> input;
            if(input != 0){
                if(input <= sizeOfOrderList && input > 0){
                    orderService.setOrderDeliveredValue(orderFile, input-1, true);
                    cout << "Order number " << input << " marked prepared" << endl;
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


void DeliveryUI::displayLegacyOrders(){
    string orderFile = "orders.dat";
    OrderRepo ordRep;
    int sizeOfOrderList;
    Order* orders = ordRep.retrieveOrderArray(orderFile, sizeOfOrderList);
    //Kominn með allar pantanir
    //þarf núna að sigta út óvirkar pantanir þeas þær sem er  bið að afgreiða
    int amountOfDeliveredOrdersAtThisLocation = 0;
    for (int i = 0; i < sizeOfOrderList; i++) {
        if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && orders[i].isDelivered()){
            amountOfDeliveredOrdersAtThisLocation++;
        }
    }
    cout << " - - - - - - - - - - Listing All Legacy Orders in " << locationOfDelivery << " - - - - - - - - - - " << endl;
    if(ordRep.fileExists(orderFile) && amountOfDeliveredOrdersAtThisLocation != 0){
        for (int i = 0; i < sizeOfOrderList; i++) {
            if(locationOfDelivery.getLocation() == orders[i].getLocation().getLocation() && orders[i].isDelivered()){
                cout << orders[i] << endl;
            }
        }
        cout << endl;
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
}
