//
//  InvalidPriceException.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/9/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "InvalidPriceException.hpp"

InvalidPriceException::InvalidPriceException(string message){
    
    this->message = message;
}

string InvalidPriceException::getMessage(){
    
    return message;
}
