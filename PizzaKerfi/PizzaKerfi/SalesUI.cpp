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
#include "Bizniz.hpp"

void SalesUI::startSalesUI(){
    
    char input = 0;
    while(input != 'b')
    {
        cout << "1: New order" << endl;
        cout << "2: View all orders" << endl;
        cout << "3: Change a order BROKEN" << endl;
        cout << "4: delete a order BROKEN" << endl;
        cout << "5: (temporary)add one pizza directly to pizzas.dat with status WAITING" << endl;
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
    Pizza* pizzasInOrder = order.getPizzasInOrder();
    PizzaRepo pr;
    for (int i = 0; i < order.getNumberOfPizzas(); i++) {
        pr.storePizza( pizzasInOrder[i], PIZZAFILE);
    }
}

void SalesUI::displayOrders(){
    int orderCnt = 0;
    OrderRepo ordRep;
    Order* orderList = ordRep.retrieveOrderArray("orders.dat", orderCnt);
    for (int i = 0; i < orderCnt; i++) {
        cout << orderList[i];
    }
    delete [] orderList;
}







Size SalesUI::sizePickingProcess(){
    Size sizeForPizza;
    
    cout << endl << "-----List of available sizes-----" << endl;
    SizeRepo sizeRepo;
    vector<Size> sizes = sizeRepo.getVectorOfSizes();
    
    if(sizes.size() < 1){
        
        cout << endl << "No sizes available at this time." << endl;
        
    }
    else{
        for(int i = 0; i < sizes.size(); i++){
            Size temp = sizes.at(i);
            cout << "Size number " << i+1 << endl;
            cout << temp << endl;
        }
        int input = 0;
        cout << "Please choose a size for your pizza: ";
        cin >> input;
        for(int i = 0; i < sizes.size(); i++){
            if(input == i+1){
                sizeForPizza = sizes.at(i);
            }
        }
        
        
    }
    return sizeForPizza;
}




Base SalesUI::basePickingProcess(){
    Base baseForPizza;
    
    cout << endl << "-----List of available bases-----" << endl;
    
    BaseRepo baseRepo;
    vector<Base> bases = baseRepo.getVectorOfBases();
    
    if(bases.size() < 1){
        
        cout << endl << "No bases available at this time." << endl;
        
    }
    else{
        for(int i = 0; i < bases.size(); i++){
            Base temp = bases.at(i);
            cout << "Base number " << i+1 << endl;
            cout << temp << endl;
        }
        int input = 0;
        cout << "Please choose a base for your pizza: ";
        cin >> input;
        baseForPizza = bases.at(input-1);
    }
    return baseForPizza;
}


Topping* SalesUI::toppingPickingProcess(int& toppingCount){
    
    Topping* toppingsForPizza = new Topping[MAXTOPPINGSONPIZZA];
    cout << endl << "-----List of available toppings-----" << endl;
    ToppingRepo tr;
    vector<Topping> allToppings = tr.getVectorOfToppings();
    
    if(allToppings.size() < 1){
        cout << endl << "No toppings available at this time." << endl;
    }
    else{
        for (int i = 0; i < allToppings.size(); i++) {
            cout << "Topping nr: " << i+1 << endl;
            cout << allToppings.at(i) << endl << endl;
        }
        int c = 0;
        while(true){
            //Veit ekki hvort þarf < eða <= hérna í næstu línu
            if(c <= MAXTOPPINGSONPIZZA){
                cout << "Enter an index of topping to add or 0 to exit: ";
                int input;
                cin >> input;
                if(input != 0){
                    toppingsForPizza[c] = allToppings.at(input-1);
                    c++;
                    cout << "Topping number " << input << " added" << endl;
                }else{
                    break;
                }
            }
        }
        toppingCount = c;
    }
    return toppingsForPizza;
}


Location SalesUI::locationPickingProcess(){
    Location returnLocation;
    LocationRepo lr;
    vector<Location> locations = lr.getVectorOfLocations();
    
    if(locations.size() < 1){
        cout << endl << "No locations available at this time" << endl << endl;
    }
    else{
        cout << endl << "-----Locations available-----" << endl << endl;
        int locationNumber = 0;
        
        bool invalidInput = true;
        
        while(invalidInput){
            LocationRepo lr;
            vector<Location> locations = lr.getVectorOfLocations();
            
            for(unsigned int i = 0; i < locations.size(); i++){
                cout << "Location number: " << i+1 << endl;
                cout << locations.at(i) << endl << endl;
            }
            cout << "Choose a location for your order: ";
            cin >> locationNumber;
            
            for(unsigned int i = 0; i < locations.size(); i++){
                if(locationNumber == i+1){
                    returnLocation = locations.at(i);
                    invalidInput = false;
                }
            }
            
            if(invalidInput){
                cout << "Please enter a valid location: " << endl;
                
            }
        }
        
    }
    return returnLocation;
}


















/*
 Bráðabirgðaföll til að sjá hvort það virki að vista pizzur í skrár
*/

void SalesUI::createASinglePizzaToTest(){
    //Also saves to file
    
    Size pizzaSize = sizePickingProcess();
    Base pizzaBase = basePickingProcess();
    int toppingCount;
    Topping* pizzaToppings = toppingPickingProcess(toppingCount);
    Location pizzaLocation = locationPickingProcess();
    
    Pizza newPizza = bizniz.assemblePizza(pizzaSize, pizzaBase, pizzaToppings, toppingCount, pizzaLocation);
    delete [] pizzaToppings;
    bizniz.appendPizzaToFile(PIZZAFILE, newPizza);
    
    
}

