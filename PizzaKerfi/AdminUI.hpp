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
    //Prentar út valmynd sem býður notandanum uppá að velja það sem hann vill gera með topping listann.
    
    
    //Sub menu undir Topping
    void displayAllToppings();
    //Prentar út lista yfir öll álegg.
    void addTopping();
    //Bætir við áleggi á listann.
    void changeTopping();
    //Gerir notandanum kleift að velja alegg af listanum og nafninu og verðinu á því.
    void removeTopping();
    //Gerir notandanum kleift að velja álegg af listanum og eyða því.

    
    
};

#endif /* AdminUI_hpp */
