//
//  SalesUI.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef SalesUI_hpp
#define SalesUI_hpp

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include "ToppingRepo.hpp"
#include "Topping.hpp"
#include "Location.hpp"
#include "LocationRepo.hpp"
#include "SideRepo.hpp"
#include "Side.hpp"
#include "DrinkRepo.hpp"
#include "Drink.hpp"
#include "Global.hpp"
#include "Size.hpp"
#include "Bizniz.hpp"

using namespace std;

class SalesUI{
public:
   void startSalesUI();
private:
    Bizniz bizniz;
    void createOrder();
    void displayOrders();
    
    Size sizePickingProcess();
    Base basePickingProcess();
    Topping* toppingPickingProcess(int& toppingCount);
    Location locationPickingProcess();
    Pizza pizzaCreationProcess(Location locationOfOrderForPizzaToFollow);
    void pizzaListCreationProcess(Order& order);
    Drink drinkPickingProcess();
    void drinkListCreationProcess(Order& order);
    Side sidePickingProcess();
    void sideListCreationProcess(Order& order);
    
    //Bráðabirgða
    void createASinglePizzaToTest();
    
    
};


#endif /* SalesUI_hpp */
