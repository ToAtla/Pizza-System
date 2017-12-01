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
    //TODO að gera þennan gæja tóman
    //pizzaList =
}

void Order::setVerbose(bool v){
    verbose = v;
}

bool Order::getVerbose(){
    return verbose;
}
istream& operator >> (istream& in, Order& order){
    if(order.verbose){
        cout << "Enter number of pizzas to add to order: ";
        
    }
    in >> order.numberOfPizzas;
    
    for (int i = 0; i < order.numberOfPizzas; i++) {
        //order.pizzaList[i] = Pizza();
        //order.pizzaList[i].setVerbose(order.verbose);
        in >> order.pizzaList[i];
    }
    if(order.verbose){
        
    }
    return in;
}

ostream& operator << (ostream& out, const Order& order){
    if(order.verbose){
        cout << "Number of pizzas in order: " << order.numberOfPizzas << endl;
        
    }
    for (int i = 0; i < order.numberOfPizzas; i++) {
        //order.pizzaList[i] = Pizza();
        //order.pizzaList[i].setVerbose(order.verbose);
        out << order.pizzaList[i];
    }
    if(order.verbose){
        
    }
    return out;
}

