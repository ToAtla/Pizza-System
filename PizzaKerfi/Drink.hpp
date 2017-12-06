//
//  Drink.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/30/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef Drink_hpp
#define Drink_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Global.hpp"

using namespace std;



class Drink{
    
    public:
        Drink();
        int getPrice();
        void setPrice(int inPrice);
        char* getName();
        void setName(char inName[]);
        friend istream& operator >> (istream& in, Drink& drink);
        friend ostream& operator << (ostream& out, const Drink& drink);
    private:
        char name[MAXCHARINDRINKNAME];
        int price;
    
};

#endif /* Drink_hpp */
