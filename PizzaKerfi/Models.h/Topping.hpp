//
//  Topping.hpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 28/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef Topping_hpp
#define Topping_hpp

#include <stdio.h>
#include <string>
#include "Global.hpp"

using namespace std;

class Topping {
    public:
        Topping();
        ///Defult constructor that gives all the private variables a value of 0.
        Topping(char inName[MAXCHARINTOPPINGNAME], int inPrice);
        ///A constructor that takes in a character array and an int as parameters and gives the private variables
        ///nane and price the values of them.
        int getPrice();
        ///Returns the value of the private variable price.
        void setPrice(int inPrice);
        ///Takes in an int as a parameter and gives the private variable price the value of it.
        char* getName();
        ///Returns a pointer to the private array name.
        void setName(char inName[]);
        ///Takes in a character array and gives the private array the value of is.
        friend istream& operator >> (istream& in, Topping& topping);
        ///Overloads the istream operator so one can use '>>' to input the contents of a Topping instance.
        friend ostream& operator << (ostream& out, const Topping& topping);
        ///Overloads the ostream operator so one can use '<<' to print out the contents of a Topping instance.
    private:
        char name[30];
        int price;
};

#endif /* Topping_hpp */
