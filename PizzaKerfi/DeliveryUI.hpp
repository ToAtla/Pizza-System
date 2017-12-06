//
//  DeliveryUI.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef DeliveryUI_hpp
#define DeliveryUI_hpp


#include <stdio.h>
#include "ConsoleMagic.hpp"
#include "OrderService.hpp"
#include "LocationRepo.hpp"
#include "Location.hpp"

class DeliveryUI{
public:
    void chooseYourLocation();
    void startDeliveryUI();
    void displayUnpaidOrders();
    void displayPaidOrders();
    void displayAllOrders();
    void displayLegacyOrders();
private:
    OrderService orderService;
    Location locationOfDelivery;
};

#endif /* DeliveryUI_hpp */
