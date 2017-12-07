//
//  BaseRepo.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/1/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef BaseRepo_hpp
#define BaseRepo_hpp

#include <stdio.h>
#include <vector>
#include "Base.hpp"
#include "Global.hpp"

using namespace std;

class BaseRepo{
    public:
        BaseRepo();
        void addBase(Base& base);
        void displayBase();
        vector<Base> getVectorOfBases();
        void storeVectorOfBases(vector<Base> bases);
    private:
        void clearBases();
        void createBases();
};
#endif /* BaseRepo_hpp */
