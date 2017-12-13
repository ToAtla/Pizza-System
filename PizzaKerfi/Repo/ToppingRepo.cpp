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

//Bætir breytu af taginu topping inní textaskránna "toppings.txt"
void ToppingRepo::addTopping(Topping& topping){
    ofstream fout;
    fout.open("toppings.dat", ios::binary|ios::app);
    fout.write((char*)(&topping), sizeof(Topping));
    fout.close();
}

//Skilar fyrsta alegginu út textaskránni.
Topping ToppingRepo::retrieveTopping(){
    
    createToppings();
    
    ifstream fin;
    Topping temp;
    fin.open("toppings.dat", ios::binary);
    fin.read((char*)(&temp), sizeof(Topping));
    fin.close();
    return temp;
}

//Skilar vector af öllum toppings sem eru í "toppings.txt"
vector<Topping> ToppingRepo::getVectorOfToppings(){
    
    createToppings();
    
    vector<Topping> toppings;
    ifstream fin;
    fin.open("toppings.dat", ios::binary);
    
    fin.seekg(0, fin.end);
    int numberOfToppings = (int)(fin.tellg() / sizeof(Topping));
    fin.seekg(0, fin.beg);
    
    //Almennt gerum við svona.
    //fin.read((char*)(&drinks), sizeof(Drink)*numberOfDrinks);
    //En ekki í þessu tilviki
    //Því búið er að hanna klasan í kringum vektora
    
    for (int i = 0; i < numberOfToppings; i++) {
        Topping tempTopping;
        fin.read((char*)(&tempTopping), sizeof(Topping));
        toppings.push_back(tempTopping);
    }
    return toppings;

}

//Byrjar á því að tæma textaskránna "toppings.txt"
//Tekur inn vector af toppings og setur það inn í textaskránna.
void ToppingRepo::storeVectorOfToppings(vector<Topping> toppings){
    
    clearToppings();
    
    ofstream fout;
    fout.open("toppings.dat", ios::binary|ios::app);
    for(int i = 0; i < toppings.size(); i++){
        Topping tempTopping = toppings.at(i);
        fout.write((char*)(&tempTopping), sizeof(Topping));
    }
    fout.close();
}

//Tæmir textaskránna "toppings.txt"
void ToppingRepo::clearToppings()
{
    ofstream fout;
    fout.open("toppings.dat", ios::binary);
    fout.close();
}

//Býr til textaskránna "toppings.txt" ef að hún er ekki til nú þegar.
void ToppingRepo::createToppings(){
    ofstream fout;
    fout.open("toppings.dat", ios::binary|ios::app);
    fout.close();
}
