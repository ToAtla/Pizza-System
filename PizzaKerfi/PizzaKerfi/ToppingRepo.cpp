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
#include <vector>
#include <string>

using namespace std;

/*
 Skjalid toppings.txt er hardkodad.
 Viljum vid breyta tvi?
 */
ToppingRepo::ToppingRepo(){
    
}
void ToppingRepo::storeTopping(Topping& topping){
    
    ofstream fout;
    fout.open("toppings.txt", ios::app);
    topping.setVerbose(false);
    fout << topping;
    fout.close();
    topping.setVerbose(true);
    
}

Topping ToppingRepo::retrieveTopping(){
    
    ifstream fin;
    Topping temp;
    fin.open("toppings.txt");
    fin >> temp;
    fin.close();
    return temp;
}

vector<Topping> ToppingRepo::getVectorOfToppings(){
    vector<Topping> toppings;
    ifstream fin;
    fin.open("toppings.txt");
    while(!fin.eof()){
        Topping temp;
        fin >> temp;
        toppings.push_back(temp);
    }
    toppings.pop_back();
    return toppings;
}
