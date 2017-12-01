//
//  Pizza.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 28/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include <stdio.h>
#include "Pizza.hpp"
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

istream& operator >> (istream& in, Pizza& pizza){
    /*
    if(pizza.verbose){
        cout << "Enter Size: ";
        in >> pizza.size;
        int numOfToppings = 0;
        in >> numOfToppings;
        for (int i = 0; i < numOfToppings; i++) {
            Topping tempTopping;
            in >> tempTopping;
            pizza.toppings.push_back(tempTopping);
        }
    }else{
        in >> pizza.size;
        in >> pizza.name;
    }
     */
    
    return in;
}
