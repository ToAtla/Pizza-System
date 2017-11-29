//
//  OrderRepo.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef OrderRepo_hpp
#define OrderRepo_hpp

#include <stdio.h>
#include "Order.hpp"

class OrderRepo{
  
public:
    OrderRepo();
    void storeOrder(const Order& order);
    Order retrieveOrder();
    void displayOrder();
private:
    
};


#endif /* OrderRepo_hpp */
