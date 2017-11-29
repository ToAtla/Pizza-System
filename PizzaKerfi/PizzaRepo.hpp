//
//  PizzaRepo.hpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 29/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef PizzaRepo_hpp
#define PizzaRepo_hpp

#include <stdio.h>
#include "Pizza.hpp"

class PizzaRepo {
public:
    void storePizza(const Pizza& pizza);
    Pizza retrievePizza();
private:
};

#endif /* PizzaRepo_hpp */
