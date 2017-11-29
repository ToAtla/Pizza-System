//
//  ToppingRepo.hpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 29/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef ToppingRepo_hpp
#define ToppingRepo_hpp

#include <stdio.h>
#include "Topping.hpp"

class ToppingRepo{
public:
    ToppingRepo();
    void storeTopping(const Topping& topping);
    Topping retrieveTopping();
    void displayToppings();
private:
};

#endif /* ToppingRepo_hpp */

