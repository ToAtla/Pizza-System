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
#include "InvalidInputException.hpp"
#include "InvalidFileLocationException.hpp"
#include "InvalidFileSizeBaseException.hpp"
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
    
    void savePizzaArrayInFile(Pizza pizzaArray[], int sizeOfArray);
    void storePizza(Pizza pizza, string fileName);
    char* statusToString(status status);
    string getStatusAndPriceCharArr(Pizza pizza);
    void fixNameOfPizza(Pizza& pizza);
    Pizza assemblePizza(Size size, Base base, Topping *toppings, int amountOfToppings, Location location);
    void appendPizzaToFile(string fileName, Pizza pizza);
    void extractPizzasForPrepUI(Order order);
    Pizza* extractApplicablePizzasFromOrder(Order order, status status, bool onlyWith, int& tellMeHowMany);
    
    
    //Order
    void setOrderStatus(string fileName, int orderNum, orderStatus newOrderStatus);
    bool allPizzasInOrderReady(Order order);
    char* orderStatusToString(orderStatus status);
    Order getOrderNumber(int orderNumber);
    int getNumberForNextOrder();
    void storeOrder(Order order);
    Order* getArrayOfOrders(string fileName, int& tellMeHowManyOrders);
    void locateFirstOrderWithPizzaWithStatusAtLocation(status status, Location location, int& orderNum, int& pizzaNum);
    void changeStatusOfPizzaInOrder(int orderNum, int pizzaNumber, status status);
    Order* getArrayOfOrdersAtLocationWithApplicablePizzas(status status, Location location, bool onlyWith, int& sizeOfReturnOrderList);
    bool thereExistsOrderAtLocationWithApplicablePizza(status status, Location location, bool onlyWith);
    bool orderExist(int orderNum);
    
    
    //Exceptions(Bool functions)
    bool isValidName(string name);
    bool isValidPrice(int price);
    bool isValidInput(int input, unsigned long sizeOfList);
    bool isValidToppingInput(int input, unsigned long sizeOflist);
    bool isPriceDigit(string price);
    bool isInputDigit(string input);
    bool isValidNameLength(string name, int lenght);
    bool isValidLocationFile();
    bool isValidBaseSizeFile();
    
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