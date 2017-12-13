//
//  InvalidFileSizeBaseException.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/10/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef InvalidFileSizeBaseException_hpp
#define InvalidFileSizeBaseException_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class InvalidFileSizeBaseException{
    
    public:
        InvalidFileSizeBaseException(string message);
        string getMessage();
    private:
        string message;
};

#endif /* InvalidFileSizeBaseException_hpp */
