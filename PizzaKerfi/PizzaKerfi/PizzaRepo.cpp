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

Pizza PizzaRepo::retrievePizza(string fileName, int index){
    Pizza returnPizza;
    int size;
    Pizza* pizzaList = retrievePizzaArray(fileName, size);
    //Þetta er gert til að koma í veg fyrir out of bounds villu
    if(index < size){
        returnPizza = pizzaList[index];
    }
    return returnPizza;
}


Pizza* PizzaRepo::retrievePizzaArray(string fileName, int& tellMeHowMany){
    Pizza pizzas[MAXPIZZASINPIZZAFILE];
    ifstream fin;
    fin.open(fileName, ios::binary);
    fin.seekg(0, fin.end);
    tellMeHowMany = (int)(fin.tellg()/sizeof(Pizza));
    fin.seekg(0, fin.beg);
    fin.read((char*)(pizzas), sizeof(Pizza)*tellMeHowMany);
    fin.close();
    return pizzas;
};

void PizzaRepo::moveBetween(string sourceFile, string destFile, int index){
    //retrieve from source
    Pizza tempPizza = retrievePizza(sourceFile, index);
    //remove from source
    
    //sækja allar pizzur
    int sizeOfSourceFile;
    Pizza* pizzaList = retrievePizzaArray(sourceFile, sizeOfSourceFile);
    
    //eyða öllu í skjalinu
    clearPizzaFile(sourceFile);
    //Bæta öllu við fram að index
    //Og halda áfram eftir index í i+1
    for (int i = 0; i < sizeOfSourceFile-1; i++) {
        if(i < index){
            storePizza(pizzaList[i], sourceFile);
        }else{
            storePizza(pizzaList[i+1], sourceFile);
        }
    }
    //append to dest
    storePizza(tempPizza, destFile);
}

void PizzaRepo::clearPizzaFile(string fileName){
    ofstream fout;
    fout.open(fileName, ios::binary);
    fout.close();
}

bool PizzaRepo::fileExists(string fileName){
    ifstream fin;
    fin.open(fileName);
    bool returnValue = fin.is_open();
    fin.close();
    return returnValue;
}
