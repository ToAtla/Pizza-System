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
    fout.open("sizes.txt", ios::app);
    size.setVerbose(false);
    fout << size;
    fout.close();
    size.setVerbose(true);
}

//Skilar vector af öllum meðlætum sem eru í "sizes.txt"
vector<Size> SizeRepo::getVectorOfSizes(){
    vector<Size> sizes;
    ifstream fin;
    fin.open("sizes.txt");
    while(!fin.eof()){
        Size temp;
        temp.setVerbose(false);
        fin >> temp;
        temp.setVerbose(true);
        sizes.push_back(temp);
    }
    sizes.pop_back();
    return sizes;
}

//Byrjar á því að tæma textaskránna "sizes.txt"
//Tekur inn vector af sizes og setur það inn í textaskránna.
void SizeRepo::storeVectorOfSizes(vector<Size> sizes){
    
    clearSizes();
    
    ofstream fout;
    fout.open("sizes.txt");
    for(int i = 0; i < sizes.size(); i++){
        sizes[i].setVerbose(false);
        fout << sizes[i];
    }
    fout.close();
}


//Tæmir textaskránna "sizes.txt"
void SizeRepo::clearSizes()
{
    ofstream fout;
    fout.open("sizes.txt");
    fout.close();
}
