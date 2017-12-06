//
//  Drink.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/30/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Drink.hpp"
const string tabString = "\t\t\t\t\t\t\t\t\t\t\t";

//Defult constuctor.
Drink::Drink(){
    price = 0;
    name[0] = '\0';
}

//Returns the price of the drink.
int Drink::getPrice(){
    
    return price;
}

//Takes in a parameter and gives the private variable price the value of the parameter
void Drink::setPrice(int inPrice){
    
    price = inPrice;
}

//Takes in a bool parameter and gives the private variable verbose the value of the parameter.
void Drink::setVerbose(bool v){
    
    verbose = v;
}

//Returns the private variable name.
char* Drink::getName(){
    
    return name;
}

//Take in a character array as a paramaeter and puts it into the private variable name.
void Drink::setName(char inName[]){
    for(int i = 0; i < MAXCHARINDRINKNAME; i++){
        name[i] = inName[i];
    }
}

//Overloads the ostream operator so one can use the '<<' operator to print the contents of a Drink instance.
ostream& operator << (ostream& out, const Drink& drink){

    if(drink.verbose){
        out << drink.name << tabString << drink.price;
    }else{
        out << drink.name << endl;
        out << drink.price << endl;
    }
    
    return out;
}

//Overloads the ostream operator so one can use the '>>' operator to input the contents of a Drink Side.
istream& operator >> (istream& in, Drink& drink){
    
    if(drink.verbose)
        cout << "Enter drink name: ";
    in >> drink.name;
    
    if(drink.verbose)
        cout << "Enter drink price: ";
    in >> drink.price;
    
    return in;
}
