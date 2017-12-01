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
    fout.open("bases.txt", ios::app);
    base.setVerbose(false);
    fout << base;
    fout.close();
    base.setVerbose(true);
}

//Skilar vector af öllum botnum sem eru í "bases.txt"
vector<Base> BaseRepo::getVectorOfBases(){
    
    vector<Base> bases;
    ifstream fin;
    fin.open("bases.txt");
    while(!fin.eof()){
        Base temp;
        temp.setVerbose(false);
        fin >> temp;
        temp.setVerbose(true);
        bases.push_back(temp);
    }
    bases.pop_back();
    return bases;
}

//Byrjar á því að tæma textaskránna "bases.txt"
//Tekur inn vector af bases og setur það inn í textaskránna.
void BaseRepo::storeVectorOfBases(vector<Base> bases){
    
    clearBases();
    
    ofstream fout;
    fout.open("bases.txt");
    for(int i = 0; i < bases.size(); i++){
        bases[i].setVerbose(false);
        fout << bases[i];
    }
    fout.close();
}


//Tæmir textaskránna "bases.txt"
void BaseRepo::clearBases()
{
    ofstream fout;
    fout.open("bases.txt");
    fout.close();
}

