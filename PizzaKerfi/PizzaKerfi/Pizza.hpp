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

class Pizza{

public:
    
    Pizza();
    Pizza(string inSize, vector<Topping> inToppings);
    string getName();
    void setName(string inName);

    int getPrice();
    void setPrice(int inPrice);
    
    friend ostream& operator << (ostream& out, const Pizza&);
    friend istream& operator >> (istream& in, Pizza&);
private:
    string name;
    int price;
    string size;
    vector<Topping> toppings;
    bool verbose = true;
};
#endif /* Pizza_hpp */
