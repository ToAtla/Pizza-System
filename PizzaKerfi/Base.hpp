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

using namespace std;

const int MAXCHARSINBASENAME = 4;

class Base{
    
    public:
        Base();
        int getPrice();
        void setPrice(int inPrice);
        void setVerbose(bool v);
        char* getName();
        void setName(char inName[]);
        friend istream& operator >> (istream& in, Base& base);
        friend ostream& operator << (ostream& out, const Base& base);
    private:
        char name[MAXCHARSINBASENAME];
        int price;
        bool verbose = true;
};

#endif /* Base_hpp */