//
//  SideRepo.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/30/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef SideRepo_hpp
#define SideRepo_hpp

#include <stdio.h>

#include <vector>
#include "Side.hpp"

using namespace std;

class SideRepo{
    public:
        SideRepo();
        void addSide(Side& Side);
        void displaySides();
        vector<Side> getVectorOfSides();
        void storeVectorOfSides(vector<Side> sides);
    private:
        void clearSides();
};

#endif /* SideRepo_hpp */
