//
//  Location.hpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 29/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef Location_hpp
#define Location_hpp

#include <stdio.h>
#include <string>
#include "Global.hpp"

using namespace std;

class Location{
    
    public:
        Location();
        ///Defult constructor that gives all the private variables a value of 0.
        Location(char inName[MAXCHARINLOCATIONNAME]);
        ///A constructor that takes in a character array and an int as parameters and gives the private variables
        ///nane and price the values of them.
        string getLocation();
        ///Returns the value of the private array name.
        void setName(char inName[]);
        ///Takes in a character array and gives the private array the value of is.
        friend istream& operator >> (istream& in, Location& Location);
        ///Overloads the istream operator so one can use '>>' to input the contents of a Location instance.
        friend ostream& operator << (ostream& out, const Location& Location);
        ///Overloads the ostream operator so one can use '<<' to print out the contents of a Location instance.
    private:
        char name[MAXCHARINLOCATIONNAME];
};

#endif /* Location_hpp */
