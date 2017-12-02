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
const int BASICCOST = 1000;

using namespace std;

Pizza::Pizza(){
    
    strcpy(name, "Margarita");
    price = BASICCOST;
}

Pizza::Pizza(char inSize[MAXCHARSINPIZZASIZE], Topping inToppings[], int toppingsToAdd){
    strcpy(size, inSize);
    price = 9999;
    if(toppingsToAdd > MAXTOPPINGSONPIZZA){
        cout << "Error: Topping amount exceeds max allowed number of toppings" << endl;
    }else{
        for (int i = 0; i < toppingsToAdd; i++) {
            inToppings[i] = toppings[i];
        }
        toppingCount = toppingsToAdd;
    }
}

/*
string Pizza::getName(){
    return name;
}
void Pizza::setName(string inName){
    name = inName;
}

int Pizza::getPrice(){
    return price;
}
void Pizza::setPrice(int inPrice){
    price = inPrice;
}
*/

//Fall sem gefur notandanum kleift á því að velja botn fyrir pizzu tilvik.
void Pizza::chooseBase(){
    Base baseForPizza;
    Size sizaForPizza;
    
    cout << endl << "-----List of available bases-----" << endl;
    BaseRepo baseRepo;
    vector<Base> bases = baseRepo.getVectorOfBases();
    for(int i = 0; i < bases.size(); i++){
        Base temp = bases.at(i);
        cout << "Base number " << i+1 << endl;
        cout << temp << endl;
    }
    int input = 0;
    cout << "Please choose a base for you pizza:" << endl;
    cin >> input;
    for(int i = 0; i < bases.size(); i++){
        if(input == i+1){
            baseForPizza = bases.at(i);
        }
    }
    
    baseOfPizza.setName(baseForPizza.getName());
    baseOfPizza.setPrice(baseForPizza.getPrice());
}


ostream& operator << (ostream& out, const Pizza& pizza){
    if(pizza.verbose){
        out << "Name: " << pizza.name << endl;
        out << "Price: " << pizza.price << endl;
    }else{
        out << pizza.name << endl;
        out << pizza.price << endl;
    }
    return out;
}

//Það á eftir að bæta meira við!
//Leyfir notandanum að velja af lista botn pizzunar og stærð hennar.
istream& operator >> (istream& in, Pizza& pizza){
    
    pizza.chooseBase();
    
    
    return in;
}
