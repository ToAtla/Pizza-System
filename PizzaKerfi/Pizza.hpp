//
//  Pizza.hpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 28/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef Pizza_hpp
#define Pizza_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Topping.hpp"

using namespace std;

const int MAXTOPPINGSONPIZZA = 16;
const int MAXCHARSINPIZZANAME = 100;
const int MAXCHARSINPIZZASIZE = 3;

class Pizza{

public:
    
    Pizza();
    Pizza(char inSize[MAXCHARSINPIZZASIZE], Topping inToppings[], int toppingsToAdd);
    
    bool getVerbose();
    void setVerbose(bool v);
    /*
    string getName();
    void setName(string inName);

    int getPrice();
    void setPrice(int inPrice);
    */
    friend ostream& operator << (ostream& out, const Pizza&);
    friend istream& operator >> (istream& in, Pizza&);
private:
    char name[MAXCHARSINPIZZANAME];
    int price;
    char size[MAXCHARSINPIZZASIZE];
    Topping toppings[MAXTOPPINGSONPIZZA];
    int toppingCount;
    bool verbose = true;
};
#endif /* Pizza_hpp */
