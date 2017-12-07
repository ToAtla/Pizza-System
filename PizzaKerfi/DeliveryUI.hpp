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
#include "Bizniz.hpp"
#include "Global.hpp"

class DeliveryUI{
public:
    void startDeliveryUI();
    void chooseYourLocation();
    void displayUnpaidOrders();
    void displayPaidOrders();
    void displayAllOrders();
    void displayLegacyOrders();
private:
    Bizniz bizniz;
    Location locationOfDelivery;
};

#endif /* DeliveryUI_hpp */
