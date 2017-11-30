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
    temp.setVerbose(false);
    fin >> temp;
    fin.close();
    temp.setVerbose(true);
    return temp;
}

vector<Topping> ToppingRepo::getVectorOfToppings(){
    vector<Topping> toppings;
    ifstream fin;
    fin.open("toppings.txt");
    while(!fin.eof()){
        Topping temp;
        temp.setVerbose(false);
        fin >> temp;
        temp.setVerbose(true);
        toppings.push_back(temp);
    }
    toppings.pop_back();
    return toppings;
}

void ToppingRepo::storeVectorOfToppings(vector<Topping> toppings){
    
    ofstream fout;
    
    fout.open("toppings.txt");
    fout.close();
    
    fout.open("toppings.txt");
    for(int i = 0; i < toppings.size(); i++){
        toppings[i].setVerbose(false);
        fout << toppings[i];
    }
    fout.close();
    
}
