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
#include "Global.hpp"

using namespace std;


class Pizza{

public:
        
    Pizza();
    Pizza(Size size, Base base, Location location);
    void createPizza();
    
    
    string getName();
    void setName(char inName[MAXCHARSINPIZZANAME]);

    int getPrice();
    Location getLocation();
    void setPrice(int inPrice);
    void setLocation(Location inLocation);
    
    status getStatus();
    void setStatus(status inStatus);
    
    int getParentID();
    void setParentID(int inParentID);
    
    Base getBase();
    Size getSize();
    Topping* getToppings();
    int getToppingCount();
    void setToppingCount(int inToppingCount);
    
    friend ostream& operator << (ostream& out, const Pizza&);
private:
    Topping toppings[MAXTOPPINGSONPIZZA];
    Size sizeOfPizza;
    Base baseOfPizza;
    Location locationOfPizza;
    char name[MAXCHARSINPIZZANAME];
    int price;
    int toppingCount;
    status status;
    int parentID;
    
    
    
};
#endif /* Pizza_hpp */
