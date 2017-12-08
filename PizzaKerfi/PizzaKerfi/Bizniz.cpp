//
//  Bizniz.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 07/12/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Bizniz.hpp"
#include <cstring>


/**************************************************************************************
 
                                    TOPPINGS
 
 ***************************************************************************************/
 
vector<Topping> Bizniz::getVectorOfToppings(){
    
    vector<Topping> toppings;
    toppings = toppingRepo.getVectorOfToppings();
    
    return toppings;
}

void Bizniz::addTopping(Topping& topping){
   
    toppingRepo.addTopping(topping);
    
}

void Bizniz::storeVectorOfToppings(vector<Topping> toppings){
    
    toppingRepo.storeVectorOfToppings(toppings);
}




/**************************************************************************************
 
                                    LOCATIONS
 
 ***************************************************************************************/

vector<Location> Bizniz::getVectorOfLocations(){
    vector<Location> locations;
    locations = locationRepo.getVectorOfLocations();
    
    return locations;
    
}
void Bizniz::addLocation(Location& location){
    
    locationRepo.addLocation(location);
    
}
void Bizniz::storeVectorOfLocations(vector<Location> locations){
    
    locationRepo.storeVectorOfLocations(locations);
    
}




/**************************************************************************************
 
                                    SIDES
 
 ***************************************************************************************/

vector<Side> Bizniz::getVectorOfSides(){
    
    vector<Side> sides;
    sides = sideRepo.getVectorOfSides();
    
    return sides;
    
}
void Bizniz::addSide(Side& side){
    
    sideRepo.addSide(side);
    
}
void Bizniz::storeVectorOfSides(vector<Side> sides){
    
    sideRepo.storeVectorOfSides(sides);
    
}




/**************************************************************************************
 
                                    DRINKS
 
 ***************************************************************************************/

vector<Drink> Bizniz::getVectorOfDrinks(){
    vector<Drink> drinks;
    drinks = drinkRepo.getVectorOfDrinks();
    
    return drinks;
    
}

void Bizniz::addDrink(Drink& drink){
    
    drinkRepo.addDrink(drink);
    
}

void Bizniz::storeVectorOfDrinks(vector<Drink> drinks){
    
    drinkRepo.storeVectorOfDrinks(drinks);
    
}



/**************************************************************************************
 
                                    SIZES
 
 ***************************************************************************************/

vector<Size> Bizniz::getVectorOfSizes(){
    
    vector<Size> sizes;
    sizes = sizeRepo.getVectorOfSizes();
    
    return sizes;
    
}

void Bizniz::addSize(Size& size){
    
    sizeRepo.addSize(size);
    
}

void Bizniz::storeVectorOfSizes(vector<Size> sizes){
    
    sizeRepo.storeVectorOfSizes(sizes);
    
}



/**************************************************************************************
 
                                    BASES
 
 ***************************************************************************************/
vector<Base> Bizniz::getVectorOfBases(){
    
    vector<Base> bases;
    bases = baseRepo.getVectorOfBases();
    
    return bases;
    
}

void Bizniz::addBase(Base& base){
    
    baseRepo.addBase(base);
    
}

void Bizniz::storeVectorOfBases(vector<Base> bases){
    
    baseRepo.storeVectorOfBases(bases);
    
}






/**************************************************************************************
 
                                    PIZZA
 
 ***************************************************************************************/


Pizza* Bizniz::getArrayOfPizzasAtLocationWithSomeStatus(status status, Location location, int &sizeOfReturnPizzaList){
    
    int sizeOfEntirePizzaList;
    Pizza* allPizzas = pizzaRepo.retrievePizzaArray(PIZZAFILE, sizeOfEntirePizzaList);
    Pizza* returnPizzas = new Pizza[sizeOfEntirePizzaList];
    sizeOfReturnPizzaList = 0;
    for (int i = 0; i < sizeOfEntirePizzaList; i++) {
        if((allPizzas[i].getStatus()) == status && allPizzas[i].getLocation().getLocation() == location.getLocation()){
            returnPizzas[sizeOfReturnPizzaList] = allPizzas[i];
            sizeOfReturnPizzaList++;
        }
    }
    return returnPizzas;
}

Pizza* Bizniz::getArrayOfPizzasAtLocationWithoutSomeStatus(status status, Location location, int& sizeOfReturnPizzaList){
    int sizeOfEntirePizzaList;
    Pizza* allPizzas = pizzaRepo.retrievePizzaArray(PIZZAFILE, sizeOfEntirePizzaList);
    Pizza* returnPizzas = new Pizza[sizeOfEntirePizzaList];
    sizeOfReturnPizzaList = 0;
    for (int i = 0; i < sizeOfEntirePizzaList; i++) {
        if((allPizzas[i].getStatus()) != status && allPizzas[i].getLocation().getLocation() == location.getLocation()){
            returnPizzas[sizeOfReturnPizzaList] = allPizzas[i];
            sizeOfReturnPizzaList++;
        }
    }
    return returnPizzas;
}


void Bizniz::savePizzaArrayInFile(Pizza *pizzaArray, int sizeOfArray){
    pizzaRepo.clearPizzaFile(PIZZAFILE);
    for (int i = 0; i < sizeOfArray; i++) {
        pizzaRepo.storePizza(pizzaArray[i], PIZZAFILE);
    }
}

char* Bizniz::statusToString(status status){
    char* statusString = new char[MAXCHARINSTATUSSTRING];
    if(status == WAITING){
        strcpy(statusString, "WAITING  ");
    }else if(status == PREPPING){
        strcpy(statusString, "PREPPING ");
    }else if(status == READY){
        strcpy(statusString, "READY    ");
    }else if(status == DELIVERED){
        strcpy(statusString, "DELIVERED");
    }
    return statusString;
}

string Bizniz::getStatusAndPriceCharArr(Pizza pizza){
    
    char* statusAndPriceString = new char[MAXCHARINSTATUSANDPRICESTRING];
    //Hef streng STATUS
    strcpy(statusAndPriceString, statusToString(pizza.getStatus()));
    //Hef string BIL
    strcat(statusAndPriceString, "          ");//Passa að þessi lengd sé sú sama og SIZEOF.. breytan
   
    //Hef int price
    char* priceString = new char[MAXCHARINPRICESTRING];
    int price = pizza.getPrice();
    sprintf(priceString, "%d", price);
    
    //Vil STATUSBILprice
    strcat(statusAndPriceString, priceString);
    //cout << statusAndPriceString << endl;
    string returnString = statusAndPriceString;
    return returnString;
}


/**************************************************************************************
 
                                        ORDER
 
 ***************************************************************************************/



void Bizniz::setOrderPaidValue(string fileName, int pureIndex, bool value){
    int size;
    Order* orders = orderRepo.retrieveOrderArray(fileName, size);
    orders[pureIndex].setPaid(value);
    orderRepo.clearOrderFile(fileName);
    for (int i = 0; i < size; i++) {
        orderRepo.storeOrder(orders[i]);
    }
}

void Bizniz::setOrderDeliveredValue(string fileName, int pureIndex, bool value){
    int size;
    Order* orders = orderRepo.retrieveOrderArray(fileName, size);
    orders[pureIndex].setDelivered(value);
    orderRepo.clearOrderFile(fileName);
    for (int i = 0; i < size; i++) {
        orderRepo.storeOrder(orders[i]);
    }
}
