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
#include "Global.hpp"

class PizzaRepo {
public:
    void storePizza(const Pizza& pizza, string fileName);
    Pizza retrievePizza(string fileName, int index);
    Pizza* retrievePizzaArray(string fileName, int& tellMeHowMany);
    void moveBetween(string sourceFile, string destFile, int index);
    void clearPizzaFile(string fileName);
    bool fileExists(string fileName);
private:
};

#endif /* PizzaRepo_hpp */
