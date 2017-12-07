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
#include "PizzaRepo.hpp"
#include "OrderRepo.hpp"
class Bizniz {
public:
    
    vector<Topping> getVectorOfToppings();
    void addTopping(Topping& topping);
    void storeVectorOfToppings(vector<Topping> toppings);
    
    Pizza* getArrayOfPizzasAtLocationWithSomeStatus(status status, Location location, int& sizeOfReturnPizzaList);
    
    void setOrderPaidValue(string fileName, int pureIndex, bool value);
    void setOrderDeliveredValue(string fileName, int pureIndex, bool value);
private:
    ToppingRepo toppingRepo;
    PizzaRepo pizzaRepo;
    OrderRepo orderRepo;
};

#endif /* Bizniz_hpp */
