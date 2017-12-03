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
            displayOrders();
        }
        else if(input == '2'){
        }
        else if(input == '3'){
        }
        else if(input == '4'){
        }
    }
}

void DeliveryUI::displayOrders(){
    string orderFile = "orders.dat";
    OrderRepo ordRep;
    int sizeOfOrderList;
    Order* orders = ordRep.retrieveOrderArray(orderFile, sizeOfOrderList);
    cout << " - - - - Orders - - - - " << endl;
    if(ordRep.fileExists(orderFile) && sizeOfOrderList != 0){
        for (int i = 0; i < sizeOfOrderList; i++) {
            if(orders[i].isPaid()){
                cout << "#" << i+1 << " PAID"<< endl;
            }else{
                cout << "#" << i+1 << " NOT PAID"<< endl;
            }
            cout << orders[i] << endl;
        }
        cout << endl;
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
}
