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

using namespace std;

class Pizza{

public:
    
    Pizza();
    string getName();
    void setName(string inName);

    int getPrice();
    void setPrice(int inPrice);
private:
    string name;
    int price;
};
#endif /* Pizza_hpp */
