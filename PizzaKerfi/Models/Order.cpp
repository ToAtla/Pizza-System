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
    statusOfOrder = UNPAID;
    comment[0] = '\0';
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

void Order::setLocation(Location inLocation){
    locationOfOrder = inLocation;
}

int Order::getID(){
    return ID;
}

void Order::setID(int inID){
    ID = inID;
}

orderStatus Order::getStatusOfOrder(){
    return statusOfOrder;
}

void Order::setStatusOfOrder(orderStatus oStatus){
    statusOfOrder = oStatus;
}

void Order::setNumberOfPizzas(int inNumberOfPizzas){
    numberOfPizzas =  inNumberOfPizzas;
}

int Order::getTotalPrice(){
    return totalPrice;
}
void Order::setTotalPrice(int inTotalPrice){
    totalPrice = inTotalPrice;
}

int Order::getNumberOfSides(){
    return numberOfSides;
}

void Order::setNumberofSides(int inNumberOfSides){
    numberOfSides = inNumberOfSides;
}

int Order::getNumberOfDrinks(){
    return numberOfDrinks;
}

void Order::setNumberOfDrinks(int inNumberOfDrinks){
    numberOfDrinks = inNumberOfDrinks;
}

Side* Order::getSideList(){
    return sideList;
}

Drink* Order::getDrinkList(){
    return drinkList;
}

char* Order::getOrdercComment(){
    return comment;
}

void Order::setOrderComment(char *inComment){
    strcpy(comment, inComment);
}

ostream& operator << (ostream& out, const Order& order){
    Bizniz bizniz;
    out << "#" << order.ID << "\t\t\t\t\t\t\t\t\t\t\t   " << order.locationOfOrder << "  \t\t\t\t\t\t\t\t" << bizniz.orderStatusToString(order.statusOfOrder) << endl;
    out << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << endl;
    if(order.comment[0] != '\0'){
        cout << "Comment:" << order.comment << endl;
    }
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
