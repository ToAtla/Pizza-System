//
//  Pizza.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 28/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Pizza.hpp"
#include <iostream>
const int BASICCOST = 1000;

using namespace std;

Pizza::Pizza(){
    name = "Margarita";
    price = BASICCOST;
}

Pizza::Pizza(string inSize, vector<Topping> inToppings){
    name = inSize;
    price = BASICCOST;
    for (int i = 0; i < inToppings.size(); i++) {
        name = name + inToppings.at(i).getName() + " ";
        price += inToppings.at(i).getPrice();
    }
    size = inSize;
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
    return in;
}
