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

using namespace std;

class Topping {
public:
    Topping();
    int getPrice();
    void setPrice(int inPrice);
    string getName();
    void setName(string inName);
    friend istream& operator >> (istream& in, Topping& topping);
    friend ostream& operator << (ostream& out, const Topping& topping);
private:
    string name;
    int price;
};

#endif /* Topping_hpp */