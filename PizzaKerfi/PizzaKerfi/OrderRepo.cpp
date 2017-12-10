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
    fout.open(ORDERFILE, ios::binary|ios::app);
    fout.write((char*)(&order), sizeof(Order));
    fout.close();
}


Order* OrderRepo::retrieveOrderArray(string fileName, int& tellMeHowManyOrders){
    
    ifstream fin;
    fin.open(fileName, ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        tellMeHowManyOrders = (int)(fin.tellg() / sizeof(Order));
        fin.seekg(0, fin.beg);
        Order* orderList = new Order[tellMeHowManyOrders];
        fin.read((char*)(orderList), sizeof(Order)*tellMeHowManyOrders);
        fin.close();
        return orderList;
    }else{
        tellMeHowManyOrders = 0;
        Order* orderList = NULL;
        return orderList;
    }
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

