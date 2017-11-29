//
//  AdminUI.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef AdminUI_hpp
#define AdminUI_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class AdminUI{

public:
    void startAdminUI();
    void displayToppingMenu();
    
    
    
private:
    //Sub menu undir Topping
    void displayAllToppings();
    
};

#endif /* AdminUI_hpp */
