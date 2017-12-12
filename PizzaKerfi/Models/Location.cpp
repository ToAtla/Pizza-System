//
//  Location.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 29/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "Location.hpp"
#include "LocationRepo.hpp"
using namespace std;

///Defult constructor that gives all the private variables a value of 0.
Location::Location(){
    name[0] = '\0';
}

///A constructor that takes in a character array and an int as parameters and gives the private variables
///nane and price the values of them.
Location::Location(char inName[MAXCHARINLOCATIONNAME]){
    strcpy(name, inName);
    
}

///Returns the value of the private array name.
string Location::getLocation(){
    return name;
}

///Takes in a character array and gives the private array the value of is.
void Location::setName(char inName[30]){
    for(int i = 0; i < 30; i++){
    name[i] = inName[i];
    }
}

///Overloads the istream operator so one can use '>>' to input the contents of a Location instance.
istream& operator >> (istream& in, Location& location){
    cout << "Enter the location name: ";
    in >> location.name;

    return in;
}

///Overloads the ostream operator so one can use '<<' to print out the contents of a Location instance.
ostream& operator << (ostream& out, const Location& location){

    out << location.name;

    return out;
}
