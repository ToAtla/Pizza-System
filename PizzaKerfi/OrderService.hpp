//
//  OrderService.hpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 06/12/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef OrderService_hpp
#define OrderService_hpp

#include <stdio.h>
#include "OrderRepo.hpp"
class OrderService {
public:
    void setOrderPaidValue(string fileName, int pureIndex, bool value);
    void setOrderDeliveredValue(string fileName, int pureIndex, bool value);
private:
    OrderRepo orderRepo;
    
};

#endif /* OrderService_hpp */
