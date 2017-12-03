//
//  DeliveryUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "DeliveryUI.hpp"
#include <iostream>

using namespace std;

void DeliveryUI::startDeliveryUI(){
    char input = '\0';
    while(input != 'b'){
        cout << "1: some" << endl;
        cout << "2: delivery" << endl;
        cout << "3: options" << endl;
        cout << "4: BROKEN" << endl;
        cout << "b: back" << endl;
        cin >> input;
        cout << endl;
        
        if(input == '1'){
        }
        else if(input == '2'){
        }
        else if(input == '3'){
        }
        else if(input == '4'){
        }
    }
    
}
