//
//  LocationRepo.hpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 30/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef LocationRepo_hpp
#define LocationRepo_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Location.hpp"
#include "Global.hpp"

using namespace std;

class LocationRepo{

    public:
        LocationRepo();
        void displayLocations();
        vector<Location>getVectorOfLocations();
        void storeVectorOfLocations(vector<Location> locations);
        void storeLocation(Location& location);

    private:
        void clearLocations();


};

#endif  /* LocationRepo_hpp */
