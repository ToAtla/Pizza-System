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


Location::Location(){
    name[0] = '\0';
}

void Location::setVerbose(bool v){
    verbose = v;
}
string Location::getLocation(){
    return name;
}
void Location::setName(char inName[MAXCHARINLOC]){
    for(int i = 0; i < MAXCHARINLOC; i++){
    name[i] = inName[i];
    }
}

istream& operator >> (istream& in, Location& location){
    if(location.verbose)
        cout << "Enter the location name: ";
    in >> location.name;

return in;
}

ostream& operator << (ostream& out, const Location& location){
    if(location.verbose)
        out <<  "Location: ";
    out << location.name << endl;

return out;
}
