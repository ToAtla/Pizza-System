//
//  InvalidPriceException.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/9/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef InvalidPriceException_hpp
#define InvalidPriceException_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class InvalidPriceException {
    
    public:
        InvalidPriceException(string message);
        string getMessage();
    private:
        string message;
};
#endif /* InvalidPriceException_hpp */
