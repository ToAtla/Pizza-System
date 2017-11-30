//
//  DrinkRepo.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/30/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "DrinkRepo.hpp"

//Færibreytulaus smiður.
DrinkRepo::DrinkRepo(){
    
}

//Bætir breytu af taginu Drink inní textaskránna "drinks.txt"
void DrinkRepo::addDrink(Drink& drink){
    ofstream fout;
    fout.open("drinks.txt", ios::app);
    drink.setVerbose(false);
    fout << drink;
    fout.close();
    drink.setVerbose(true);
}

//Skilar vector af öllum meðlætum sem eru í "drinks.txt"
vector<Drink> DrinkRepo::getVectorOfDrinks(){
    
    vector<Drink> drinks;
    ifstream fin;
    fin.open("sides.txt");
    while(!fin.eof()){
        Drink temp;
        temp.setVerbose(false);
        fin >> temp;
        temp.setVerbose(true);
        drinks.push_back(temp);
    }
    drinks.pop_back();
    return drinks;
}

//Byrjar á því að tæma textaskránna "drinks.txt"
//Tekur inn vector af drinks og setur það inn í textaskránna.
void DrinkRepo::storeVectorOfDrinks(vector<Drink> drinks){
    
    clearDrinks();
    
    ofstream fout;
    fout.open("drinks.txt");
    for(int i = 0; i < drinks.size(); i++){
        drinks[i].setVerbose(false);
        fout << drinks[i];
    }
    fout.close();
}


//Tæmir textaskránna "sides.txt"
void DrinkRepo::clearDrinks()
{
    ofstream fout;
    fout.open("drinks.txt");
    fout.close();
}
