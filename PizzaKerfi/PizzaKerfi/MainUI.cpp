//
//  MainUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "MainUI.hpp"

#include <stdlib.h>

void MainUI::startUI(){
    
    
    
    char input = '\0';
    while(input != 'q'){
        magic.clearScreen();
        cout << " -------------------------------" << endl;
        cout << "|1: Manager     |2: Sales       |" << endl;
        cout << " -------------------------------" << endl;
        cout << "|3: Prep        |4: Delivery    |" << endl;
        cout << " -------------------------------" << endl;
        cout << "|q: quit        |" << endl;
        cout << " ---------------" << endl;
        cin >> input;
        cout << endl;
        
        if(input == '1'){
            magic.clearScreen();
            AdminUI adminUI;
            adminUI.startAdminUI();
        }
        else if(input == '2'){
            SalesUI salesUI;
            salesUI.startSalesUI();
        }
        else if(input == '3'){
            PrepUI prepUI;
            prepUI.startPrepUI();
        }
        else if(input == '4'){
            DeliveryUI deliveryUI;
            deliveryUI.startDeliveryUI();
        }
        else if(input == 'q'){
            break;
        }
       
    }
}
