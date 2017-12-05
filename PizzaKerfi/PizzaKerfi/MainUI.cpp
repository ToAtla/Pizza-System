//
//  MainUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "MainUI.hpp"
#include "AdminUI.hpp"
#include "PrepUI.hpp"
#include "SalesUI.hpp"
#include "DeliveryUI.hpp"
#include "LocationRepo.hpp"
#include "Location.hpp"
#include "ConsoleMagic.hpp"
#include <stdlib.h>

void MainUI::startUI(){
    
    char input = '\0';
    while(input != 'q'){
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
            //branchLocation();
        }
        else if(input == '4'){
            DeliveryUI deliveryUI;
            deliveryUI.startDeliveryUI();
            //branchLocation();
        }
        else if(input == 'q'){
            break;
        }
       
    }
}

void MainUI::branchLocation(){

    //A EFTIR AD KLARA!!
    cout << endl <<  "-----Locations-----" << endl;
    LocationRepo locationRepo;
    vector<Location> locations = locationRepo.getVectorOfLocations();
    cout << endl;
    
        for(int i = 0; i < locations.size(); i++){
            Location temp = locations.at(i);
            cout << "Location number: " << i+1 << endl;
            cout <<  temp << endl;
        }
        int input = 0;
        cout << "Choose a location: ";
        cin >> input;
        
        for(int i = 0; i < locations.size(); i++){
            if(input == i+1){
                
            }
        }
    
}
