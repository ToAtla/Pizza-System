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
class Bizniz {
public:
    //Toppings
    vector<Topping> getVectorOfToppings();
    void addTopping(Topping& topping);
    void storeVectorOfToppings(vector<Topping> toppings);
    
    Pizza* getArrayOfPizzasAtLocationWithSomeStatus(status status, Location location, int& sizeOfReturnPizzaList);
    
    void setOrderPaidValue(string fileName, int pureIndex, bool value);
    void setOrderDeliveredValue(string fileName, int pureIndex, bool value);
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
