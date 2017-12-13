//
//  InvalidInputException.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/9/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef InvalidInputException_hpp
#define InvalidInputException_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class InvalidInputException {
    
    public:
        InvalidInputException(string message);
        string getMessage();
    private:
        string message;
};

#endif /* InvalidInputException_hpp */
