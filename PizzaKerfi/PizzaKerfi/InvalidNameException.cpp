//
//  InvalidNameException.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/9/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "InvalidNameException.hpp"


InvalidNameException::InvalidNameException(string message){
    
    this->message = message;
    
}

string InvalidNameException::getMessage(){
    return message;
}
