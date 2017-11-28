//
//  Topping.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 28/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Topping.hpp"

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
