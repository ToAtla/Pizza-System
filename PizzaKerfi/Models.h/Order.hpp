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
    ///Defult constructor that gives all the private variables a value of 0.
    void setLocation(Location inLocation);
    ///Takes in a location as a parameter and gives the private variable locationOfOrder the value of it.
    int getID();
    ///Returns the value of the private variable ID.
    void setID(int inID);
    ///Takes in an int as a parameter and gives the private variable ID the value of it.
    orderStatus getStatusOfOrder();
    ///Return the value of the private variable statusOfOrder.
    void setStatusOfOrder(orderStatus oStatus);
    ///Takes in an orderStatus enum and gives the private variable statusOfOrder the value of it.
    void setNumberOfPizzas(int inNumberOfPizzas);
    ///Takes in an int parameter and gives the private variable numberOfPizzas the value of it.
    Pizza* getPizzasInOrder();
    ///Returns a pointer to the private array pizzaList.
    int getNumberOfPizzas();
    ///Returns the value of the private variable numberOfPizzas.
    Location getLocation();
    ///Returns the value of the private variable locationOfOrder.
    int getTotalPrice();
    ///Returns the value of the private variable totalPrice.
    void setTotalPrice(int inTotalPrice);
    ///Takes in an int as a parameter and gives the private variable totalPrice the value of it.
    int getNumberOfSides();
    ///Returns the value of the private variable numberOfSides.
    void setNumberofSides(int inNumberOfSides);
    ///Takes in an int as a parameter and gives the private variable numberOfSides the value of it.
    int getNumberOfDrinks();
    ///Return the value of the private variable numberOfDrinks.
    void setNumberOfDrinks(int inNumberOfDrinks);
    ///Takes in an int as a parameter and gives the private variable numberOfDrinks the value of it.
    Side* getSideList();
    ///Returns a pointer to the private array sideList.
    Drink* getDrinkList();
    ///Returns a pointer to the private array drinkList.
    char* getOrdercComment();
    ///Return a pointer to the private array comment.
    void setOrderComment(char inComment[]);
    ///Takes in an char array as a parameter and gives the private array comment the value of it.
    friend ostream& operator << (ostream& out, const Order&);
    ///Overloads the cout operator so one can use '>>' to input the contents of a Order instance.
    
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
