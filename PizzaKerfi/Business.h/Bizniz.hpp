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
#include "MenuItemRepo.hpp"
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
   
    //MenuItem
    MenuItem* getArrayOfMenuItems(string fileName, int& tellMeHowMany);
    void addMenuItem(MenuItem& menuItem);
    MenuItem recognizeMenuItem(Topping* pizzaToppings, int toppingCount, bool& isMenuitem);
    
    //Analysis
    int calcTotalTurnover();
    int calcTotalPizzas();
    int calcTotalOrders();
    double calcMeanOrderPrice();
    double calcMeanNumberOfPizzasPerOrder();
    double calcMeanNumberOfDrinksPerOrder();
    double calcMeanNumberOfSidesPerOrder();
    string mostPopularTopping();
    
    //Pizza
    
    void savePizzaArrayInFile(Pizza pizzaArray[], int sizeOfArray);
    void storePizza(Pizza pizza, string fileName);
    char* statusToString(status status);
    string getStatusAndPriceCharArr(Pizza pizza);
    void fixNameOfPizza(Pizza& pizza);
    void fixNameOfPizza(Pizza& pizza, MenuItem menuItem);
    Pizza assemblePizza(Size size, Base base, Topping *toppings, int amountOfToppings, Location location);
    Pizza assemblePizzaWithMenuItem(Size size, Base base, MenuItem menuItem, Location location);
    void appendPizzaToFile(string fileName, Pizza pizza);
    void extractPizzasForPrepUI(Order order);
    Pizza* extractApplicablePizzasFromOrder(Order order, status status, bool onlyWith, int& tellMeHowMany);
    
    
    //Order
    void setOrderStatus(string fileName, int orderNum, orderStatus newOrderStatus);
    bool allPizzasInOrderReady(Order order);
    char* orderStatusToString(orderStatus status);
    Order getOrderByID(int orderNumber);
    int getIDForNextOrder();
    void storeOrder(Order order);
    void storeOrder(const Order& order, string fileName);
    void moveOrderBetween(string sourceFile, string destFile, int orderNum);
    Order* getArrayOfOrders(string fileName, int& tellMeHowManyOrders);
    void locateFirstOrderWithPizzaWithStatusAtLocation(status status, Location location, int& orderNum, int& pizzaNum);
    void changeStatusOfPizzaInOrder(int orderNum, int pizzaNumber, status status);
    Order* getArrayOfOrdersAtLocationWithApplicablePizzas(status status, Location location, bool onlyWith, int& sizeOfReturnOrderList);
    bool thereExistsOrderAtLocationWithApplicablePizza(status status, Location location, bool onlyWith);
    bool orderExist(int orderNum);
    char* getTimeNow();
    int getOrderIndexByID(int inputID);
    
    
    
    
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
    MenuItemRepo menuItemRepo;
};

#endif /* Bizniz_hpp */
