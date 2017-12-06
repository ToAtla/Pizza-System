//
//  Side.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/30/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef Side_hpp
#define Side_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Global.hpp"

using namespace std;



class Side{

    public:
        Side();
        int getPrice();
        void setPrice(int inPrice);
        void setVerbose(bool v);
        char* getName();
        void setName(char inName[]);
        friend istream& operator >> (istream& in, Side& side);
        friend ostream& operator << (ostream& out, const Side& side);
    private:
        char name[MAXCHARINSIDENAME];
        int price;
        bool verbose = true;
    
};



#endif /* Side_hpp */
