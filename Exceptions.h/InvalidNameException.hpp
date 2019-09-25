//
//  InvalidNameException.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/9/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef InvalidNameException_hpp
#define InvalidNameException_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class InvalidNameException{
    
    public:
        InvalidNameException(string message);
        string getMessage();
    private:
        string message;
};


#endif /* InvalidNameException_hpp */
