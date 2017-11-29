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

void ToppingRepo::storeTopping(const Topping& topping){
    
    ofstream fout;
    fout.open("toppings.txt");
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
