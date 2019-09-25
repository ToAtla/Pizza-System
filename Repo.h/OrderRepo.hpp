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
#include <fstream>
#include "Order.hpp"
#include "Global.hpp"

class OrderRepo{

    public:
    void storeOrder(const Order& order);
    void storeOrder(const Order& order, string fileName);
    Order* retrieveOrderArray(string fileName, int& tellMeHowManyOrders);
    bool fileExists(string fileName);
    void clearOrderFile(string fileName);
    private:
    
};


#endif /* OrderRepo_hpp */
