//
//  AdminUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "AdminUI.hpp"

void AdminUI::startAdminUI(){
    
    char input = 0;
    while(input != 'q'){
        cout << "1: fikta i toppings" << endl;
        cout << "q: quit" << endl;
        cin >> input;
        
        if(input == '1'){
            displayToppingMenu();
        }
    }
}

void AdminUI::displayToppingMenu(){
    char input = '\0';
    while(input != 'q'){
        cout << "1: List toppings" << endl;
        cout << "2: Change a topping BROKEN" << endl;
        cout << "3: Add a topping" << endl;
        cout << "4: Delete a topping BROKEN" << endl;
        cout << "q: quit" << endl;
        cin >> input;
        
        if(input == '1'){
            displayAllToppings();
        }
        else if(input == '2'){
            
        }
        else if(input == '3'){
            
        }
        else if(input == '4'){
        }
    }
}

void AdminUI::displayAllToppings(){
    cout << "Here are all the toppings BROKEN" << endl;
}
