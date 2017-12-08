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
#include "Size.hpp"
#include "Base.hpp"
#include "Location.hpp"

using namespace std;
//MUNA AÐ SKILJA EFTIR PLÁSS FYRIR NULLCHARACTER Í LOKIN 
const int MAXTOPPINGSONPIZZA = 16;
const int MAXCHARSINPIZZANAME = 100;
const int MAXCHARSINPIZZASIZE = 4;
const int MAXPIZZASINPIZZAFILE = 20;

class Pizza{

public:
        
    Pizza();
    void createPizza();
    
    
    string getName();
    void setName(char inName[MAXCHARSINPIZZANAME]);

    int getPrice();
    Location getLocation();
    void setPrice(int inPrice);
    void setLocation(Location inLocation);
    
    status getStatus();
    void setStatus(status inStatus);
    void chooseBase();
    void chooseSize();
    void chooseToppings();
    Base getBase();
    Size getSize();
    Topping* getToppings();
    int getToppingCount();
    
    void fixName();
    friend ostream& operator << (ostream& out, const Pizza&);
    friend istream& operator >> (istream& in, Pizza&);
private:
    Topping toppings[MAXTOPPINGSONPIZZA];
    Size sizeOfPizza;
    Base baseOfPizza;
    Location locationOfPizza;
    char name[MAXCHARSINPIZZANAME];
    int price;
    int toppingCount;
    status status;
    
};
#endif /* Pizza_hpp */
