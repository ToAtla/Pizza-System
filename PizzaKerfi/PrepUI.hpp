//
//  PrepUI.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef PrepUI_hpp
#define PrepUI_hpp

#include <stdio.h>
#include "Global.hpp"
#include "LocationRepo.hpp"
#include "Bizniz.hpp"

class PrepUI{
public:
    void startPrepUI();
    void chooseYourLocation();
private:
    void waitingOverview();
    void preppingOverview();
    void readyOverview();
    Location locationOfPrep;
    Bizniz bizniz;
};
#endif /* PrepUI_hpp */
