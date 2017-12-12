//
//  Side.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/30/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef Side_hpp
#define Side_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Global.hpp"

using namespace std;



class Side{

public:
    Side();
    ///Defult constructor that gives all the private variables a value of 0.
    Side(char inName[MAXCHARINSIDENAME], int price);
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
    void setStatus(status inStatus);
    ///Takes in a Status a parameter and give the private variable status the value of it.
    status getStatus();
    ///Returns the value of the private variable status.

    friend istream& operator >> (istream& in, Side& side);
    ///Overloads the istream operator so one can use '>>' to input the contents of a Side instance.
    friend ostream& operator << (ostream& out, const Side& side);
    ///Overloads the ostream operator so one can use '<<' to print out the contents of a Side instance.
private:
    char name[MAXCHARINSIDENAME];
    int price;
    status status;
};



#endif /* Side_hpp */
