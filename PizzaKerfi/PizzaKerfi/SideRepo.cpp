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
    fout.open("sides.txt", ios::app);
    side.setVerbose(false);
    fout << side;
    fout.close();
    side.setVerbose(true);
}

//Skilar vector af öllum meðlætum sem eru í "sides.txt"
vector<Side> SideRepo::getVectorOfSides(){
    
    vector<Side> sides;
    ifstream fin;
    fin.open("sides.txt");
    while(!fin.eof()){
        Side temp;
        temp.setVerbose(false);
        fin >> temp;
        temp.setVerbose(true);
        sides.push_back(temp);
    }
    sides.pop_back();
    return sides;
}

//Byrjar á því að tæma textaskránna "sides.txt"
//Tekur inn vector af sides og setur það inn í textaskránna.
void SideRepo::storeVectorOfToppings(vector<Side> sides){
    
    clearSides();
    
    ofstream fout;
    fout.open("sides.txt");
    for(int i = 0; i < sides.size(); i++){
        sides[i].setVerbose(false);
        fout << sides[i];
    }
    fout.close();
}


//Tæmir textaskránna "sides.txt"
void SideRepo::clearSides()
{
    ofstream fout;
    fout.open("sides.txt");
    fout.close();
}
