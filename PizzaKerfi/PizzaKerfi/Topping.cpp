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

Topping::Topping(){
    price = 0;
    name[0] = '\0';
}

char* Topping::getName(){
    return name;
}

void Topping::setName(char inName[MAXCHARINTOP]){
    for(int i = 0; i < MAXCHARINTOP; i++){
    name[i] = inName[i];
    }
}

int Topping::getPrice(){
    return price;
}

void Topping::setPrice(int inPrice){
    price = inPrice;
}

void Topping::setVerbose(bool v){
    verbose = v;
}

ostream& operator << (ostream& out, const Topping& topping){
    if(topping.verbose)
        out << "Topping: ";
    out << topping.name << endl;
    
    if(topping.verbose)
        out << "Price: ";
    out << topping.price << endl;
    
    
    return out;
}

istream& operator >> (istream& in, Topping& topping){
    if(topping.verbose)
        cout << "Enter topping name: ";
    in >> topping.name;
    
    if(topping.verbose)
        cout << "Enter topping price: ";
    in >> topping.price;
    return in;
}
