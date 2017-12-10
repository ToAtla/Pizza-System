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
#include <iomanip>
#include "Global.hpp"

using namespace std;



class Side{

public:
    Side();
    Side(string name, int price);
    int getPrice();
    void setPrice(int inPrice);
    char* getName();
    void setName(char inName[]);
    void setStatus(status inStatus);
    status getStatus();

    friend istream& operator >> (istream& in, Side& side);
    friend ostream& operator << (ostream& out, const Side& side);
private:
    char name[MAXCHARINSIDENAME];
    int price;
    status status;
};



#endif /* Side_hpp */
