//
//  Side.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/30/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Side.hpp"

const string tabString = "\t\t\t\t\t\t\t\t";

//Defult constructor.
Side::Side(){
    price = 0;
    name[0] = '\0';
}

//Returns the price of the side.
int Side::getPrice(){
    
    return price;
}

//Takes in a parameter and gives the private variable price the value of the parameter
void Side::setPrice(int inPrice){
    
    price = inPrice;
}

//Takes in a bool parameter and gives the private variable verbose the value of the parameter.
void Side::setVerbose(bool v){
 
    verbose = v;
}

//Returns the private variable name.
char* Side::getName(){
    
    return name;
}

//Take in a character array as a paramaeter and puts it into the private variable name.
void Side::setName(char inName[]){
    for(int i = 0; i < MAXCHARINSIDE; i++){
        name[i] = inName[i];
    }
}

//Overloads the ostream operator so one can use the '<<' operator to print the contents of a topping instance.
ostream& operator << (ostream& out, const Side& side){
    
    if(side.verbose){
        out << side.name << tabString << side.price;
    }else{
        out << side.name << endl;
        out << side.price << endl;
    }
    return out;
}

//Overloads the ostream operator so one can use the '>>' operator to input the contents of a topping Side.
istream& operator >> (istream& in, Side& side){
    
    if(side.verbose)
        cout << "Enter side name: ";
    in >> side.name;
    
    if(side.verbose)
        cout << "Enter side price: ";
    in >> side.price;
    
    return in;
}
