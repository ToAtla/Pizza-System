//
//  InvalidFileSizeBaseException.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/10/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "InvalidFileSizeBaseException.hpp"

InvalidFileSizeBaseException::InvalidFileSizeBaseException(string message){
    this->message = message;
}

string InvalidFileSizeBaseException::getMessage(){
    return message;
}
