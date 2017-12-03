//
//  PizzaRepo.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 29/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "PizzaRepo.hpp"
#include <fstream>

using namespace std;

void PizzaRepo::storePizza(const Pizza& pizza, string fileName){
    
    ofstream fout;
    
    fout.open(fileName, ios::binary|ios::app);
    fout.write((char*)(&pizza), sizeof(Pizza));
    fout.close();
}

Pizza PizzaRepo::retrievePizza(){
    
    ifstream fin;
    Pizza returnPizza;
    fin.open("pizzas.dat", ios::binary);
    fin.read((char*)(&returnPizza), sizeof(Pizza));
    fin.close();
    return returnPizza;
}


Pizza* PizzaRepo::retrievePizzaArray(string fileName, int& tellMeHowMany){
    Pizza pizzas[MAXPIZZASINPIZZAFILE];
    ifstream fin;
    fin.open(fileName, ios::binary);
    fin.seekg(0, fin.end);
    tellMeHowMany = fin.tellg()/sizeof(Pizza);
    fin.seekg(0, fin.beg);
    fin.read((char*)(pizzas), sizeof(Pizza)*tellMeHowMany);
    fin.close();
    return pizzas;
};

void PizzaRepo::moveBetween(string sourceFile, string destFile, int index){
    //retrieve from source
    
    //remove from source
    
    //append to dest
    
}
