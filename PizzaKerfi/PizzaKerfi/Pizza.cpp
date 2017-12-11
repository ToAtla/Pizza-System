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
#include "Bizniz.hpp"

using namespace std;

Pizza::Pizza(){
    strcpy(name, "THIS SHOULD NEVER BE VISIBLE");
    status = WAITING;
    price = 0;
}

Pizza::Pizza(Size size, Base base, Location location){
    sizeOfPizza = size;
    baseOfPizza = base;
    locationOfPizza = location;
    status = WAITING;
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
int Pizza::getParentID(){
    return parentID;
}
void Pizza::setParentID(int inParentID){
    parentID = inParentID;
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
    cout << setfill(' ');
    out << setw(SIZEOFSETW) << left << pizza.name << setfill(' ') <<  statusAndPriceString << endl;
    return out;
}

