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
    fout.open("orders.dat", ios::binary|ios::app);
    fout.write((char*)(&order), sizeof(Order));
    fout.close();
}

Order OrderRepo::retrieveOrder(){
    Order order;
    
    return order;
}








Order* OrderRepo::retrieveOrderArray(int& tellMeHowManyOrders){
    Order orderList[MAXSTUFFSINORDER];
    ifstream fin;
    fin.open("orders.dat", ios::binary);
    fin.seekg(0, fin.end);
    tellMeHowManyOrders = fin.tellg() / sizeof(Order);
    fin.seekg(0, fin.beg);
    fin.read((char*)(orderList), sizeof(Order)*tellMeHowManyOrders);
    fin.close();
    return orderList;
}

