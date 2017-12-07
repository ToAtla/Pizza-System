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
#include "OrderRepo.hpp"
#include "ToppingRepo.hpp"

class Bizniz {
public:
    
    vector<Topping> getVectorOfToppings();
    
    
    
    
    void setOrderPaidValue(string fileName, int pureIndex, bool value);
    void setOrderDeliveredValue(string fileName, int pureIndex, bool value);
private:
    OrderRepo orderRepo;
    ToppingRepo toppingRepo;
};

#endif /* Bizniz_hpp */
