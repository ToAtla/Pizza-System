//
//  Pizza.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 28/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Pizza.hpp"

Pizza::Pizza(){
    name = "Margarita";
    price = 1000;
}
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
