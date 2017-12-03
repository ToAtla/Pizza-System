//
//  Order.hpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 28/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef Order_hpp
#define Order_hpp

#include <stdio.h>
#include <string>
#include "Pizza.hpp"
#include "Side.hpp"
#include "Drink.hpp"

const int MAXSTUFFSINORDER = 20;

using namespace std;

class Order {
    public:
        Order();
        friend ostream& operator << (ostream& out, const Order&);
        friend istream& operator >> (istream& in, Order&);
    private:
        Pizza pizzaList[MAXSTUFFSINORDER];
        Side sideList[MAXSTUFFSINORDER];
        Drink drinkList[MAXSTUFFSINORDER];
    
        int numberOfPizzas;
        int totalPrice;
};

#endif /* Order_hpp */
