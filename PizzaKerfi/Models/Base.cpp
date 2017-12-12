//
//  Base.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/1/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Base.hpp"

///Defult constructor that gives all the private variables a value of 0.
Base::Base(){
    name[0] = '\0';
    price = 0;
}

///A constructor that takes in a character array and an int as parameters and gives the private variables
///nane and price the values of them.
Base::Base(char inName[MAXCHARINBASENAME], int inPrice){
    
    price = inPrice;
    
    strcpy(name, inName);
    
}

///Returns the value of the private variable price.
int Base::getPrice(){
    return price;
}

 ///Takes in an int as a parameter and gives the private variable price the value of it.
void Base::setPrice(int inPrice){
    price = inPrice;
}

///Returns a pointer to the private array name.
char* Base::getName(){
    return name;
}

///Takes in a character array and gives the private array the value of is.
void Base::setName(char inName[]){
    
    for(int i = 0; i < MAXCHARINBASENAME; i++){
        name[i] = inName[i];
    }
    
}

///Overloads the istream operator so one can use '>>' to input the contents of a Base instance.
istream& operator >> (istream& in, Base& base){
    
    cout << "Enter base name: ";
    in >> base.name;
    cout << "Enter side price: ";
    in >> base.price;
    return in;
}

///Overloads the ostream operator so one can use '<<' to print out the contents of a Base instance.
ostream& operator << (ostream& out, const Base& base){
    out << base.name << TABSTRING << base.price << endl;
    
    return out;
}
