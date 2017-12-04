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
const int MAXCHARINLOC = 20;

class Location{
    public:
        Location();
        string getLocation();
        void setName(char inName[]);
        friend istream& operator >> (istream& in, Location& Location);
        friend ostream& operator << (ostream& out, const Location& Location);
    private:
        char name[MAXCHARINLOC];
};

#endif /* Location_hpp */
