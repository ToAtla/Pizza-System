//
//  main.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 28/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Order.hpp"

using namespace std;

void toppings();

int main(){
    int val1;
    cout << "Please choose department: "<< endl << endl;
    cout << "1: Management  "<< endl;
    cout << "2: Sales       " << endl;
    cout << "3: Baking      " << endl;
    cout << "4: Delivery    " << endl;

    do {
        cin >> val1;
    } while (val1 < 1 || val1 > 4);

    cout << endl;

    switch(val1){
        case 1 :
            cout << "1: Set base price for pizzas       " << endl;
            cout << "2: Register toppings and prices    " << endl;
        break;

        case 2 :
            cout << "1: Register an ordered pizza" << endl;
            
        break;

        case 3 :
            cout << "1: List of ordered pizzas" << endl;
            cout << "2: Set order in progress" << endl;

        break;

        case 4 :
            cout << "1: Mark ordered as paid     " << endl;
            cout << "2: Mark order as delivered  " << endl;

        break;


    }

    Order temp = Order();
    temp.setVerbose(true);
    cin >> temp;
     cout << temp;
    
    //toppings();

    return 0;
}


void toppings(){
    ofstream fout;

    fout.open("C:\\Users\\Andres\ Hardarson\\Documents\\GitHub\\Verklegt1\\PizzaKerfi\\PizzaKerfi\\ToppingsAndPrices.txt");
    fout << "Prufa numer 1 "<< endl;
    fout << "Prufa numer 2" << endl;
    fout.close();


}
