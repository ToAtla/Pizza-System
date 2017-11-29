//
//  ToppingRepo.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 29/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "ToppingRepo.hpp"
#include "Topping.hpp"
#include <fstream>
#include <iostream>

using namespace std;

/*
 Skjalid toppings.txt er hardkodad.
 Viljum vid breyta tvi?
 */
ToppingRepo::ToppingRepo(){
    
}
void ToppingRepo::storeTopping(const Topping& topping){
    
    ofstream fout;
    fout.open("toppings.txt", ios::app);
    fout << topping;
    fout.close();
}

Topping ToppingRepo::retrieveTopping(){
    
    ifstream fin;
    Topping temp;
    fin.open("toppings.txt");
    fin >> temp;
    fin.close();
    return temp;
}

//Vandinn við þetta er að við erum að blanda saman UI og Vinnslulagi
void ToppingRepo::displayToppings(){
    ifstream fin;
    fin.open("toppings.txt");
    while(!fin.eof()){
        Topping temp = retrieveTopping();
        cout << "A topping:" << endl;
        cout << temp;
    }
}
