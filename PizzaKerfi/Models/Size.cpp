//
//  Size.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/1/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Size.hpp"

///Defult constructor that gives all the private variables a value of 0.
Size::Size(){
    name[0] = '\0';
    price = 0;
}

///A constructor that takes in a character array and an int as parameters and gives the private variables
///nane and price the values of them.
Size::Size(char inName[MAXCHARINSIZENAME], int price){
    
    this->price = price;
    
    strcpy(name, inName);
    
}

///Returns the value of the private variable price.
int Size::getPrice(){
    return price;
}

 ///Takes in an int as a parameter and gives the private variable price the value of it.
void Size::setPrice(int inPrice){
    price = inPrice;
}

///Returns a pointer to the private array name.
char* Size::getName(){
    return name;
}

///Takes in a character array and gives the private array the value of is.
void Size::setName(char inName[]){
    for(int i = 0; i < MAXCHARINSIZENAME; i++)
    {
        name[i] = inName[i];
    }
}

///Overloads the istream operator so one can use '>>' to input the contents of a Size instance.
istream& operator >> (istream& in, Size& size){
    cout << "Enter size name: ";
    in >> size.name;
    cout << "Enter side price: ";
    in >> size.price;
    
    return in;
}

///Overloads the ostream operator so one can use '<<' to print out the contents of a Size instance.
ostream& operator << (ostream& out, const Size& size){
    out << size.name << TABSTRING << size.price << endl;
    return out;
}

