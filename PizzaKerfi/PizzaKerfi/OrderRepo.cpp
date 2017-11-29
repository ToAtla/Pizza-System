//
//  OrderRepo.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "OrderRepo.hpp"

OrderRepo::OrderRepo(){
    
}

void OrderRepo::storeOrder(const Order& order){
    ofstream fout;
    fout.open("toppings.txt", ios::app);
    fout << order;
    fout.close();
}

Order OrderRepo::retrieveOrder(){
    Order order;
    
    return order;
}

void OrderRepo::displayOrder(){
    
}
