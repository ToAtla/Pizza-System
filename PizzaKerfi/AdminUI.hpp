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
#include "ToppingRepo.hpp"
#include "Topping.hpp"

using namespace std;

class AdminUI{

public:
    void startAdminUI();
   
    
    
    
private:
    void displayToppingMenu();
    //Sub menu undir Topping
    void displayAllToppings();
    void addTopping();
    void changeTopping();
    
    
};

#endif /* AdminUI_hpp */
