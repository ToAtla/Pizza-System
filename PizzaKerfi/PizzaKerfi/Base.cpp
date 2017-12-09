//
//  Base.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/1/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Base.hpp"

Base::Base(){
    name[0] = '\0';
    price = 0;
}

Base::Base(string name, int inPrice){
    
    price = inPrice;
    
    for(int i = 0; i < name.length(); i++){
        this->name[i] = name[i];
    }
    
}

int Base::getPrice(){
    return price;
}

void Base::setPrice(int inPrice){
    price = inPrice;
}

char* Base::getName(){
    return name;
}

void Base::setName(char inName[]){
    
    for(int i = 0; i < MAXCHARSINBASENAME; i++){
        name[i] = inName[i];
    }
    
}

istream& operator >> (istream& in, Base& base){
    
    cout << "Enter base name: ";
    in >> base.name;
    cout << "Enter side price: ";
    in >> base.price;
    return in;
}

ostream& operator << (ostream& out, const Base& base){
    out << base.name << TABSTRING << base.price << endl;
    
    return out;
}
