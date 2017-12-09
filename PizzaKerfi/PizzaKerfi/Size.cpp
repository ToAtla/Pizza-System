//
//  Size.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/1/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Size.hpp"

Size::Size(){
    name[0] = '\0';
    price = 0;
}

Size::Size(string name, int price){
    
    this->price = price;
    
    for(int i = 0; i < name.length(); i++){
        this->name[i] = name[i];
    }
    
}

int Size::getPrice(){
    return price;
}

void Size::setPrice(int inPrice){
    price = inPrice;
}

char* Size::getName(){
    return name;
}

void Size::setName(char inName[]){
    for(int i = 0; i < MAXCHARINSIZENAME; i++)
    {
        name[i] = inName[i];
    }
}

istream& operator >> (istream& in, Size& size){
    cout << "Enter size name: ";
    in >> size.name;
    cout << "Enter side price: ";
    in >> size.price;
    
    return in;
}

ostream& operator << (ostream& out, const Size& size){
    out << size.name << TABSTRING << size.price << endl;
    return out;
}

