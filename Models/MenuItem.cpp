//
//  MenuItem.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/13/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "MenuItem.hpp"

MenuItem::MenuItem(){
    nameOfMenuItem[0] = '\0';
    price = 0;
    toppingCount = 0;
}

MenuItem::MenuItem(Topping toppings[], string name, int numberOfToppings, int price){
    
    toppingCount = numberOfToppings;
    
    for(int i = 0; i < toppingCount; i++){
        toppingsInMenuItem[i] = toppings[i];
    }
    
    strcpy(nameOfMenuItem, name.c_str());
    
    this->price = price;
    
}

char* MenuItem::getName(){
    return nameOfMenuItem;
}

void MenuItem::setName(char inName[MAXCHARSINPIZZANAME]){
    strcpy(nameOfMenuItem, inName);
}

int MenuItem::getPrice(){
    return price;
}

void MenuItem::setPrice(int inPrice){
    price = inPrice;
}

Topping* MenuItem::getToppings(){
    return toppingsInMenuItem;
}

int MenuItem::getToppingCount(){
    return toppingCount;
}

void MenuItem::setToppingCount(int inToppingCount){
    toppingCount = inToppingCount;
}

Topping MenuItem::getCertainTopping(int index){
    return toppingsInMenuItem[index];
}

ostream& operator << (ostream& out, const MenuItem&){
   
    
    return out;
}

