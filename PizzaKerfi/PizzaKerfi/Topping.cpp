//
//  Topping.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 28/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Topping.hpp"
//using namespace std;
#include <iostream>
#include <string>

//Defult constructor.
Topping::Topping(){
    price = 0;
    name[0] = '\0';
}

Topping::Topping(string inName, int inPrice){
    this->price = inPrice;
    
    for(int i = 0; i < inName.length(); i++){
        name[i] = inName[i];
    }
}

//Returns the private variable name.
char* Topping::getName(){
    return name;
}

//Take in a character array as a paramaeter and puts it into the private variable name.
void Topping::setName(char inName[MAXCHARSINTOPPINGNAME]){
    for(int i = 0; i < MAXCHARSINTOPPINGNAME; i++){
    name[i] = inName[i];
    }
}

//Returns the price of the topping.
int Topping::getPrice(){
    return price;
}

//Takes in a parameter and gives the private variable price the value of the parameter
void Topping::setPrice(int inPrice){
    price = inPrice;
}
    

//Overloads the ostream operator so one can use the '<<' operator to print the contents of a topping instance.
ostream& operator << (ostream& out, const Topping& topping){
    out << topping.name << TABSTRING << topping.price << endl;
    
    return out;
}

//Overloads the ostream operator so one can use the '>>' operator to input the contents of a topping instance.
istream& operator >> (istream& in, Topping& topping){
    
    cout << "Enter topping name: ";
    in >> topping.name;
    cout << "Enter topping price: ";
    in >> topping.price;
    
    return in;
}
