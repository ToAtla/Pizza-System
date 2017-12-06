//
//  OrderService.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 06/12/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "OrderService.hpp"

void OrderService::setOrderPaidValue(string fileName, int pureIndex, bool value){
    int size;
    Order* orders = orderRepo.retrieveOrderArray(fileName, size);
    orders[pureIndex].setPaid(value);
    orderRepo.clearOrderFile(fileName);
    for (int i = 0; i < size; i++) {
        orderRepo.storeOrder(orders[i]);
    }
}
