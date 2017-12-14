//
//  MenuItem.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/13/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef MenuItem_hpp
#define MenuItem_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Topping.hpp"
#include "Size.hpp"
#include "Base.hpp"
#include "Location.hpp"
#include "Global.hpp"

using namespace std;

class MenuItem{
    
public:
    MenuItem();
    ///Defult constructor that gives all the private variables a value of 0.
    MenuItem(Topping toppings[], string name, int numberOfToppings, int price);
    
    char* getName();
    ///Return the private variable name of the pizza.
    void setName(char inName[MAXCHARSINPIZZANAME]);
    ///Takes in a character array and gives the private variable name the value of it.
    int getPrice();
    ///Returns the value of the private variable price.
    void setPrice(int inPrice);
    ///Takes in an int as a parameter and gives the private variable price the value of it.
    Topping* getToppings();
    ///Returns a pointer to the private array toppings.
    int getToppingCount();
    ///Return the value of the private variable toppingCount.
    void setToppingCount(int inToppingCount);
    ///Takes in an int as a parameter and gives the private variable toppingCount the value of it.
    Topping getCertainTopping(int index);
    friend ostream& operator << (ostream& out, const MenuItem&);
    ///Overloads the ostream operator so when one uses the '<<' to print out the contents of an instance of Pizza.
private:
    Topping toppingsInMenuItem[MAXTOPPINGSONPIZZA];
    char nameOfMenuItem[MAXCHARSINPIZZANAME];
    int price;
    int toppingCount;
};



#endif /* MenuItem_hpp */
