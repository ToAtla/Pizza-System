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

using namespace std;

class SalesUI{
    
    public:
       void startSalesUI();
    private:
        void createOrder();
        void createASinglePizzaToTest();
        void displayPizzas();
};


#endif /* SalesUI_hpp */
