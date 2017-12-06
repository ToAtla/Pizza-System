//
//  Size.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/1/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef Size_hpp
#define Size_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Global.hpp"

using namespace std;



class Size{
    
    public:
        Size();
        int getPrice();
        void setPrice(int inPrice);
        char* getName();
        void setName(char inName[]);
        friend istream& operator >> (istream& in, Size& size);
        friend ostream& operator << (ostream& out, const Size& size);
    private:
        char name[MAXCHARINSIZENAME];
        int price;
};

#endif /* Size_hpp */
