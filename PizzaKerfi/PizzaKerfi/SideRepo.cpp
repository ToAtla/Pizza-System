//
//  SideRepo.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/30/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "SideRepo.hpp"

//Færibreytulaus smiður.
SideRepo::SideRepo(){
    
}

//Bætir breytu af taginu Side inní textaskránna "toppings.txt"
void SideRepo::addSide(Side& side){
    ofstream fout;
    fout.open("sides.dat", ios::binary|ios::app);
    fout.write((char*)(&side), sizeof(Side));
    fout.close();
}

//Skilar vector af öllum meðlætum sem eru í "sides.txt"
vector<Side> SideRepo::getVectorOfSides(){
    
    createSides();
    
    vector<Side> sides;
    ifstream fin;
    fin.open("sides.dat", ios::binary);
    
    fin.seekg(0, fin.end);
    int numberOfSides = (int)(fin.tellg() / sizeof(Side));
    fin.seekg(0, fin.beg);
    
    //Almennt gerum við svona.
    //fin.read((char*)(&drinks), sizeof(Drink)*numberOfDrinks);
    //En ekki í þessu tilviki
    //Því búið er að hanna klasan í kringum vektora
    
    for (int i = 0; i < numberOfSides; i++) {
        Side tempSide;
        fin.read((char*)(&tempSide), sizeof(Side));
        sides.push_back(tempSide);
    }
    return sides;
}

//Byrjar á því að tæma textaskránna "sides.txt"
//Tekur inn vector af sides og setur það inn í textaskránna.
void SideRepo::storeVectorOfSides(vector<Side> sides){
    
    
    clearSides();
    
    ofstream fout;
    fout.open("sides.dat", ios::binary|ios::app);
    for(int i = 0; i < sides.size(); i++){
        Side tempSide = sides.at(i);
        fout.write((char*)(&tempSide), sizeof(Side));
    }
    fout.close();
}


//Tæmir textaskránna "sides.txt"
void SideRepo::clearSides(){
    ofstream fout;
    fout.open("sides.dat", ios::binary);
    fout.close();
}

void SideRepo::createSides(){
    ofstream fout;
    fout.open("sides.dat", ios::binary);
    fout.close();
}

