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

string Location::getLocation(){
    return name;
}
void Location::setName(char inName[30]){
    for(int i = 0; i < 30; i++){
    name[i] = inName[i];
    }
}

istream& operator >> (istream& in, Location& location){
    
    in >> location.name;

return in;
}

ostream& operator << (ostream& out, const Location& location){

    out << location.name;

return out;
}
