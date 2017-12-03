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

const int MAXTOPPINGS = 16;
const int MAXCHARSINTOPPINGNAME = 20;

using namespace std;

class Topping {
    public:
        Topping();
        int getPrice();
        void setPrice(int inPrice);
        void setVerbose(bool v);
        char* getName();
        void setName(char inName[]);
        friend istream& operator >> (istream& in, Topping& topping);
        friend ostream& operator << (ostream& out, const Topping& topping);
    private:
        char name[MAXCHARSINTOPPINGNAME];
        int price;
        bool verbose = true;
};

#endif /* Topping_hpp */
