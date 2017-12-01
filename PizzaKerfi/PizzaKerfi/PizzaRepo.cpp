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

void PizzaRepo::storePizza(const Pizza& pizza){
    
    ofstream fout;
    
    fout.open("pizzas.dat", ios::binary|ios::app);
    
    fout.write((char*)(&pizza), sizeof(Pizza));
    fout.close();
}

using namespace std;

Pizza PizzaRepo::retrievePizza(){
    
    ifstream fin;
    Pizza returnPizza;
    fin.open("pizzas.dat");
    fin.read((char*)(&returnPizza), sizeof(Pizza));
    fin.close();
    return returnPizza;
}
