//
//  AdminUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "AdminUI.hpp"
#include "ToppingRepo.hpp"
#include <fstream>
#include <iostream>

using namespace std;

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
            
            //BREYTA ÞESSU ASAP ÞETTA ER BRÁÐABIRGÐA
            addToppingVirkni();
        }
        else if(input == '4'){
        }
    }
}

void AdminUI::displayAllToppings(){
    ToppingRepo toppingRepo;
    vector<Topping> toppings = toppingRepo.getVectorOfToppings();
    for (int i = 0; i < toppings.size(); i++) {
        cout << "Hér er ég eftir debug" << endl;
        Topping temp = toppings.at(i);
        cout << temp << endl;
    }
}

void AdminUI::addToppingVirkni(){
    ToppingRepo toppingRepo;
    Topping temp;
    cin >> temp;
    toppingRepo.storeTopping(temp);
    
}
