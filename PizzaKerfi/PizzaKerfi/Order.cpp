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
#include "Bizniz.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Order::Order(){
    numberOfPizzas = 0;
    numberOfSides = 0;
    numberOfDrinks = 0;
    ID = 0;
    locationOfOrder = Location();
    totalPrice = 0;
    paid = false;
    ready = false;
    delievered = false;
}

Pizza* Order::getPizzasInOrder(){
    return this->pizzaList;
}
int Order::getNumberOfPizzas(){
    return this->numberOfPizzas;
}

Location Order::getLocation(){
    return this->locationOfOrder;
}

void Order::setPaid(bool input){
    this->paid = input;
}

bool Order::isPaid(){
    return paid;
}

void Order::setDelivered(bool v){
    delievered = v;
}
bool Order::isDelivered(){
    return delievered;
}

istream& operator >> (istream& in, Order& order){
   
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
                    order.locationOfOrder = locations.at(i);
                    invalidInput = false;
                }
            }
            
            if(invalidInput){
                cout << "Please enter a valid location: " << endl;
                
            }
        }
        Bizniz bizniz;
        order.ID = bizniz.getNumberForNextOrder();
        
        cout << endl << "Enter number of pizzas to add to order: ";
        in >> order.numberOfPizzas;
        
        for (int i = 0; i < order.numberOfPizzas; i++) {
            cout << endl << "Pizza number: " << i+1 << endl;
            order.pizzaList[i] = Pizza();
            order.pizzaList[i].setLocation(order.locationOfOrder);
            in >> order.pizzaList[i];
            order.totalPrice += order.pizzaList[i].getPrice();
        }
     
        SideRepo sr;
        vector<Side> sides = sr.getVectorOfSides();
        char input = '0';
        int c = 0;
        
        if(sides.size() < 1){
            cout << endl << "There are no sides available at this time." << endl;
        }
        else{
            cout << endl << "Would you like a side with your order? y: yes ";
            char input = '0';
            cin >> input;
            
            int c = 0;
            order.numberOfSides = 0;
           
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
            
            
        }
        c = 0;
        
        DrinkRepo dr;
        vector<Drink> drinks = dr.getVectorOfDrinks();
        
        if(drinks.size() < 1){
            cout << endl << "There are no drinks available at this time." << endl;
        }
        else{
            cout << endl << "Would you like to a drink with your order? y: yes ";
            cin >> input;
            order.numberOfDrinks = 0;
            
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
            
        }
    }
    
    return in;
  
}

ostream& operator << (ostream& out, const Order& order){
    out << "#" << order.ID << "\t\t\t\t\t\t\t\t\t\t\t   " << order.locationOfOrder << "  \t\t\t\t\t\t\t\t";
    if(!order.paid){
        cout << "NOT ";
    }
    out << "PAID" << endl;
    out << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << endl;
    out << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << endl;
    
    out << setfill(' ') <<  endl;
    //Millilýsingar
    
    out << setw(SIZEOFSETW) << left << "ITEM" << "STATUS              PRICE" << endl;
    out << setw(SIZEOFSETW) << left << "----" << "----------          -----" << endl;
    
    for(int i = 0; i < order.numberOfPizzas; i++) {
        out << order.pizzaList[i];
    }
    
    for(int i = 0; i < order.numberOfSides; i++){
        out << order.sideList[i] << endl;
    }
    
    for(int i = 0; i < order.numberOfDrinks; i++){
        out << order.drinkList[i] << endl;
    }
    cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << endl << endl;
    cout << setfill(' ');
    char* totalPriceCA = new char[7];
    
    sprintf(totalPriceCA, "%d", order.totalPrice);
    string totalPriceString = totalPriceCA;
    
    //cout << LONGLINE << endl;
    out <<  setw(SIZEOFSETWBIG-6) << left << "TOTAL:" << totalPriceString << endl;
    out << endl;
    out << TABSTRING << "------" << endl;
    out << endl;
    
    return out;
}
