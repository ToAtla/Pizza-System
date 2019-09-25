//
//  MainUI.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef MainUI_hpp
#define MainUI_hpp

#include <stdio.h>
#include "Global.hpp"
#include "AdminUI.hpp"
#include "PrepUI.hpp"
#include "SalesUI.hpp"
#include "DeliveryUI.hpp"
#include "LocationRepo.hpp"
#include "Location.hpp"
#include "ConsoleMagic.hpp"
#include "Order.hpp"

class MainUI{
    
    public:
        void startUI();
    private:
        ConsoleMagic magic;
};



#endif /* MainUI_hpp */
