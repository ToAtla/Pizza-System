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
    while(input != 'b'){
        cout << "1: fikta i toppings" << endl;
        cout << "b: back" << endl;
        cin >> input;
        
        if(input == '1'){
            displayToppingMenu();
        }
    }
}

void AdminUI::displayToppingMenu(){
    char input = '\0';
    while(input != 'b'){
        cout << "1: List toppings" << endl;
        cout << "2: Change a topping BROKEN" << endl;
        cout << "3: Add a topping" << endl;
        cout << "4: Delete a topping BROKEN" << endl;
        cout << "b: back" << endl;
        cin >> input;
        
        if(input == '1'){
            cout << endl << "-----List of all topings-----" << endl;
            displayAllToppings();
            cout << endl;
        }
        else if(input == '2'){
            
        }
        else if(input == '3'){
            addTopping();
        }
        else if(input == '4'){
        }
    }
}

void AdminUI::displayAllToppings(){
    ToppingRepo toppingRepo;
    vector<Topping> toppings = toppingRepo.getVectorOfToppings();
    for (int i = 0; i < toppings.size(); i++) {
        Topping temp = toppings.at(i);
        cout << temp << endl;
    }
}

void AdminUI::addTopping(){
    char input = 'y';
    
    while(input == 'y'){
        ToppingRepo toppingRepo;
        Topping temp;
        cin >> temp;
        toppingRepo.storeTopping(temp);
        cout << endl << "Do you want to add another topping? y/n" << endl;
        cin >> input;
        while(input != 'y' && input != 'n'){
            cout << endl << "Please enter either 'y' or 'n'" << endl;
            cin >> input;
        }
        cout << endl;
    }
}
