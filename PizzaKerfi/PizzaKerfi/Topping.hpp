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

using namespace std;

class Topping {
public:
    int getPrice();
    void setPrice(int inPrice);
    string getName();
    void setName(string inName);
private:
    string name;
    int price;
};

#endif /* Topping_hpp */
