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
#include "ToppingRepo.hpp"
#include "PizzaRepo.hpp"
#include "OrderRepo.hpp"
class Bizniz {
public:
    
    vector<Topping> getVectorOfToppings();
    void addTopping(Topping& topping);
    void storeVectorOfToppings(vector<Topping> toppings);
    
    Pizza* getArrayOfWaitingPizzas(int& sizeOfWaitingPizzaList);
    
    void setOrderPaidValue(string fileName, int pureIndex, bool value);
    void setOrderDeliveredValue(string fileName, int pureIndex, bool value);
private:
    
    ToppingRepo toppingRepo;
    PizzaRepo pizzaRepo;
    OrderRepo orderRepo;
};

#endif /* Bizniz_hpp */
