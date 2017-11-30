//
//  Location.hpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 29/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef Location_hpp
#define Location_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Location{
public:

     Location();
        Location (string name);
        virtual ~Location();

        void setLocation();
        void writeToFile();
        void displayLocations();

private:
    string name;
};

#endif /* Location_hpp */
