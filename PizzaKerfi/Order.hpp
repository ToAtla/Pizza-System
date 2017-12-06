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
#include "Location.hpp"
#include <iomanip>

const int MAXSTUFFSINORDER = 20;

using namespace std;

class Order {
public:
    Order();
    Pizza* getPizzasInOrder();
    int getNumberOfPizzas();
    void setPaid(bool paid);
    bool isPaid();
    void setDelivered(bool v);
    bool isDelivered();
    friend ostream& operator << (ostream& out, const Order&);
    friend istream& operator >> (istream& in, Order&);
private:
    Pizza pizzaList[MAXSTUFFSINORDER];
    Side sideList[MAXSTUFFSINORDER];
    Drink drinkList[MAXSTUFFSINORDER];
    Location locationOfOrder;
    int numberOfPizzas;
    int numberOfSides;
    int numberOfDrinks;
    int totalPrice;
    int ID;
    bool paid = false;
    bool ready = false;
    bool delievered = false;
};

#endif /* Order_hpp */
