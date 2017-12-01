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

//Færibreytulaus smiður.
ToppingRepo::ToppingRepo(){
    
}

//Bætir breytu af taginu topping inní textaskránna "toppings.txt"
void ToppingRepo::addTopping(Topping& topping){
    ofstream fout;
    fout.open("toppings.txt", ios::app);
    topping.setVerbose(false);
    fout << topping;
    fout.close();
    topping.setVerbose(true);
}

//Skilar fyrsta alegginu út textaskránni.
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

//Skilar vector af öllum toppings sem eru í "toppings.txt"
vector<Topping> ToppingRepo::getVectorOfToppings(){
    
    //
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

//Byrjar á því að tæma textaskránna "toppings.txt"
//Tekur inn vector af toppings og setur það inn í textaskránna.
void ToppingRepo::storeVectorOfToppings(vector<Topping> toppings){
    
    clearToppings();

    ofstream fout;
    fout.open("toppings.txt");
    for(int i = 0; i < toppings.size(); i++){
        toppings[i].setVerbose(false);
        fout << toppings[i];
    }
    fout.close();
}


//Tæmir textaskránna "toppings.txt"
void ToppingRepo::clearToppings()
{
    ofstream fout;
    fout.open("toppings.txt");
    fout.close();
}
