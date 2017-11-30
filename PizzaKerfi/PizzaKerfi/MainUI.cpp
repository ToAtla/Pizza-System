//
//  MainUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "MainUI.hpp"
#include "AdminUI.hpp"
#include <stdlib.h>

void MainUI::startUI(){

    char input = '\0';
    while(input != 'q')
    {
        cout << "1: Manager" << endl;
        cout << "2: Sales" << endl;
        cout << "3: Prep" << endl;
        cout << "4: Delivery" << endl;
        cout << "q: quit" << endl;
        cin >> input;
        cout << endl;
        
        if(input == '1'){
            AdminUI adminUI;
            adminUI.startAdminUI();
        }
        else if(input == '2'){
            branchLocation();

        }
        else if(input == '3'){
            branchLocation();
        }
        else if(input == '4'){
            branchLocation();
        }
        else if(input == 'q'){
            break;
        }
    }
}

void MainUI::branchLocation(){

//A EFTIR AD KLARA!!
cout << "Choose your location: " << endl;

}
