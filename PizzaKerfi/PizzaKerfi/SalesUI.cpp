//
//  SalesUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "SalesUI.hpp"

void SalesUI::startSalesUI(){
    
    char input = 0;
    while(input != 'b')
    {
        cout << "1: Create a orders BROKEN" << endl;
        cout << "2: View all orders BROKEN" << endl;
        cout << "3: Change a order BROKEN" << endl;
        cout << "3: delete a order BROKEN" << endl;
        cin >> input;
        if(input == '1')
        {
            createOrder();
        }
        else if(input == '2')
        {
            
        }
        else if(input == '3')
        {
            
        }
        else if(input == '4')
        {
            
        }
    }
}

void SalesUI::createOrder(){
    
}
