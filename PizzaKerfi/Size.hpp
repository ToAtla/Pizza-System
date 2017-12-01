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

using namespace std;

const int MAXCHARINSIZE = 30;

class Size{
    
public:
    Size();
    int getPrice();
    void setPrice(int inPrice);
    void setVerbose(bool v);
    char* getName();
    void setName(char inName[]);
    friend istream& operator >> (istream& in, Size& size);
    friend ostream& operator << (ostream& out, const Size& size);
private:
    char name[MAXCHARINSIZE];
    int price;
    bool verbose = true;
};

#endif /* Size_hpp */
