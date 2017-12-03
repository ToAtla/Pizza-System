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
int Size::getPrice(){
    return price;
}

void Size::setPrice(int inPrice){
    price = inPrice;
}
void Size::setVerbose(bool v){
    verbose = v;
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
    
    if(size.verbose)
        cout << "Enter size name: ";
    in >> size.name;
    
    if(size.verbose)
        cout << "Enter side price: ";
    in >> size.price;
    
    return in;
}

ostream& operator << (ostream& out, const Size& size){
    
    if(size.verbose)
        out << "Size: ";
    out << size.name << endl;
    
    if(size.verbose)
        out << "Price: ";
    out << size.price << endl;
    
    return out;
}

