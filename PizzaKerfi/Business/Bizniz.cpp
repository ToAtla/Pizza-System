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

//Return a vector of all toppings from the "toppings.dat" file.
vector<Topping> Bizniz::getVectorOfToppings(){
    
    vector<Topping> toppings;
    toppings = toppingRepo.getVectorOfToppings();
    
    return toppings;
}

//Adds a topping to the "toppings.dat" file.
void Bizniz::addTopping(Topping& topping){
    
    if(isValidPrice(topping.getPrice())){
        toppingRepo.addTopping(topping);
    }
}

//Takes a vector of toppings as a parameter and overwrites it into the "toppings.dat" file
void Bizniz::storeVectorOfToppings(vector<Topping> toppings){
    
    toppingRepo.storeVectorOfToppings(toppings);
}

//Takes a vector of toppings as a parameter and a int index and erases the topping at that index
//and overwrites it into the "toppings.dat" file
void Bizniz::removeTopping(vector<Topping> toppings, int index){
    
    toppings.erase(toppings.begin() + (index-1));
    
    toppingRepo.storeVectorOfToppings(toppings);
    
}



/**************************************************************************************
 
                                    LOCATIONS
 
 ***************************************************************************************/

//Return a vector of all locations from the "locations.dat" file.
vector<Location> Bizniz::getVectorOfLocations(){
    vector<Location> locations;
    locations = locationRepo.getVectorOfLocations();
    
    return locations;
    
}

//Adds a location to the "location.dat" file.
void Bizniz::addLocation(Location& location){
    
        locationRepo.addLocation(location);
    
}

//Takes a vector of locations as a parameter and overwrites it into the "locations.dat" file
void Bizniz::storeVectorOfLocations(vector<Location> locations){
    
    locationRepo.storeVectorOfLocations(locations);
    
}

//Takes a vector of locations as a parameter and a int index and erases the location at that index
//and overwrites it into the "locations.dat" file
void Bizniz::removeLocation(vector<Location> locations, int index){
    
    locations.erase(locations.begin() + (index-1));
    
    locationRepo.storeVectorOfLocations(locations);
    
}




/**************************************************************************************
 
                                    SIDES
 
 ***************************************************************************************/

//Return a vector of all sides from the "sides.dat" file.
vector<Side> Bizniz::getVectorOfSides(){
    
    vector<Side> sides;
    sides = sideRepo.getVectorOfSides();
    
    return sides;
    
}

//Adds a side to the "sides.dat" file.
void Bizniz::addSide(Side& side){
    
    if(isValidPrice(side.getPrice())){
        sideRepo.addSide(side);
    }
    
}

//Takes a vector of sides as a parameter and overwrites it into the "sides.dat" file
void Bizniz::storeVectorOfSides(vector<Side> sides){
    
    sideRepo.storeVectorOfSides(sides);
    
}

//Takes a vector of sides as a parameter and a int index and erases the side at that index
//and overwrites it into the "sides.dat" file
void Bizniz::removeSide(vector<Side> sides, int index){
    
    sides.erase(sides.begin() + (index-1));
    
    sideRepo.storeVectorOfSides(sides);
}



/**************************************************************************************
 
                                    DRINKS
 
 ***************************************************************************************/

//Return a vector of all drinks from the "drinks.dat" file.
vector<Drink> Bizniz::getVectorOfDrinks(){
    vector<Drink> drinks;
    drinks = drinkRepo.getVectorOfDrinks();
    
    return drinks;
    
}

//Adds a drink to the "drinks.dat" file.
void Bizniz::addDrink(Drink& drink){
    
    if(isValidPrice(drink.getPrice()))
        drinkRepo.addDrink(drink);
    
}

//Takes a vector of drinks as a parameter and overwrites it into the "drinks.dat" file
void Bizniz::storeVectorOfDrinks(vector<Drink> drinks){
    
    drinkRepo.storeVectorOfDrinks(drinks);
    
}

//Takes a vector of drinks as a parameter and a int index and erases the drink at that index
//and overwrites it into the "drinks.dat" file
void Bizniz::removeDrink(vector<Drink> drinks, int index){
    
    drinks.erase(drinks.begin() + (index-1));
    
    drinkRepo.storeVectorOfDrinks(drinks);
}


/**************************************************************************************
 
                                    SIZES
 
 ***************************************************************************************/

//Return a vector of all sizes from the "sizes.dat" file.
vector<Size> Bizniz::getVectorOfSizes(){
    
    vector<Size> sizes;
    sizes = sizeRepo.getVectorOfSizes();
    
    return sizes;
    
}

//Adds a sizes to the "sizes.dat" file.
void Bizniz::addSize(Size& size){
   
    if(isValidPrice(size.getPrice()))
        sizeRepo.addSize(size);
    
}

//Takes a vector of sizes as a parameter and overwrites it into the "sizes.dat" file
void Bizniz::storeVectorOfSizes(vector<Size> sizes){
    
    sizeRepo.storeVectorOfSizes(sizes);
    
}

//Takes a vector of sizes as a parameter and a int index and erases the size at that index
//and overwrites it into the "sizes.dat" file
void Bizniz::removeSize(vector<Size> sizes, int index){
    
    sizes.erase(sizes.begin() + (index-1));
    
    sizeRepo.storeVectorOfSizes(sizes);
}


/**************************************************************************************
 
                                    BASES
 
 ***************************************************************************************/

//Return a vector of all bases from the "bases.dat" file.
vector<Base> Bizniz::getVectorOfBases(){
    
    vector<Base> bases;
    bases = baseRepo.getVectorOfBases();
    
    return bases;
    
}

//Adds a base to the "bases.dat" file.
void Bizniz::addBase(Base& base){
    
    if(isValidPrice(base.getPrice()))
        baseRepo.addBase(base);
    
}

//Takes a vector of bases as a parameter and overwrites it into the "bases.dat" file
void Bizniz::storeVectorOfBases(vector<Base> bases){
    
    baseRepo.storeVectorOfBases(bases);
    
}

//Takes a vector of bases as a parameter and a int index and erases the base at that index
//and overwrites it into the "bases.dat" file
void Bizniz::removeBase(vector<Base> bases, int index){
   
    bases.erase(bases.begin() + (index-1));
    
    baseRepo.storeVectorOfBases(bases);
}

/**************************************************************************************
 
                                    MenuItem
 
 ***************************************************************************************/


MenuItem* Bizniz::getArrayOfMenuItems(string fileName, int& tellMeHowMany){
    
    MenuItem* menuItems = new MenuItem[MAXPIZZASINPIZZAFILE];
    
    menuItemRepo.getArrayOfMenuItems(tellMeHowMany);
    
    for(int i = 0; i < tellMeHowMany; i++){
        menuItems[i] = menuItemRepo.getArrayOfMenuItems(tellMeHowMany)[i];
    }
    
    return menuItems;
}

void Bizniz::addMenuItem(MenuItem& menuItem){
    
    menuItemRepo.addMenuItem(menuItem);
    
}

MenuItem Bizniz::recognizeMenuItem(Topping* pizzaToppings, int toppingCount, bool isMenuitem){
    MenuItem returnMenuItem;
    int sizeOfMenu;
    MenuItem* allMenuItems = getArrayOfMenuItems(MENUITEMFILE, sizeOfMenu);
    for (int i = 0; i < sizeOfMenu; i++) {
        if(allMenuItems[i].getToppingCount() == toppingCount){
            
        }
    }
    return returnMenuItem;
}

/**************************************************************************************
 
                                    Analysis
 
 ***************************************************************************************/

int Bizniz::calcTotalTurnover(){
    int numberOfOrders;
    int sum = 0;
    Order* allOrders = getArrayOfOrders(LEGACYORDERFILE, numberOfOrders);
    for (int i = 0; i < numberOfOrders ; i++) {
        sum += allOrders[i].getTotalPrice();
    }
    delete [] allOrders;
    return sum;
}

int Bizniz::calcTotalPizzas(){
    int numberOfOrders;
    int pizzaSum = 0;
    Order* allOrders = getArrayOfOrders(LEGACYORDERFILE, numberOfOrders);
    for (int i = 0; i < numberOfOrders ; i++) {
        pizzaSum += allOrders[i].getNumberOfPizzas();
    }
    delete [] allOrders;
    return pizzaSum;
}

int Bizniz::calcTotalOrders(){
    int numberOfOrders;
    Order* allOrders = getArrayOfOrders(LEGACYORDERFILE, numberOfOrders);
    delete [] allOrders;
    return numberOfOrders;
}

double Bizniz::calcMeanOrderPrice(){
    return (double)calcTotalTurnover()/(double)calcTotalOrders();
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
    strcat(statusAndPriceString, "           ");//Passa að þessi lengd sé sú sama og SIZEOF.. breytan
   
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

void Bizniz::fixNameOfPizza(Pizza& pizza, MenuItem menuItem){
    char tempName[MAXCHARSINPIZZANAME];
    char* name = new char[MAXCHARSINPIZZANAME];
    strcpy(tempName, pizza.getSize().getName());
    strcat(tempName, " ");
    strcat(tempName, pizza.getBase().getName());
    strcat(tempName, " ");
    strcat(tempName, menuItem.getName());
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

Pizza Bizniz::assemblePizzaWithMenuItem(Size size, Base base, MenuItem menuItem, Location location){
    
    int pizzaPrice = menuItem.getPrice() + size.getPrice() + base.getPrice();
    Pizza returnPizza = Pizza(size, base, location);
    
    for (int i = 0; i < menuItem.getToppingCount(); i++) {
        
        returnPizza.getToppings()[i] = menuItem.getCertainTopping(i);
        
    }
    
    returnPizza.setToppingCount(menuItem.getToppingCount());
    fixNameOfPizza(returnPizza, menuItem);
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
        strcpy(statusString, "PAID     ");
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
    kukaorder.setStatusOfOrder(DELIVERED);
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

void Bizniz::storeOrder(const Order& order, string fileName){
    orderRepo.storeOrder(order, fileName);
}

void Bizniz::moveOrderBetween(string sourceFile, string destFile, int orderNum){

    //sækja allar pantanir
    int sizeOfSourceFile;
    Order* orderList = getArrayOfOrders(sourceFile, sizeOfSourceFile);
    
    
    int index;
    
    for (int i = 0; i < sizeOfSourceFile; i++) {
        if(orderList[i].getID() == orderNum){
            //eitthvað gerist
            index = i;
            i = sizeOfSourceFile;
        }
    }
    
    
    //eyða öllu í skjalinu
    orderRepo.clearOrderFile(sourceFile);
    //Bæta öllu við fram að index
    //Og halda áfram eftir index í i+1
    for (int i = 0; i < sizeOfSourceFile-1; i++) {
        if(i < index){
            storeOrder(orderList[i], sourceFile);
        }else{
            storeOrder(orderList[i+1], sourceFile);
        }
    }
    //append to dest
    storeOrder(orderList[index], destFile);
    delete [] orderList;
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
                    orderNum = i;
                    pizzaNum = c;
                    cout << allOrders[orderNum].getPizzasInOrder()[pizzaNum] << endl;
                    i = ordersInFile;
                    c = allOrders[i].getNumberOfPizzas();
                }
            }
        }
    }
    delete [] allOrders;
}

void Bizniz::changeStatusOfPizzaInOrder(int orderNum, int pizzaNumber, status status){
    int ordersInFile = 0;
    Order* allOrders = getArrayOfOrders(ORDERFILE, ordersInFile);
    
    
     allOrders[orderNum].getPizzasInOrder()[pizzaNumber].setStatus(status);
    
    
    //Hér á eftir að setja inn að hann visti dæmið í skrána
    orderRepo.clearOrderFile(ORDERFILE);
    for (int i = 0; i < ordersInFile; i++) {
        storeOrder(allOrders[i]);
    }
    delete [] allOrders;
    
    
    
    
    
    //PRUFUVIÐBÓT
    int newOrdersInFile = 0;
    Order* newAllOrders = getArrayOfOrders(ORDERFILE, newOrdersInFile);
    delete [] newAllOrders;
    
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


bool Bizniz::orderExist(int orderNum){
    int ordersInFile = 0;
    Order* allOrders = getArrayOfOrders(ORDERFILE, ordersInFile);
    for (int i = 0; i < ordersInFile; i++) {
        if(allOrders[i].getID() == orderNum){
            return true;
        }
    }
    return false;
}

/**************************************************************************************
 
                              Exceptions(Bool functions)
 
 ***************************************************************************************/

//Takes a string as a parameter and throws an exception if it contains a digit
//if it does not it returns true.
bool Bizniz::isValidName(string name){
    
    for(int i = 0; i < name.length(); i++){
        if(isdigit(name[i])){
            throw InvalidNameException("Invalid name! (Name can't include digits)");
        }
        
    }
    
    return true;
}

//Takes an int as a parameter and throws an exception if it's lower than 0
//if it is not it returns true.
bool Bizniz::isValidPrice(int price){
    
    if(price < 0){
        throw InvalidPriceException("Invalid price! (Price must be higher than 0)");
    }
    
    return true;
}

//Takes in a string as a parameter and throws an exception if it contains a character that is not a number
//if it does not it returns true.
bool Bizniz::isPriceDigit(string price){
    
    for(int i = 0; i < price.length(); i++){
        if(!isdigit(price[i])){
            throw InvalidPriceException("*ERROR* Invalid price! (Price can't contain a character)");
        }
    }
    
    return true;
}


//Takes an int and an unsigned long as parameters and if the int is lower than 1
//or higher than the unsigned long it throws an exception otherwise it returns true.
bool Bizniz::isValidInput(int input, unsigned long sizeOfList){
    
    unsigned long unsignedInput = input;
    
    if(unsignedInput < 1 || unsignedInput > sizeOfList){
        throw InvalidInputException("*ERROR* Invalid input! (Input does not match any index on the list) Please try again");
    }
    
    return true;
}

//Takes an int and an unsigned long as parameters and if the int is higher than the unsigned lon
//otherwise it returns true.
bool Bizniz::isValidToppingInput(int input, unsigned long sizeOflist){
    
    unsigned long unsignedInput = input;
    
    if(unsignedInput > sizeOflist){
        throw InvalidInputException("*ERROR* Invalid input! (Input does not match any index on the list) Please try again");
    }
    
    return true;
    
}

//Takes a string as a parameter an if it contains a character that is not a number
//it throws an exception otherwise it returns true.
bool Bizniz::isInputDigit(string input){
    
    for(int i = 0; i < input.length(); i++){
        if(!isdigit(input[i])){
            throw InvalidInputException("*ERROR* Invalid input! (Input does not match any index on the list) Please try again");
        }
    }
    
    return true;
}

//Takes in a string and an int as parameters and if the integ
bool Bizniz::isValidNameLength(string name, int lenght){
    
    if(name.length() > lenght-1){
        throw InvalidNameException("*ERROR* Invalid name! (Name cant exceed the maximum amount of characters)");
    }
        
    return true;
}

//Throws an exception if the "locations.dat" file is empty
//otherwise returns true
bool Bizniz::isValidLocationFile(){
    
    vector<Location> locations;
    locations = locationRepo.getVectorOfLocations();
    
    if(locations.size() < 1){
        throw InvalidFileLocationException();
    }
    
    return true;
}

//Throws an exception if the "base.dat" file is empty or if the "size.dat" file is empty
//otherwise it returns true.
bool Bizniz::isValidBaseSizeFile(){
    
    vector<Size> sizes;
    sizes = sizeRepo.getVectorOfSizes();
    vector<Base> bases;
    bases = baseRepo.getVectorOfBases();
    
    if(sizes.size() < 1){
        throw InvalidFileSizeBaseException("*ERROR* Can't order a pizza because there are no sizes available");
    }
    
    if(bases.size() < 1) {
        throw InvalidFileSizeBaseException("*ERROR* Can't order a pizza because there are no bases available");
    }
    
    return true;
}






