//
//  Base.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/1/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef Base_hpp
#define Base_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Global.hpp"

using namespace std;



class Base{

    public:
        Base();
        int getPrice();
        void setPrice(int inPrice);
        char* getName();
        void setName(char inName[]);
        friend istream& operator >> (istream& in, Base& base);
        friend ostream& operator << (ostream& out, const Base& base);
    private:
        char name[MAXCHARSINBASENAME];
        int price;
};

#endif /* Base_hpp */
