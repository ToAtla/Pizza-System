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

///Defult constructor that gives all the private variables a value of 0.
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

///Returns a pointer to the private array pizzaList.
Pizza* Order::getPizzasInOrder(){
    return this->pizzaList;
}

///Returns the value of the private variable numberOfPizzas.
int Order::getNumberOfPizzas(){
    return this->numberOfPizzas;
}

///Returns the value of the private variable locationOfOrder.
Location Order::getLocation(){
    return this->locationOfOrder;
}

///Takes in a location as a parameter and gives the private variable locationOfOrder the value of it.
void Order::setLocation(Location inLocation){
    locationOfOrder = inLocation;
}

///Returns the value of the private variable ID.
int Order::getID(){
    return ID;
}

///Takes in an int as a parameter and gives the private variable ID the value of it.
void Order::setID(int inID){
    ID = inID;
}

///Return the value of the private variable statusOfOrder.
orderStatus Order::getStatusOfOrder(){
    return statusOfOrder;
}

 ///Takes in an orderStatus enum and gives the private variable statusOfOrder the value of it.
void Order::setStatusOfOrder(orderStatus oStatus){
    statusOfOrder = oStatus;
}

///Takes in an int parameter and gives the private variable numberOfPizzas the value of it.
void Order::setNumberOfPizzas(int inNumberOfPizzas){
    numberOfPizzas =  inNumberOfPizzas;
}

///Returns the value of the private variable totalPrice.
int Order::getTotalPrice(){
    return totalPrice;
}

///Takes in an int as a parameter and gives the private variable totalPrice the value of it.
void Order::setTotalPrice(int inTotalPrice){
    totalPrice = inTotalPrice;
}

///Returns the value of the private variable numberOfSides.
int Order::getNumberOfSides(){
    return numberOfSides;
}

///Takes in an int as a parameter and gives the private variable numberOfSides the value of it.
void Order::setNumberofSides(int inNumberOfSides){
    numberOfSides = inNumberOfSides;
}

///Return the value of the private variable numberOfDrinks.
int Order::getNumberOfDrinks(){
    return numberOfDrinks;
}

///Takes in an int as a parameter and gives the private variable numberOfDrinks the value of it.
void Order::setNumberOfDrinks(int inNumberOfDrinks){
    numberOfDrinks = inNumberOfDrinks;
}

///Returns a pointer to the private array sideList.
Side* Order::getSideList(){
    return sideList;
}

///Returns a pointer to the private array drinkList.
Drink* Order::getDrinkList(){
    return drinkList;
}

///Return a pointer to the private array comment.
char* Order::getOrdercComment(){
    return comment;
}

///Takes in an char array as a parameter and gives the private array comment the value of it.
void Order::setOrderComment(char *inComment){
    strcpy(comment, inComment);
}

///Overloads the cout operator so one can use '>>' to input the contents of a Order instance.
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
