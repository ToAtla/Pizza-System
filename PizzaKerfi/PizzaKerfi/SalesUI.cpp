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

void SalesUI::startSalesUI(){
    
    char input = 0;
    while(input != 'b')
    {
        cout << "1: Create a orders BROKEN" << endl;
        cout << "2: View all orders BROKEN(create one pizza and save to file)" << endl;
        cout << "3: Change a order BROKEN(display pizzas in file)" << endl;
        cout << "3: delete a order BROKEN" << endl;
        cout << "b: back" << endl;
        cin >> input;
        if(input == '1')
        {
            createOrder();
        }
        else if(input == '2')
        {
            createASinglePizzaToTest();
        }
        else if(input == '3')
        {
            displayPizzas();
        }
        else if(input == '4')
        {
            
        }
    }
}

void SalesUI::createOrder(){
    Order order;
    cin >> order;
}

















/*
 Bráðabirgðaföll til að sjá hvort það virki að vista pizzur í skrár
*/

void SalesUI::createASinglePizzaToTest(){
    //Also saves to file
    Pizza pizza;
    cin >> pizza;
    PizzaRepo pr;
    pr.storePizza(pizza);
}

void SalesUI::displayPizzas(){
    Pizza pizza;
    PizzaRepo pr;
    pizza = pr.retrievePizza();
    cout << pizza;
}
