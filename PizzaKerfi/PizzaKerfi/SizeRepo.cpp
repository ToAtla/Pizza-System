//
//  SizeRepo.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/1/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "SizeRepo.hpp"

//Færibreytulaus smiður.
SizeRepo::SizeRepo(){
    
}

//Bætir breytu af taginu Size inní textaskránna "sizes.txt"
void SizeRepo::addSize(Size& size){
    ofstream fout;
    fout.open("sizes.dat", ios::binary|ios::app);
    fout.write((char*)(&size), sizeof(Size));
    fout.close();
}

//Skilar vector af öllum meðlætum sem eru í "sizes.txt"
vector<Size> SizeRepo::getVectorOfSizes(){
    vector<Size> sizes;
    ifstream fin;
    fin.open("sizes.dat", ios::binary);
    
    fin.seekg(0, fin.end);
    int numberOfSizes = (int)(fin.tellg() / sizeof(Size));
    fin.seekg(0, fin.beg);
    
    //Almennt gerum við svona.
    //fin.read((char*)(&drinks), sizeof(Drink)*numberOfDrinks);
    //En ekki í þessu tilviki
    //Því búið er að hanna klasan í kringum vektora
    
    for (int i = 0; i < numberOfSizes; i++) {
        Size tempSize;
        fin.read((char*)(&tempSize), sizeof(Size));
        sizes.push_back(tempSize);
    }
    return sizes;
}

//Byrjar á því að tæma textaskránna "sizes.txt"
//Tekur inn vector af sizes og setur það inn í textaskránna.
void SizeRepo::storeVectorOfSizes(vector<Size> sizes){
    
    clearSizes();
    
    ofstream fout;
    fout.open("sizes.dat", ios::binary|ios::app);
    for(int i = 0; i < sizes.size(); i++){
        Size tempSize = sizes.at(i);
        fout.write((char*)(&tempSize), sizeof(Size));
    }
    fout.close();
}


//Tæmir textaskránna "sizes.txt"
void SizeRepo::clearSizes()
{
    ofstream fout;
    fout.open("sizes.dat", ios::binary);
    fout.close();
}
