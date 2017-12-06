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
    fout.open("drinks.dat", ios::binary|ios::app);
    fout.write((char*)(&drink), sizeof(Drink));
    fout.close();
}

//Skilar vector af öllum meðlætum sem eru í "drinks.txt"
vector<Drink> DrinkRepo::getVectorOfDrinks(){
    
    vector<Drink> drinks;
    ifstream fin;
    fin.open("drinks.dat", ios::binary);
    
    fin.seekg(0, fin.end);
    int numberOfDrinks = (int)(fin.tellg() / sizeof(Drink));
    fin.seekg(0, fin.beg);
    
    //fin.read((char*)(&drinks), sizeof(Drink)*numberOfDrinks);
    
    //EÐA
    
    for (int i = 0; i < numberOfDrinks; i++) {
        Drink tempDrink;
        fin.read((char*)(&tempDrink), sizeof(Drink));
        drinks.push_back(tempDrink);
    }
    /*
    fin.open("drinks.txt");
    while(!fin.eof()){
        Drink temp;
        temp.setVerbose(false);
        fin >> temp;
        temp.setVerbose(true);
        drinks.push_back(temp);
    }
    */
    //drinks.pop_back();
    return drinks;
}

//Byrjar á því að tæma textaskránna "drinks.txt"
//Tekur inn vector af drinks og setur það inn í textaskránna.
void DrinkRepo::storeVectorOfDrinks(vector<Drink> drinks){
    
    clearDrinks();
    
    ofstream fout;
    fout.open("drinks.dat", ios::binary|ios::app);
    for(int i = 0; i < drinks.size(); i++){
        Drink tempDrink = drinks.at(i);
        fout.write((char*)(&tempDrink), sizeof(Drink));
    }
    fout.close();
}


//Tæmir textaskránna "sides.txt"
void DrinkRepo::clearDrinks(){
    ofstream fout;
    fout.open("drinks.dat", ios::binary);
    fout.close();
}
