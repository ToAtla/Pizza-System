//
//  SizeRepo.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/1/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef SizeRepo_hpp
#define SizeRepo_hpp

#include <stdio.h>

#include <vector>
#include "Size.hpp"

using namespace std;

class SizeRepo{
public:
    SizeRepo();
    void addSize(Size& size);
    void displaySizes();
    vector<Size> getVectorOfSizes();
    void storeVectorOfSizes(vector<Size> sizes);
private:
    void clearSizes();
};

#endif /* SizeRepo_hpp */
