//
//  MenuItem.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/13/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "MenuItem.hpp"

MenuItem::MenuItem(){
    name[0] = '\0';
    price = 0;
    toppingCount = 0;
}

string MenuItem::getName(){
    return name;
}

void MenuItem::setName(char inName[MAXCHARSINPIZZANAME]){
    strcpy(name, inName);
}

int MenuItem::getPrice(){
    return price;
}

void MenuItem::setPrice(int inPrice){
    price = inPrice;
}

Topping* MenuItem::getToppings(){
    return toppings;
}

int MenuItem::getToppingCount(){
    return toppingCount;
}

void MenuItem::setToppingCount(int inToppingCount){
    toppingCount = inToppingCount;
}

ostream& operator << (ostream& out, const MenuItem&){
   
    
    return out;
}

