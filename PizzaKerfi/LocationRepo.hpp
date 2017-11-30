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

using namespace std;

class LocationRepo{

public:
    LocationRepo();

    vector<string> displayLocations();

private:
    string name;


};

#endif  /* LocationRepo_hpp */
