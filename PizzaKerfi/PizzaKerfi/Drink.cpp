//
//  Drink.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/30/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Drink.hpp"
#include <iomanip>



//Defult constuctor.
Drink::Drink(){
    price = 0;
    name[0] = '\0';
}

Drink::Drink(char inName[MAXCHARINDRINKNAME], int price){
    
    this->price = price;
    
    strcpy(name, inName);
    
}

//Returns the price of the drink.
int Drink::getPrice(){
    
    return price;
}

//Takes in a parameter and gives the private variable price the value of the parameter
void Drink::setPrice(int inPrice){
    
    price = inPrice;
}


//Returns the private variable name.
char* Drink::getName(){
    
    return name;
}

//Take in a character array as a paramaeter and puts it into the private variable name.
void Drink::setName(char inName[]){
    for(int i = 0; i < MAXCHARINDRINKNAME; i++){
        name[i] = inName[i];
    }
}

//Overloads the ostream operator so one can use the '<<' operator to print the contents of a Drink instance.
ostream& operator << (ostream& out, const Drink& drink){
    
    
    out << drink.name << TABSTRING << drink.price;
    return out;
}

//Overloads the ostream operator so one can use the '>>' operator to input the contents of a Drink Side.
istream& operator >> (istream& in, Drink& drink){
    cout << "Enter drink name: ";
    in >> drink.name;
    cout << "Enter drink price: ";
    in >> drink.price;
    
    return in;
}
