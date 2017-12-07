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

Order* OrderRepo::retrieveOrderArray(string fileName, int& tellMeHowManyOrders){
    Order orderList[MAXSTUFFSINORDER];
    ifstream fin;
    fin.open(fileName, ios::binary);
    fin.seekg(0, fin.end);
    tellMeHowManyOrders = (int)(fin.tellg() / sizeof(Order));
    fin.seekg(0, fin.beg);
    fin.read((char*)(orderList), sizeof(Order)*tellMeHowManyOrders);
    fin.close();
    return orderList;
}

bool OrderRepo::fileExists(string fileName){
    ifstream fin;
    fin.open(fileName);
    bool returnValue = fin.is_open();
    fin.close();
    return returnValue;
}

void OrderRepo::clearOrderFile(string fileName){
    ofstream fout;
    fout.open(fileName);
    fout.close();
}
