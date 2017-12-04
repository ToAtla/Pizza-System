//
//  Order.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 28/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Order.hpp"
#include <iostream>
using namespace std;

Order::Order(){
    numberOfPizzas = 0;
    totalPrice = 0;
    paid = false;
    ready = false;
    delievered = false;
}

Pizza* Order::getPizzasInOrder(){
    return pizzaList;
}
int Order::getNumberOfPizzas(){
    return numberOfPizzas;
}

bool Order::isPaid(){
    return paid;
}

istream& operator >> (istream& in, Order& order){
    
    cout << "Enter number of pizzas to add to order: ";
    in >> order.numberOfPizzas;
    
    for (int i = 0; i < order.numberOfPizzas; i++) {
        cout << endl << "Pizza number: " << i+1 << endl;
        order.pizzaList[i] = Pizza();
        in >> order.pizzaList[i];
    }
    return in;
}

ostream& operator << (ostream& out, const Order& order){
    cout << " - - - - " << endl;
    for(int i = 0; i < order.numberOfPizzas; i++) {
        out << order.pizzaList[i];
    }
    cout << " - - - - " << endl;
    return out;
}
