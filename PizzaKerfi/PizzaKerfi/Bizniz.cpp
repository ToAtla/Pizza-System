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
    
    if(isValidPrice(side.getPrice())){
        sideRepo.addSide(side);
    }
    
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
    
    if(isValidPrice(drink.getPrice()))
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
   
    if(isValidPrice(size.getPrice()))
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
    
    if(isValidPrice(base.getPrice()))
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
    }else if(status == OUTOFSHOP){
        strcpy(statusString, "OUTOFSHOP");
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
    delete [] priceString;
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


Pizza* Bizniz::extractApplicablePizzasFromOrder(Order order, status status, bool onlyWith, int& tellMeHowMany){
    tellMeHowMany = 0;
    Pizza* returnPizzas = new Pizza[order.getNumberOfPizzas()];
    for (int i = 0; i < order.getNumberOfPizzas(); i++) {
        if(onlyWith){
            if(order.getPizzasInOrder()[i].getStatus() == status){
                returnPizzas[tellMeHowMany] = order.getPizzasInOrder()[i];
                tellMeHowMany++;
            }
        }else{
            if(order.getPizzasInOrder()[i].getStatus() != status){
                returnPizzas[tellMeHowMany] = order.getPizzasInOrder()[i];
                tellMeHowMany++;
            }
        }
        
    }
    return returnPizzas;
}


/**************************************************************************************
 
                                        ORDER
 
 ***************************************************************************************/


void Bizniz::setOrderStatus(string fileName, int orderNum, orderStatus newOrderStatus){
    int size;
    Order* allOrders = orderRepo.retrieveOrderArray(fileName, size);
    for (int i = 0; i < size; i++) {
        if(allOrders[i].getID() == orderNum){
            //eitthvað gerist
            allOrders[i].setStatusOfOrder(newOrderStatus);
            i = size;
        }
    }
    for (int i = 0; i < size; i++) {
        orderRepo.clearOrderFile(ORDERFILE);
        storeOrder(allOrders[i]);
    }
    delete [] allOrders;
}
bool Bizniz::allPizzasInOrderReady(Order order){
    for (int i = 0; i < order.getNumberOfPizzas(); i++) {
        if(order.getPizzasInOrder()[i].getStatus() != READY){
            return false;
        }
    }
    return true;
}

char* Bizniz::orderStatusToString(orderStatus status){
    char* statusString = new char[MAXCHARINORDERSTATUSSTRING];
    if(status == UNPAID){
        strcpy(statusString, "UNPAID   ");
    }if(status == PAID){
        strcpy(statusString, "PAiD     ");
    }if(status == DELIVERED){
        strcpy(statusString, "DELIVERED");
    }
    return statusString;
}

Order Bizniz::getOrderNumber(int orderNumber){
    int size;
    Order* allOrders = orderRepo.retrieveOrderArray(ORDERFILE, size);
    for (int i = 0; i < size; i++) {
        if(allOrders[i].getID() == orderNumber){
            return allOrders[i];
        }
    }
    Order kukaorder;
    return kukaorder;
}

int Bizniz::getNumberForNextOrder(){
    int orderCnt = 0;
    OrderRepo ordRep;
    Order* tempOrderArray = ordRep.retrieveOrderArray(ORDERFILE, orderCnt);
    if(orderCnt == 0){
        orderCnt = 1;
        return orderCnt;
    }
    orderCnt++;
    delete [] tempOrderArray;
    return orderCnt;
}


void Bizniz::storeOrder(Order order){
    orderRepo.storeOrder(order);
}

Order* Bizniz::getArrayOfOrders(string fileName, int& tellMeHowManyOrders){
    return orderRepo.retrieveOrderArray(fileName, tellMeHowManyOrders);
}

void Bizniz::locateFirstOrderWithPizzaWithStatusAtLocation(status status, Location location, int& orderNum, int& pizzaNum){
    int ordersInFile = 0;
    Order* allOrders = getArrayOfOrders(ORDERFILE, ordersInFile);
    for (int i = 0; i < ordersInFile; i++) {
        if(allOrders[i].getLocation().getLocation() == location.getLocation()){
            for (int c = 0; c < allOrders[i].getNumberOfPizzas(); c++) {
                if(allOrders[i].getPizzasInOrder()[c].getStatus() == status){
//                    cout << "first instance of pizza that applies O:" << orderNum << " P:" << pizzaNum << endl;
//                    cout << "printing that pizza:" << endl;
//                    cout << allOrders[orderNum].getPizzasInOrder()[pizzaNum]
                    orderNum = i;
                    pizzaNum = c;
                    i = ordersInFile;
                    c = allOrders[i].getNumberOfPizzas();
                }
            }
        }
    }
    delete [] allOrders;
}

void Bizniz::changeStatusOfPizzaInOrder(int orderNum, int pizzaNumber, status status){
//    cout << "Changing status of pizza in order" << endl;
//    cout << "O: " << orderNum << " and P: " << pizzaNumber << " and New Status: " << statusToString(status) << endl;
    
    int ordersInFile = 0;
    Order* allOrders = getArrayOfOrders(ORDERFILE, ordersInFile);
//    cout << "Printing said pizza in said order before change: " << endl << allOrders[orderNum].getPizzasInOrder()[pizzaNumber] << endl;
    allOrders[orderNum].getPizzasInOrder()[pizzaNumber].setStatus(status);
    //Hér á eftir að setja inn að hann visti dæmið í skrána
    for (int i = 0; i < ordersInFile; i++) {
        orderRepo.clearOrderFile(ORDERFILE);
        storeOrder(allOrders[i]);
    }
    delete [] allOrders;
    
    //PRUFUVIÐBÓT
//    int newOrdersInFile = 0;
//    Order* newAllOrders = getArrayOfOrders(ORDERFILE, newOrdersInFile);
//    cout << "Printing said pizza in said order after change: " << endl << newAllOrders[orderNum].getPizzasInOrder()[pizzaNumber] << endl;
//    delete [] newAllOrders;
    
}


Order* Bizniz::getArrayOfOrdersAtLocationWithApplicablePizzas(status status, Location location, bool onlyWith, int& sizeOfReturnOrderList){
    int ordersInFile = 0;
    Order* allOrders = getArrayOfOrders(ORDERFILE, ordersInFile);
    sizeOfReturnOrderList = 0;
    Order* returnOrders = new Order[ordersInFile];
    
    
    for (int i = 0; i < ordersInFile; i++) {
        if(allOrders[i].getLocation().getLocation() == location.getLocation()){
            for (int c = 0; c < allOrders[i].getNumberOfPizzas(); c++) {
                if(onlyWith){
                    if(allOrders[i].getPizzasInOrder()[c].getStatus() == status){
                        returnOrders[sizeOfReturnOrderList] = allOrders[i];
                        sizeOfReturnOrderList++;
                        c = allOrders[i].getNumberOfPizzas();
                    }
                }else{
                    if(allOrders[i].getPizzasInOrder()[c].getStatus() != status){
                        returnOrders[sizeOfReturnOrderList] = allOrders[i];
                        sizeOfReturnOrderList++;
                        c = allOrders[i].getNumberOfPizzas();
                    }
                }
                
            }
        }
    }
    delete [] allOrders;
    return returnOrders;
}



bool Bizniz::thereExistsOrderAtLocationWithApplicablePizza(status status, Location location, bool onlyWith){
    int ordersInFile = 0;
    Order* allOrders = getArrayOfOrders(ORDERFILE, ordersInFile);
    for (int i = 0; i < ordersInFile; i++) {
        if(allOrders[i].getLocation().getLocation() == location.getLocation()){
            for (int c = 0; c < allOrders[i].getNumberOfPizzas(); c++) {
                if(onlyWith){
                    if(allOrders[i].getPizzasInOrder()[c].getStatus() == status){
                        return true;
                    }
                }else{
                    if(allOrders[i].getPizzasInOrder()[c].getStatus() != status){
                        return true;
                    }
                }
                
            }
        }
    }
    delete [] allOrders;
    return false;
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
    
    for(int i = 0; i < price.length(); i++){
        if(!isdigit(price[i])){
            throw InvalidPriceException("Invalid price!");
        }
    }
    
    return true;
}

bool Bizniz::isValidInput(int input, unsigned long sizeOfList){
    
    unsigned long unsignedInput = input;
    
    if(unsignedInput < 1 || unsignedInput > sizeOfList){
        throw InvalidInputException("Invalid input! (Input does not match any index on the list) Please try again");
    }
    
    return true;
}

bool Bizniz::isValidToppingInput(int input, unsigned long sizeOflist){
    
    unsigned long unsignedInput = input;
    
    if(unsignedInput > sizeOflist){
        throw InvalidInputException("Invalid input! (Input does not match any index on the list) Please try again");
    }
    
    return true;
    
}

bool Bizniz::isInputDigit(string input){
    
    for(int i = 0; i < input.length(); i++){
        if(!isdigit(input[i])){
            throw InvalidInputException("Invalid input! (Input does not match any index on the list) Please try again");
        }
    }
    
    return true;
}

bool Bizniz::isValidNameLength(string name, int lenght){
    
    if(name.length() > lenght-1){
        throw InvalidNameException("Invalid name! (Name cant exceed the maximum amount of characters)");
    }
        
    return true;
}

bool Bizniz::isValidLocationFile(){
    
    vector<Location> locations;
    locations = locationRepo.getVectorOfLocations();
    
    if(locations.size() < 1){
        throw InvalidFileLocationException();
    }
    
    return true;
}

bool Bizniz::isValidBaseSizeFile(){
    
    vector<Size> sizes;
    sizes = sizeRepo.getVectorOfSizes();
    vector<Base> bases;
    bases = baseRepo.getVectorOfBases();
    
    if(sizes.size() < 1){
        throw InvalidFileSizeBaseException("Can't order a pizza because there are no sizes available");
    }
    
    if(bases.size() < 1) {
        throw InvalidFileSizeBaseException("Can't order a pizza because there are no bases available");
    }
    
    return true;
}

