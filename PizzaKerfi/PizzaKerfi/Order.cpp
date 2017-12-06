//
//  Order.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 28/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Order.hpp"
#include "SideRepo.hpp"
#include "DrinkRepo.hpp"
#include "LocationRepo.hpp"
#include <iostream>
using namespace std;

Order::Order(){
    numberOfPizzas = 0;
    numberOfSides = 0;
    numberOfDrinks = 0;
    locationOfOrder = Location();
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
        order.totalPrice += order.pizzaList[i].getPrice();
    }
 
    cout << endl << "Would you like a side with your order? y: yes ";
    char input = 0;
    cin >> input;
    
    int c = 0;
    while(input == 'y') {
       
        SideRepo sr;
        vector<Side> sides = sr.getVectorOfSides();
        
        for(unsigned int i = 0; i < sides.size(); i++){
            cout << "Side number: " << i+1 << endl;
            cout << sides.at(i) << endl;
        }
        cout << "Choose a side you want to add to your order: ";
        int sideNumber = 0;
        cin >> sideNumber;
        for(unsigned int i = 0; i < sides.size(); i++){
            if(sideNumber == i+1){
                order.sideList[c] = sides.at(i);
                order.totalPrice += sides.at(i).getPrice();
                order.numberOfSides++;
                c++;
            }
        }
        
        cout << endl << "Would you like to add another side? y: yes ";
        cin >> input;
    }
    
    c = 0;
    
    cout << endl << "Would you like to a drink with your order? y: yes ";
    cin >> input;
    
    while(input == 'y') {
        
        DrinkRepo dr;
        vector<Drink> drinks = dr.getVectorOfDrinks();
        
        for(unsigned int i = 0; i < drinks.size(); i++){
            cout << "Drink number: " << i+1 << endl;
            cout << drinks.at(i) << endl;
        }
        cout << "Choose a drink you want to add to your order: ";
        int drinkNumber = 0;
        cin >> drinkNumber;
        for(unsigned int i = 0; i < drinks.size(); i++){
            if(drinkNumber == i+1){
                order.drinkList[c] = drinks.at(i);
                order.totalPrice += drinks.at(i).getPrice();
                order.numberOfDrinks++;
                c++;
            }
        }
        
        cout << endl <<"Would you like do add another drink? y: yes ";
        cin >> input;
        
    }
    
    cout << endl << "-----Locations available-----" << endl << endl;
    int locationNumber = 0;
    
    bool invalidInput = true;
    
    while(invalidInput)
    {
        LocationRepo lr;
        vector<Location> locations = lr.getVectorOfLocations();
        
        for(unsigned int i = 0; i < locations.size(); i++){
            cout << "Location number: " << i+1 << endl;
            cout << locations.at(i) << endl;
        }
        cout << "Choose a location for your order: " << endl;
        cin >> locationNumber;
        
        for(unsigned int i = 0; i < locations.size(); i++){
            if(locationNumber == i+1){
                order.locationOfOrder = locations.at(i);
                invalidInput = false;
            }
        }
        
        if(!invalidInput){
            cout << "Please enter a valid location: " << endl;
        }
    }
  
    return in;
  
}

ostream& operator << (ostream& out, const Order& order){
    out << endl <<  " - - - - " << endl;
    out << "Pizza/s:" << endl;
    for(int i = 0; i < order.numberOfPizzas; i++) {
        out << order.pizzaList[i];
    }
    out << endl <<"Side/s:" << endl;
    for(int i = 0; i < order.numberOfSides; i++){
        out << order.sideList[i] << endl;
    }
    out << endl << "Drink/s:" << endl;
    for(int i = 0; i < order.numberOfDrinks; i++){
        out << order.drinkList[i] << endl;
    }
    out << endl << "Location of order" << endl;
    out << order.locationOfOrder;
    out << endl << "The total price of order: " << order.totalPrice << endl;
    out << " - - - - " << endl;
    
    return out;
}
