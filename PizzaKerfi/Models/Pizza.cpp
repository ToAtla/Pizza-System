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

///Defult constructor that gives all the private variables a value of 0.

Pizza::Pizza(){
    strcpy(name, "THIS SHOULD NEVER BE VISIBLE");
    status = WAITING;
    price = 0;
}

///A constructor that takes in 3 parameters, an instance of Size, an instance of base and a instance of location
///and gives the private variables Size, base and location the values of the parameters.
Pizza::Pizza(Size size, Base base, Location location){
    sizeOfPizza = size;
    baseOfPizza = base;
    locationOfPizza = location;
    status = WAITING;
}

 ///Return the private variable name of the pizza.
string Pizza::getName(){
    return name;
}

///Takes in a character array and gives the private variable name the value of it.
void Pizza::setName(char inName[MAXCHARSINPIZZANAME]){
    strcpy(name, inName);
}

///Returns the value of the private variable price.
int Pizza::getPrice(){
    return price;
}

///Return the value of the private variable location.
Location Pizza::getLocation(){
    return locationOfPizza;
}

///Takes in an int as a parameter and gives the private variable price the value of it.
void Pizza::setPrice(int inPrice){
    price = inPrice;
}

///Takes in a Location as a parameter and gives the private variable locationOfPizza the value of it.
void Pizza::setLocation(Location inlLocation){
    locationOfPizza = inlLocation;
}

///Returns the value of the private variable status.
status Pizza::getStatus(){
    return status;
}

///Takes in a status as a parameter and gives the private variable status the value of it.
void Pizza::setStatus(enum status inStatus){
    status = inStatus;
}

///Returns the value of the private variable parentID.
int Pizza::getParentID(){
    return parentID;
}

///Takes in an int as a parameter and gives the private variable parentID the value of it.
void Pizza::setParentID(int inParentID){
    parentID = inParentID;
}

///Returns the value of the private variable base.
Base Pizza::getBase(){
    return baseOfPizza;
}

///Returns the value of the private variable size.
Size Pizza::getSize(){
    return sizeOfPizza;
}

///Returns a pointer to the private array toppings.
Topping* Pizza::getToppings(){
    return toppings;
}

///Return the value of the private variable toppingCount.
int Pizza::getToppingCount(){
    return toppingCount;
}

///Takes in an int as a parameter and gives the private variable toppingCount the value of it.
void Pizza::setToppingCount(int inToppingCount){
    toppingCount = inToppingCount;
}

///Overloads the ostream operator so when one uses the '<<' to print out the contents of an instance of Pizza.
ostream& operator << (ostream& out, const Pizza& pizza){
    Bizniz bizniz;
    string statusAndPriceString = bizniz.getStatusAndPriceCharArr(pizza);
    cout << setfill(' ');
    out << setw(SIZEOFSETW) << left << pizza.name << setfill(' ') <<  statusAndPriceString << endl;
    return out;
}

