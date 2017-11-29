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
    name = "";
}
string Topping::getName(){
    return name;
}
void Topping::setName(string inName){
    name = inName;
}

int Topping::getPrice(){
    return price;
}
void Topping::setPrice(int inPrice){
    price = inPrice;
}

ostream& operator << (ostream& out, const Topping& topping){
    out << topping.name << endl << topping.price;
    return out;
}
istream& operator >> (istream& in, Topping& topping){
    in >> topping.name;
    in >> topping.price;
    return in;
}
