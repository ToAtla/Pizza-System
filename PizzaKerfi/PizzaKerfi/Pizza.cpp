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
#include "Bizniz.hpp"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

Pizza::Pizza(){
    strcpy(name, "THIS SHOULD NEVER BE VISIBLE");
    status = WAITING;
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
Base Pizza::getBase(){
    return baseOfPizza;
}
Size Pizza::getSize(){
    return sizeOfPizza;
}
Topping* Pizza::getToppings(){
    return toppings;
}
int Pizza::getToppingCount(){
    return toppingCount;
}
void Pizza::setToppingCount(int inToppingCount){
    toppingCount = inToppingCount;
}


ostream& operator << (ostream& out, const Pizza& pizza){
    Bizniz bizniz;
    string statusAndPriceString = bizniz.getStatusAndPriceCharArr(pizza);
    out << setw(SIZEOFSETW) << left << pizza.name << statusAndPriceString << endl;
    return out;
}

istream& operator >> (istream& in, Pizza& pizza){
    Bizniz bizniz;
    bizniz.chooseSizeForPizza(pizza);
    bizniz.chooseBaseForPizza(pizza);
    bizniz.chooseToppingsOnPizza(pizza);
    bizniz.fixNameOfPizza(pizza);
   
    return in;
}

