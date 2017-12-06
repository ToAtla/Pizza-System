//
//  BaseRepo.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/1/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "BaseRepo.hpp"

//Færibreytulaus smiður.
BaseRepo::BaseRepo(){
    
}

//Bætir breytu af taginu Base inní textaskránna "bases.txt"
void BaseRepo::addBase(Base& base){
    ofstream fout;
    fout.open("bases.dat", ios::binary|ios::app);
    fout.write((char*)(&base), sizeof(Base));
    fout.close();
}

//Skilar vector af öllum botnum sem eru í "bases.txt"
vector<Base> BaseRepo::getVectorOfBases(){
    
    vector<Base> bases;
    ifstream fin;
    fin.open("bases.dat", ios::binary);
    
    fin.seekg(0, fin.end);
    int numberOfBases = (int)(fin.tellg() / sizeof(Base));
    fin.seekg(0, fin.beg);
    
    //Almennt gerum við svona.
    //fin.read((char*)(&drinks), sizeof(Drink)*numberOfDrinks);
    //En ekki í þessu tilviki
    //Því búið er að hanna klasan í kringum vektora
    
    for (int i = 0; i < numberOfBases; i++) {
        Base tempBase;
        fin.read((char*)(&tempBase), sizeof(Base));
        bases.push_back(tempBase);
    }
    return bases;
}

//Byrjar á því að tæma textaskránna "bases.txt"
//Tekur inn vector af bases og setur það inn í textaskránna.
void BaseRepo::storeVectorOfBases(vector<Base> bases){
    
    clearBases();
    
    ofstream fout;
    fout.open("bases.dat", ios::binary|ios::app);
    for(int i = 0; i < bases.size(); i++){
        Base tempBase = bases.at(i);
        fout.write((char*)(&tempBase), sizeof(Base));
    }
    fout.close();
}


//Tæmir textaskránna "bases.txt"
void BaseRepo::clearBases(){
    ofstream fout;
    fout.open("bases.dat", ios::binary);
    fout.close();
}

