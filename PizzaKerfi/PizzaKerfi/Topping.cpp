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

//Defult constructor.
Topping::Topping(){
    price = 0;
    name[0] = '\0';
}

//Returns the private variable name.
char* Topping::getName(){
    return name;
}

//Take in a character array as a paramaeter and puts it into the private variable name.
void Topping::setName(char inName[MAXCHARINTOP]){
    for(int i = 0; i < MAXCHARINTOP; i++){
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

//Takes in a bool parameter and gives the private variable verbose the value of the parameter.
void Topping::setVerbose(bool v){
    verbose = v;
}


//Overloads the ostream operator so one can use the '<<' operator to print the contents of a topping instance.
ostream& operator << (ostream& out, const Topping& topping){
    if(topping.verbose)
        out << "Topping: ";
    out << topping.name << endl;
    
    if(topping.verbose)
        out << "Price: ";
    out << topping.price << endl;
    
    return out;
}

//Overloads the ostream operator so one can use the '>>' operator to input the contents of a topping instance.
istream& operator >> (istream& in, Topping& topping){
    
    if(topping.verbose)
        cout << "Enter topping name: ";
    in >> topping.name;
    
    if(topping.verbose)
        cout << "Enter topping price: ";
    in >> topping.price;
    
    return in;
}
