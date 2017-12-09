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
    
    if(isValidPrice(topping.getPrice())){
        toppingRepo.addTopping(topping);
    }
}

void Bizniz::storeVectorOfToppings(vector<Topping> toppings){
    
    toppingRepo.storeVectorOfToppings(toppings);
}

void Bizniz::removeTopping(vector<Topping> toppings, int index){
    
    toppings.erase(toppings.begin() + (index-1));
    
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

void Bizniz::removeLocation(vector<Location> locations, int index){
    
    locations.erase(locations.begin() + (index-1));
    
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

void Bizniz::removeSide(vector<Side> sides, int index){
    
    sides.erase(sides.begin() + (index-1));
    
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

void Bizniz::removeDrink(vector<Drink> drinks, int index){
    
    drinks.erase(drinks.begin() + (index-1));
    
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

void Bizniz::removeSize(vector<Size> sizes, int index){
    
    sizes.erase(sizes.begin() + (index-1));
    
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

void Bizniz::removeBase(vector<Base> bases, int index){
   
    bases.erase(bases.begin() + (index-1));
    
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
    delete [] allPizzas;
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
    delete [] allPizzas;
    return returnPizzas;
}


void Bizniz::savePizzaArrayInFile(Pizza *pizzaArray, int sizeOfArray){
    pizzaRepo.clearPizzaFile(PIZZAFILE);
    for (int i = 0; i < sizeOfArray; i++) {
        pizzaRepo.storePizza(pizzaArray[i], PIZZAFILE);
    }
}

void Bizniz::storePizza(Pizza pizza, string fileName){
    pizzaRepo.storePizza(pizza, fileName);
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
    char* statusString = statusToString(pizza.getStatus());
    strcpy(statusAndPriceString, statusString);
    delete [] statusString;
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
    delete [] statusAndPriceString;
    return returnString;
}

//Þetta fall á að breyta nafninu á pizzunni í nafn á forminu
//STO ORG PP SKI SVE
void Bizniz::fixNameOfPizza(Pizza& pizza){
    char tempName[MAXCHARSINPIZZANAME];
    char* name = new char[MAXCHARSINPIZZANAME];
    strcpy(tempName, pizza.getSize().getName());
    strcat(tempName, " ");
    strcat(tempName, pizza.getBase().getName());
    for (int i = 0; i < pizza.getToppingCount(); i++) {
        strcat(tempName, " ");
        strcat(tempName, pizza.getToppings()[i].getName());
    }
    strcpy(name, tempName);
    pizza.setName(name);
}

Pizza Bizniz::assemblePizza(Size size, Base base, Topping *toppings, int amountOfToppings, Location location){
    //Hingað má setja einhver tékk á það hvort allt sé rétt gert
    int pizzaPrice = size.getPrice() + base.getPrice();
    Pizza returnPizza = Pizza(size, base, location);
    for (int i = 0; i < amountOfToppings; i++) {
        returnPizza.getToppings()[i] = toppings[i];
        pizzaPrice += toppings[i].getPrice();
    }
    returnPizza.setToppingCount(amountOfToppings);
    fixNameOfPizza(returnPizza);
    returnPizza.setPrice(pizzaPrice);
    return returnPizza;
}


void Bizniz::appendPizzaToFile(string fileName, Pizza pizza){
    pizzaRepo.storePizza(pizza, fileName);
}

void Bizniz::extractPizzasForPrepUI(Order order){
    Pizza* pizzasInOrder = order.getPizzasInOrder();
    for (int i = 0; i < order.getNumberOfPizzas(); i++) {
        storePizza( pizzasInOrder[i], PIZZAFILE);
    }
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
    delete [] orders;
}

void Bizniz::setOrderDeliveredValue(string fileName, int pureIndex, bool value){
    int size;
    Order* orders = orderRepo.retrieveOrderArray(fileName, size);
    orders[pureIndex].setDelivered(value);
    orderRepo.clearOrderFile(fileName);
    for (int i = 0; i < size; i++) {
        orderRepo.storeOrder(orders[i]);
    }
    delete [] orders;
}

int Bizniz::getNumberForNextOrder(){
    int orderCnt = 0;
    OrderRepo ordRep;
    Order* tempOrderArray = ordRep.retrieveOrderArray(ORDERFILE, orderCnt);
    if(orderCnt <= 0){
        orderCnt = 1;
        return orderCnt;
    }
    orderCnt++;
    delete [] tempOrderArray;
    return orderCnt;
}
bool Bizniz::isEverythingInOrderReady(Order order){
    
    for (int i = 0; i <order.getNumberOfPizzas(); i++) {
        if(order.getPizzasInOrder()[i].getStatus() != READY){
            return false;
        }
    }
    return true;
}


void Bizniz::storeOrder(Order order){
    orderRepo.storeOrder(order);
}

Order* Bizniz::getArrayOfOrders(string fileName, int& tellMeHowManyOrders){
    return orderRepo.retrieveOrderArray(fileName, tellMeHowManyOrders);
}

/**************************************************************************************
 
                              Exceptions(Bool functions)
 
 ***************************************************************************************/

bool Bizniz::isValidName(string name){
    
    for(int i = 0; i < name.length(); i++){
        if(isdigit(name[i])){
            throw InvalidNameException("Invalid name! (Name can't include digits)");
        }
        
    }
    
    return true;
}

bool Bizniz::isValidPrice(int price){
    
    if(price < 0){
        throw InvalidPriceException("Invalid price! (Price must be higher than 0)");
    }
    
    return true;
}

bool Bizniz::isPriceDigit(string price){
    
    for(int i = 1; i < price.length(); i++){
        if(!isdigit(price[i]) && price[1] != '-'){
            throw InvalidPriceException("Invalid price! (Price can't contain letters)");
        }
    }
    
    return true;
}

bool Bizniz::isValidInput(int input, unsigned int sizeOfList){
    
    
    
    return true;
}

bool Bizniz::isInputDigit(string input){
    
    for(int i = 1; i < input.length(); i++){
        if(isdigit(input[i]) && input[1] == '-'){
            throw InvalidInputException("Invalid input!");
        }
    }
    
    for(int i = 0; i < input.length(); i++){
        if(!isdigit(input[i])){
            throw InvalidInputException("Invalid input!");
        }
    }
    
    return true;
}

bool Bizniz::isValidNameLength(string name, int lenght){
    
    if(name.length() > (lenght)){
        throw InvalidNameException("Invalid name! (Name cant exceed the maximum amount of characters)");
    }
        
    return true;
}
    

    
