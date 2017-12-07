//
//  Pizza.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 28/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include <stdio.h>
#include "Pizza.hpp"
#include "ToppingRepo.hpp"
#include "BaseRepo.hpp"
#include "SizeRepo.hpp"
#include "Base.hpp"
#include "Size.hpp"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

Pizza::Pizza(){
    strcpy(name, "THIS SHOULD NEVER BE VISIBLE");
    price = 0;
}

void Pizza::createPizza(){
    
}


string Pizza::getName(){
    return name;
}
void Pizza::setName(char inName[MAXCHARSINPIZZANAME]){
    strcpy(name, inName);
}

int Pizza::getPrice(){
    return price;
}

Location Pizza::getLocation(){
    return locationOfPizza;
}

void Pizza::setPrice(int inPrice){
    price = inPrice;
}

void Pizza::setLocation(Location inlLocation){
    locationOfPizza = inlLocation;
}

status Pizza::getStatus(){
    return status;
}

void Pizza::setStatus(enum status inStatus){
    status = inStatus;
}



//Fall sem gefur notandanum kleift á því að velja botn fyrir pizzu tilvik.
void Pizza::chooseBase(){
    Base baseForPizza;
    
    cout << endl << "-----List of available bases-----" << endl;
    
    BaseRepo baseRepo;
    vector<Base> bases = baseRepo.getVectorOfBases();
    
    if(bases.size() < 1){
        
        cout << endl << "No bases available at this time." << endl;
        
    }
    else{
        for(int i = 0; i < bases.size(); i++){
            Base temp = bases.at(i);
            cout << "Base number " << i+1 << endl;
            cout << temp << endl;
        }
        int input = 0;
        cout << "Please choose a base for your pizza: ";
        cin >> input;
        baseForPizza = bases.at(input-1);
        
        baseOfPizza.setName(baseForPizza.getName());
        baseOfPizza.setPrice(baseForPizza.getPrice());
        price += baseForPizza.getPrice();
    }
    
}


//Fall sem gefur notandanum kleift á því að velja botn fyrir pizzu tilvik.
void Pizza::chooseSize(){
    Size sizeForPizza;
    
    cout << endl << "-----List of available sizes-----" << endl;
    SizeRepo sizeRepo;
    vector<Size> sizes = sizeRepo.getVectorOfSizes();
    
    if(sizes.size() < 1){
        
        cout << endl << "No sizes available at this time." << endl;
        
    }
    else{
        for(int i = 0; i < sizes.size(); i++){
            Size temp = sizes.at(i);
            cout << "Base number " << i+1 << endl;
            cout << temp << endl;
        }
        int input = 0;
        cout << "Please choose a size for your pizza: ";
        cin >> input;
        for(int i = 0; i < sizes.size(); i++){
            if(input == i+1){
                sizeForPizza = sizes.at(i);
            }
        }
        
        sizeOfPizza.setName(sizeForPizza.getName());
        sizeOfPizza.setPrice(sizeForPizza.getPrice());
        price += sizeForPizza.getPrice();
    }
}


void Pizza::chooseToppings(){
    Topping toppingsForPizza[MAXTOPPINGSONPIZZA];
    cout << endl << "-----List of available toppings-----" << endl;
    ToppingRepo tr;
    vector<Topping> allToppings = tr.getVectorOfToppings();
    
    if(allToppings.size() < 1){
        cout << endl << "No toppings available at this time." << endl;
    }
    else{
        for (int i = 0; i < allToppings.size(); i++) {
            cout << "Topping nr: " << i+1 << endl;
            cout << allToppings.at(i) << endl << endl;
        }
        int c = 0;
        while(true){
            //Veit ekki hvort þarf < eða <= hérna í næstu línu
            if(c <= MAXTOPPINGSONPIZZA){
                cout << "Enter an index of topping to add or 0 to exit: ";
                int input;
                cin >> input;
                if(input != 0){
                    this->toppings[c] = allToppings.at(input-1);
                    this->price += allToppings.at(input-1).getPrice();
                    c++;
                    cout << "Topping number " << input << " added" << endl;
                }else{
                    break;
                }
            }
        }
        this->toppingCount = c;
    }
}


//Þetta fall á að breyta nafninu á pizzunni í nafn á forminu
//STO ORG PP SKI SVE
void Pizza::fixName(){
    char tempName[MAXCHARSINPIZZANAME];
    strcpy(tempName, sizeOfPizza.getName());
    strcat(tempName, " ");
    strcat(tempName, baseOfPizza.getName());
    for (int i = 0; i < this->toppingCount; i++) {
        strcat(tempName, " ");
        strcat(tempName, toppings[i].getName());
    }
    strcpy(name, tempName);
}

ostream& operator << (ostream& out, const Pizza& pizza){
        out << pizza.name << TABSTRING << pizza.price << endl;
    return out;
}

//Það á eftir að bæta meira við!
//Leyfir notandanum að velja af lista botn pizzunar og stærð hennar.
istream& operator >> (istream& in, Pizza& pizza){
    
    pizza.chooseSize();
    pizza.chooseBase();
    pizza.chooseToppings();
    pizza.fixName();
   
    return in;
}

