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
    
    fout.open("pizzas.txt");
    fout << pizza;
    fout.close();
}

using namespace std;

Pizza PizzaRepo::retrievePizza(){
    
    ifstream fin;
    Pizza temp;
    fin.open("pizzas.txt");
    fin >> temp;
    fin.close();
    return temp;
}
