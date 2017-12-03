//
//  SalesUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "SalesUI.hpp"
#include "Order.hpp"
#include "PizzaRepo.hpp"
#include "OrderRepo.hpp"

void SalesUI::startSalesUI(){
    
    char input = 0;
    while(input != 'b')
    {
        cout << "1: New order" << endl;
        cout << "2: View all orders" << endl;
        cout << "3: Change a order BROKEN" << endl;
        cout << "4: delete a order BROKEN" << endl;
        cout << "5: (temporary)add one pizza directly to waiting.dat" << endl;
        cout << "6: (temporary)display all pizzas in waiting.dat" << endl;
        cout << "b: back" << endl;
        cin >> input;
        if(input == '1')
        {
            createOrder();
        }
        else if(input == '2')
        {
            displayOrders();
        }
        else if(input == '3')
        {
            
        }
        else if(input == '4')
        {
            
        }
        else if(input == '5'){
            createASinglePizzaToTest();
        }
        else if(input == '6'){
            displayPizzas();
        }
    }
}

//Býr til pöntun og vistar hana
//vistar svo pizzurnar sérstaklega í pizzuskjal
void SalesUI::createOrder(){
    Order order;
    cin >> order;
    OrderRepo ordRep;
    ordRep.storeOrder(order);
    
    
    //Save Pizzas to pizzafile
    string pizzaFile = "waiting.dat";
    Pizza* pizzasInOrder = order.getPizzasInOrder();
    PizzaRepo pr;
    for (int i = 0; i < order.getNumberOfPizzas(); i++) {
        pr.storePizza( pizzasInOrder[i], pizzaFile);
    }
}

void SalesUI::displayOrders(){
    int orderCnt = 0;
    OrderRepo ordRep;
    Order* orderList = ordRep.retrieveOrderArray("orders.dat", orderCnt);
    for (int i = 0; i < orderCnt; i++) {
        cout << orderList[i];
    }
}



































/*
 Bráðabirgðaföll til að sjá hvort það virki að vista pizzur í skrár
*/

void SalesUI::createASinglePizzaToTest(){
    //Also saves to file
    Pizza pizza;
    cin >> pizza;
    PizzaRepo pr;
    pr.storePizza(pizza, "waiting.dat");
}

void SalesUI::displayPizzas(){
    
    Pizza pizza;
    PizzaRepo pr;
    int size = 0;
    Pizza* pizzas = pr.retrievePizzaArray("waiting.dat", size);
    for (int i = 0; i < size; i++) {
        cout << pizzas[i] << endl;
    }
}
