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
    
    //Prentar út valmynd sem býður notandanum að velja það sem hann vill fikta í.
    char input = 0;
    while(input != 'b'){
        cout << "1: Add/change the topping list" << endl;
        cout << "2: Add/change the location list" << endl;
        cout << "b: back" << endl;
        cin >> input;
        cout << endl;
        
        if(input == '1'){
            displayToppingMenu();
        }
    }
}

void AdminUI::displayToppingMenu(){
    //Prentar út valmynd sem býður notandanum uppá að velja það sem hann vill gera með topping listann.
    
    char input = '\0';
    while(input != 'b'){
        cout << "1: List toppings" << endl;
        cout << "2: Change a topping" << endl;
        cout << "3: Add a topping" << endl;
        cout << "4: Remove a topping" << endl;
        cout << "b: back" << endl;
        cin >> input;
        cout << endl;
        
        if(input == '1'){
            cout << endl << "-----List of all topings-----" << endl;
            displayAllToppings();
            cout << endl;
        }
        else if(input == '2'){
            changeTopping();
        }
        else if(input == '3'){
            addTopping();
        }
        else if(input == '4'){
            removeTopping();
        }
    }
}

void AdminUI::displayAllToppings(){
    //Prentar út lista yfir öll álegg.
    ToppingRepo toppingRepo;
    vector<Topping> toppings = toppingRepo.getVectorOfToppings();
    for (int i = 0; i < toppings.size(); i++) {
        Topping temp = toppings.at(i);
        cout << temp << endl;
    }
}

void AdminUI::addTopping(){
    
    //Bætir við áleggi á listann.
    char input = 'y';
    
    while(input == 'y'){
        ToppingRepo toppingRepo;
        Topping temp;
        cin >> temp;
        toppingRepo.storeTopping(temp);
        cout << endl << "Do you want to add another topping? y/n" << endl;
        cin >> input;
        while(input != 'y' && input != 'n'){
            cout << endl << "Please enter either 'y' or 'n' " << endl;
            cin >> input;
        }
        cout << endl;
    }
}

void AdminUI::changeTopping(){
    
    //Gerir notandanum kleift að velja alegg af listanum og nafninu og verðinu á því.
    
    ToppingRepo toppingRepo;
    vector<Topping> toppings = toppingRepo.getVectorOfToppings();
    cout << endl;
    
    char choice = 'y';
    
    while(choice == 'y')
    {
        for(int i = 0; i < toppings.size(); i++){
            Topping temp = toppings.at(i);
            cout << "Topping number: " << i+1 << endl;
            cout <<  temp << endl;
        }
        int input = 0;
        cout << "Choose a topping to change: ";
        cin >> input;
        
        for(int i = 0; i < toppings.size(); i++){
            if(input == i+1){
                cin >> toppings.at(i);
            }
        }
        toppingRepo.storeVectorOfToppings(toppings);
        cout << endl << "Topping changed" << endl << endl;
        cout << "do you want to change another topping: y/n ";
        cin >> choice;
        cout << endl;
        while(choice != 'y' && choice != 'n'){
            cout << "Please enter either 'y' or 'n' ";
            cin >> choice;
            cout << endl;
        }
    }
    
}

void AdminUI::removeTopping()
{
    
    //Gerir notandanum kleift að velja álegg af listanum og eyða því.
    ToppingRepo toppingRepo;
    vector<Topping> toppings = toppingRepo.getVectorOfToppings();
    cout << endl;
    
    char choice = 'y';
    
    while(choice == 'y'){
    for(int i = 0; i < toppings.size(); i++){
        Topping temp = toppings.at(i);
        cout << "Topping number: " << i+1 << endl;
        cout <<  temp << endl;
    }
        
    int input = 0;
    cout << "Choose a topping to remove: ";
    cin >> input;
        
    for(int i = 0; i < toppings.size(); i++){
        if(input == i+1){
            toppings.erase(toppings.begin() + i);
        }
    }
    toppingRepo.storeVectorOfToppings(toppings);
    cout << endl << "Topping removed" << endl << endl;
    cout << "do you want to change another topping: y/n ";
    cin >> choice;
    cout << endl;
    while(choice != 'y' && choice != 'n'){
        cout << "Please enter either 'y' or 'n' ";
        cin >> choice;
        cout << endl;
    }
    }
}
