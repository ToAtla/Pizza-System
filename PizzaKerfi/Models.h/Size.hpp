//
//  Size.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/1/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef Size_hpp
#define Size_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Global.hpp"

using namespace std;



class Size{
    
    public:
        Size();
        ///Defult constructor that gives all the private variables a value of 0.
        Size(char inName[MAXCHARINSIDENAME], int price);
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
        friend istream& operator >> (istream& in, Size& size);
        ///Overloads the istream operator so one can use '>>' to input the contents of a Size instance.
        friend ostream& operator << (ostream& out, const Size& size);
        ///Overloads the ostream operator so one can use '<<' to print out the contents of a Size instance.
    private:
        char name[MAXCHARINSIZENAME];
        int price;
};

#endif /* Size_hpp */
