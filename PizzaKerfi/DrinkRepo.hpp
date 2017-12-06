//
//  DrinkRepo.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/30/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef DrinkRepo_hpp
#define DrinkRepo_hpp

#include <stdio.h>
#include <vector>
#include "Drink.hpp"
#include "Global.hpp"

using namespace std;

class DrinkRepo{
    public:
        DrinkRepo();
        void addDrink(Drink& drink);
        void displayDrinks();
        vector<Drink> getVectorOfDrinks();
        void storeVectorOfDrinks(vector<Drink> drinks);
    private:
        void clearDrinks();
};

#endif /* DrinkRepo_hpp */
