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
#include "Global.hpp"
#include <iomanip>

using namespace std;

class Order {
public:
    
    Order();
    void setLocation(Location inLocation);
    int getID();
    void setID(int inID);
    orderStatus getStatusOfOrder();
    void setStatusOfOrder(orderStatus oStatus);
    void setNumberOfPizzas(int inNumberOfPizzas);
    Pizza* getPizzasInOrder();
    int getNumberOfPizzas();
    Location getLocation();
    int getTotalPrice();
    void setTotalPrice(int inTotalPrice);
    int getNumberOfSides();
    void setNumberofSides(int inNumberOfSides);
    int getNumberOfDrinks();
    void setNumberOfDrinks(int inNumberOfDrinks);
    Side* getSideList();
    Drink* getDrinkList();
    char* getOrdercComment();
    void setOrderComment(char inComment[]);
    friend ostream& operator << (ostream& out, const Order&);
    
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
    orderStatus statusOfOrder;
    char comment[MAXCHARINORDERCOMMENT];
};

#endif /* Order_hpp */
