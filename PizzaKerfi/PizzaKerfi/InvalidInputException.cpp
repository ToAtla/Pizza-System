//
//  InvalidInputException.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/9/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "InvalidInputException.hpp"

InvalidInputException::InvalidInputException(string message){
    
    this->message = message;
}

string InvalidInputException::getMessage(){
    
    return message;
}
