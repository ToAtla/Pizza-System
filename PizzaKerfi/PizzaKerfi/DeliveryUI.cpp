//
//  DeliveryUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "DeliveryUI.hpp"
#include "OrderRepo.hpp"
#include <iostream>

using namespace std;

void DeliveryUI::startDeliveryUI(){
    char input = '\0';
    while(input != 'b'){
        cout << "1: List all orders regarding paid status" << endl;
        cout << "2: " << endl;
        cout << "3: options" << endl;
        cout << "4: BROKEN" << endl;
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
        }
    }
}


void DeliveryUI::displayAllOrders(){
    cout << "WORK IN PROGRESS" << endl;
}

void DeliveryUI::displayUnpaidOrders(){
    string orderFile = "orders.dat";
    OrderRepo ordRep;
    int sizeOfOrderList;
    Order* orders = ordRep.retrieveOrderArray(orderFile, sizeOfOrderList);
    cout << " - - - - Orders - - - - " << endl;
    if(ordRep.fileExists(orderFile) && sizeOfOrderList != 0){
        for (int i = 0; i < sizeOfOrderList; i++) {
            cout << "#" << i+1;
            if(orders[i].isPaid()){
                cout << " PAID"<< endl;
            }else{
                cout << " NOT PAID"<< endl;
            }
            cout << orders[i] << endl;
        }
        cout << endl;
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
    
    int input = '\0';
    while(input != '0'){
        cout << "Pick a number to mark for paid or 0 to exit: ";
        cin >> input;
        if(input != 0){
            if(input <= sizeOfOrderList && input > 0){
                orderService.setOrderPaidValue(orderFile, input-1, true);
                cout << "Order number " << input << " marked prepared" << endl;
            }
        }else{
            break;
        }
    }
}

void DeliveryUI::displayPaidOrders(){
    cout << "WORK IN PROGRESS" << endl;
}
