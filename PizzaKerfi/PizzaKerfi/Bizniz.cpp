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

void Bizniz::chooseToppingsOnPizza(Pizza& pizza){
    Topping toppingsForPizza[MAXTOPPINGSONPIZZA];
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
                    pizza.getToppings()[c] = allToppings.at(input-1);
                    pizza.setPrice(pizza.getPrice() + allToppings.at(input-1).getPrice());
                    c++;
                    cout << "Topping number " << input << " added" << endl;
                }else{
                    break;
                }
            }
        }
        pizza.setToppingCount(c);
    }
}


void Bizniz::chooseSizeForPizza(Pizza &pizza){
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
            cout << "Base number " << i+1 << endl;
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
        
        pizza.getSize().setName(sizeForPizza.getName());
        pizza.getSize().setPrice(sizeForPizza.getPrice());
        pizza.setPrice(pizza.getPrice() + pizza.getSize().getPrice());
    }
}


//Fall sem gefur notandanum kleift á því að velja botn fyrir pizzu tilvik.
void Bizniz::chooseBaseForPizza(Pizza &pizza){
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
        
        pizza.getBase().setName(baseForPizza.getName());
        pizza.getBase().setPrice(baseForPizza.getPrice());
        pizza.setPrice(pizza.getPrice() + baseForPizza.getPrice());
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

int Bizniz::getNumberForNextOrder(){
    int orderCnt = 0;
    OrderRepo ordRep;
    ordRep.retrieveOrderArray("orders.dat", orderCnt);
    if(orderCnt <= 0){
        orderCnt = 1;
        return orderCnt;
    }
    orderCnt++;
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

void Bizniz::assembleOrder(Order &order){
    
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
                    order.setLocation(locations.at(i));
                    invalidInput = false;
                }
            }
            
            if(invalidInput){
                cout << "Please enter a valid location: " << endl;
                
            }
        }
        Bizniz bizniz;
        order.setID(bizniz.getNumberForNextOrder());
        
        cout << endl << "Enter number of pizzas to add to order: ";
        int inNumPizz;
        cin >> inNumPizz;
        order.setNumberOfPizzas(inNumPizz);
        
        for (int i = 0; i < order.getNumberOfPizzas(); i++) {
            cout << endl << "Pizza number: " << i+1 << endl;
            order.getPizzasInOrder()[i] = Pizza();
            order.getPizzasInOrder()[i].setLocation(order.getLocation());
            
            cin >> order.getPizzasInOrder()[i];
            order.setTotalPrice(order.getTotalPrice() + order.getPizzasInOrder()[i].getPrice());
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
            order.setNumberofSides(0);
            
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
                        order.getSideList()[c] = sides.at(i);
                        
                        order.setTotalPrice(order.getTotalPrice() + sides.at(i).getPrice());
                        
                        order.setNumberofSides(order.getNumberOfSides() + 1);
                        
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
            order.setNumberOfDrinks(0);
            
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
                        order.getDrinkList()[c] = drinks.at(i);
                        order.setTotalPrice(order.getTotalPrice() + drinks.at(i).getPrice());
                        order.setNumberOfDrinks(order.getNumberOfDrinks() + 1);
                        c++;
                    }
                }
                
                cout << endl <<"Would you like do add another drink? y: yes ";
                cin >> input;
            }
            
        }
    }
    
}
