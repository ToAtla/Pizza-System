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
#include "LocationRepo.hpp"
#include "Location.hpp"
#include "SideRepo.hpp"
#include "DrinkRepo.hpp"
#include <fstream>
#include <iostream>

using namespace std;

class AdminUI{

public:
    void startAdminUI();

private:
    //Prentar út valmynd sem býður notandanum uppá að velja það sem hann vill gera með topping listann.
    void displayToppingMenu();
    

    //Sub menu undir Topping
    void displayAllToppings();
    //Prentar út lista yfir öll álegg.
    void addTopping();
    //Bætir við áleggi á listann.
    void changeTopping();
    //Gerir notandanum kleift að velja alegg af listanum og nafninu og verðinu á því.
    void removeTopping();
    //Gerir notandanum kleift að velja álegg af listanum og eyða því.

    void displayLocationMenu();
    void displayAllLocations();
    void addLocation();
    void changeLocation();
    void removeLocation();

    
    void displaySideMenu();
    void displayAllSides();
    void addSide();
    void changeSide();
    void removeSide();

    
    void displayDrinkMenu();
    void displayAllDrinks();
    void addDrink();
    void changeDrink();
    void removeDrink();
};

#endif /* AdminUI_hpp */
