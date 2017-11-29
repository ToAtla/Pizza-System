//
//  MainUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "MainUI.hpp"
#include "AdminUI.hpp"


void MainUI::startUI(){
    
    char input = 0;
    while(input != 'q')
    {
        cout << "1: Admin" << endl;
        cout << "2: Sales" << endl;
        cout << "3: Prep" << endl;
        cout << "4: Delivery" << endl;
        cout << "q: quit" << endl;
        cin >> input;
        
        if(input == '1'){
            AdminUI adminUI;
            adminUI.startAdminUI();
        }
        else if(input == '2'){
            
        }
        else if(input == '3'){
            
        }
        else if(input == '4'){
        }
    }
}
