//
//  Bizniz.hpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 07/12/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef Bizniz_hpp
#define Bizniz_hpp

#include <stdio.h>
#include "Location.hpp"
#include "ToppingRepo.hpp"
#include "LocationRepo.hpp"
#include "SideRepo.hpp"
#include "DrinkRepo.hpp"
#include "SizeRepo.hpp"
#include "BaseRepo.hpp"
#include "PizzaRepo.hpp"
#include "OrderRepo.hpp"
#include "InvalidNameException.hpp"
#include "InvalidPriceException.hpp"
#include <string>
#include <stdio.h>
class Bizniz {
public:
    //Toppings
    vector<Topping> getVectorOfToppings();
    void addTopping(Topping& topping);
    void storeVectorOfToppings(vector<Topping> toppings);
    void removeTopping(vector<Topping>, int index);
    
    //Locations
    vector<Location> getVectorOfLocations();
    void addLocation(Location& location);
    void storeVectorOfLocations(vector<Location> locations);
    void removeLocation(vector<Location>, int index);
    
    //Side
    vector<Side> getVectorOfSides();
    void addSide(Side& side);
    void storeVectorOfSides(vector<Side> sides);
    void removeSide(vector<Side>, int index);
    
    //Drink
    vector<Drink> getVectorOfDrinks();
    void addDrink(Drink& drink);
    void storeVectorOfDrinks(vector<Drink> drinks);
    void removeDrink(vector<Drink>, int index);
    
    //Size
    vector<Size> getVectorOfSizes();
    void addSize(Size& size);
    void storeVectorOfSizes(vector<Size> sizes);
    void removeSize(vector<Size>, int index);
    
    //Base
    vector<Base> getVectorOfBases();
    void addBase(Base& base);
    void storeVectorOfBases(vector<Base> bases);
    void removeBase(vector<Base>, int index);
   
    //Pizza
    Pizza* getArrayOfPizzasAtLocationWithSomeStatus(status status, Location location, int& sizeOfReturnPizzaList);
    Pizza* getArrayOfPizzasAtLocationWithoutSomeStatus(status status, Location location, int& sizeOfReturnPizzaList);
    void savePizzaArrayInFile(Pizza pizzaArray[], int sizeOfArray);
    char* statusToString(status status);
    string getStatusAndPriceCharArr(Pizza pizza);
    void fixNameOfPizza(Pizza& pizza);
    void chooseToppingsOnPizza(Pizza& pizza);
    void chooseSizeForPizza(Pizza& pizza);
    void chooseBaseForPizza(Pizza& pizza);
    Pizza assemblePizza(Size size, Base base, Topping *toppings, int amountOfToppings, Location location);
    void appendPizzaToFile(string fileName, Pizza pizza);
    
    
    //Order
    void setOrderPaidValue(string fileName, int pureIndex, bool value);
    void setOrderDeliveredValue(string fileName, int pureIndex, bool value);
    bool isEverythingInOrderReady(Order order);
    int getNumberForNextOrder();
    void assembleOrder(Order& order);
    
    //Exceptions
    bool isValidName(string name);
    bool isValidPrice(int price);
    bool isPriceJustDigit(string price);
    
private:
    ToppingRepo toppingRepo;
    LocationRepo locationRepo;
    SideRepo sideRepo;
    DrinkRepo drinkRepo;
    SizeRepo sizeRepo;
    BaseRepo baseRepo;
    PizzaRepo pizzaRepo;
    OrderRepo orderRepo;
};

#endif /* Bizniz_hpp */
