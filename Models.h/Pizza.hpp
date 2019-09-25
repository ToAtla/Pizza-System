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
        ///Defult constructor that gives all the private variables a value of 0.
        Pizza(Size size, Base base, Location location);
        ///A constructor that takes in 3 parameters, an instance of Size, an instance of base and a instance of location
        ///and gives the private variables Size, base and location the values of the parameters.
        string getName();
        ///Return the private variable name of the pizza.
        void setName(char inName[MAXCHARSINPIZZANAME]);
        ///Takes in a character array and gives the private variable name the value of it.
        int getPrice();
        ///Returns the value of the private variable price.
        Location getLocation();
        ///Return the value of the private variable location.
        void setPrice(int inPrice);
        ///Takes in an int as a parameter and gives the private variable price the value of it.
        void setLocation(Location inLocation);
        ///Takes in a Location as a parameter and gives the private variable locationOfPizza the value of it.
        status getStatus();
        ///Returns the value of the private variable status.
        void setStatus(status inStatus);
        ///Takes in a status as a parameter and gives the private variable status the value of it.
        int getParentID();
        ///Returns the value of the private variable parentID.
        void setParentID(int inParentID);
        ///Takes in an int as a parameter and gives the private variable parentID the value of it.
        Base getBase();
        ///Returns the value of the private variable base.
        Size getSize();
        ///Returns the value of the private variable size.
        Topping* getToppings();
        ///Returns a pointer to the private array toppings.
        int getToppingCount();
        ///Return the value of the private variable toppingCount.
        void setToppingCount(int inToppingCount);
        ///Takes in an int as a parameter and gives the private variable toppingCount the value of it.
        friend ostream& operator << (ostream& out, const Pizza&);
        ///Overloads the ostream operator so when one uses the '<<' to print out the contents of an instance of Pizza.
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
