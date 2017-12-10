//
//  Side.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/30/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Side.hpp"

//Defult constructor.
Side::Side(){
    price = 0;
    name[0] = '\0';
}

Side::Side(string name, int price){
    
    this->price = price;
    
    for(int i = 0; i < name.length(); i++){
        this->name[i] = name[i];
    }
    
}

//Returns the price of the side.
int Side::getPrice(){
    
    return price;
}

//Takes in a parameter and gives the private variable price the value of the parameter
void Side::setPrice(int inPrice){
    
    price = inPrice;
}

//Returns the private variable name.
char* Side::getName(){
    
    return name;
}

//Take in a character array as a paramaeter and puts it into the private variable name.
void Side::setName(char inName[]){
    for(int i = 0; i < MAXCHARINSIDENAME; i++){
        name[i] = inName[i];
    }
}

void Side::setStatus(enum status inStatus){
    status = inStatus;
}
status Side::getStatus(){
    return status;
}

//Overloads the ostream operator so one can use the '<<' operator to print the contents of a topping instance.
ostream& operator << (ostream& out, const Side& side){
    
    out << side.name << TABSTRING << side.price;
    
    return out;
}

//Overloads the ostream operator so one can use the '>>' operator to input the contents of a topping Side.
istream& operator >> (istream& in, Side& side){
    
    cout << "Enter side name: ";
    in >> side.name;
    cout << "Enter side price: ";
    in >> side.price;
    
    return in;
}
