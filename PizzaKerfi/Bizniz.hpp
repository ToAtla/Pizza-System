//
//  Bizniz.hpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 07/12/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef Bizniz_hpp
#define Bizniz_hpp

#include <stdio.h>
#include "OrderRepo.hpp"

class Bizniz {
public:
    void setOrderPaidValue(string fileName, int pureIndex, bool value);
    void setOrderDeliveredValue(string fileName, int pureIndex, bool value);
private:
    OrderRepo orderRepo;
};

#endif /* Bizniz_hpp */
