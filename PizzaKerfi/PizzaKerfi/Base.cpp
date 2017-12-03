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
int Base::getPrice(){
    return price;
}

void Base::setPrice(int inPrice){
    price = inPrice;
}

void Base::setVerbose(bool v){
    verbose = v;
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
    
    if(base.verbose)
        cout << "Enter base name: ";
    in >> base.name;
    
    if(base.verbose)
        cout << "Enter side price: ";
    in >> base.price;
    return in;
}

ostream& operator << (ostream& out, const Base& base){
    
    if(base.verbose)
        out << "Base: ";
    out << base.name << endl;
    
    if(base.verbose)
        out << "Price: ";
    out << base.price << endl;
    
    return out;
}
