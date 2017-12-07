//
//  Bizniz.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 07/12/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "Bizniz.hpp"


/**************************************************************************************
 
                                    TOPPINGS
 
 ***************************************************************************************/
 

vector<Topping> Bizniz::getVectorOfToppings(){
    
    vector<Topping> toppings;
    toppings = toppingRepo.getVectorOfToppings();
    
    return toppings;
}

void Bizniz::addTopping(Topping& topping){
   
    toppingRepo.addTopping(topping);
    
}

void Bizniz::storeVectorOfToppings(vector<Topping> toppings){
    
    toppingRepo.storeVectorOfToppings(toppings);
}




/**************************************************************************************
 
                                    LOCATIONS
 
 ***************************************************************************************/
/*vector<Location> bizniz::getVectorOfLocations(){
    vector<Topping> toppings;
    toppings = toppingRepo.getVectorOfToppings();
    
    return toppings;
    
}
void addLocation(Location& location){
    
    
}
void storeVectorOfLocations(vector<Location> locations){
    
    
}



*/
/**************************************************************************************
 
                                    SIDES
 
 ***************************************************************************************/
/*vector<Side> getVectorOfSides(){
    vector<Topping> toppings;
    toppings = toppingRepo.getVectorOfToppings();
    
    return toppings;
    
}
void addTopping(Side& side){
    
    
}
void storeVectorOfToppings(vector<Side> sides){
    
    
}



*/
/**************************************************************************************
 
                                    DRINKS
 
 ***************************************************************************************/
/*vector<Drink> getVectorOfDrinks(){
    vector<Topping> toppings;
    toppings = toppingRepo.getVectorOfToppings();
    
    return toppings;
    
}

void addTopping(Drink& drink){
    
    
}

void storeVectorOfToppings(vector<Drink> drinks){
    
    
}


*/
/**************************************************************************************
 
                                    SIZES
 
 ***************************************************************************************/
/*vector<Size> getVectorOfSizes(){
    vector<Topping> toppings;
    toppings = toppingRepo.getVectorOfToppings();
    
    return toppings;
    
}

void addSize(Size& size){
    
    
}

void storeVectorOfToppings(vector<Size> sizes){
    
    
}



/**************************************************************************************
 
                                    BASES
 
 ***************************************************************************************/
/*vector<Base> getVectorOfBases(){
    vector<Topping> toppings;
    toppings = toppingRepo.getVectorOfToppings();
    
    return toppings;
    
}

void addBase(Base& base){
    
    
}

void storeVectorOfbases(vector<Base> bases){
    
    
}
*/





/**************************************************************************************
 
                                    PIZZA
 
 ***************************************************************************************/


Pizza* Bizniz::getArrayOfWaitingPizzas(int &sizeOfWaitingPizzaList){
    
    int sizeOfEntirePizzaList;
    Pizza* allPizzas = pizzaRepo.retrievePizzaArray(PIZZAFILE, sizeOfEntirePizzaList);
    Pizza* waitPizzas;
    sizeOfWaitingPizzaList = 0;
    for (int i = 0; i < sizeOfEntirePizzaList; i++) {
        if((allPizzas[i].getStatus()) == WAITING){
            waitPizzas[sizeOfWaitingPizzaList] = allPizzas[i];
            sizeOfWaitingPizzaList++;
        }
    }
    return waitPizzas;
    
    
    
    
    
    
    
    
    
    /*
    
    
    string waitFile = "waiting.dat";
    string prepFile = "prepping.dat";
    PizzaRepo pr;

    int sizeOfWaitingPizzaList;
    int sizeOfWaitingPizzaListLocation;
    Pizza* waitPizzas = pr.retrievePizzaArray(waitFile, sizeOfWaitingPizzaList);
    Pizza* waitPizzasInLocation;

    cout << " - - - - Pizzas not yet started - - - - " << endl;

    if(pr.fileExists(waitFile) && sizeOfWaitingPizzaList != 0){
        
        /*   for(int i = 0; i < sizeOfWaitingPizzaList; i++){
         if(waitPizzas[i].getLocation().getLocation() == locationOfPrep.getLocation()){
         sizeOfWaitingPizzaListLocation++;
         waitPizzasInLocation[sizeOfWaitingPizzaListLocation] = waitPizzas[i];
         }
         }
         /
        for (int i = 0; i < sizeOfWaitingPizzaList; i++) {
            cout << "[" << i+1 << "] " << waitPizzas[i] << endl;
        }
        cout << endl;
        int input = '\0';
        while(input != '0'){
            cout << "Pick a number to mark for prep or 0 to exit: ";
            cin >> input;
            if(input != 0){
                if(input <= sizeOfWaitingPizzaListLocation && input > 0){
                    pr.moveBetween(waitFile, prepFile, input-1);
                    cout << "Pizza number " << input << " marked prepared" << endl;
                }
            }else{
                break;
            }
        }
    }else{
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
    }
        */
}




/**************************************************************************************
 
                                        ORDER
 
 ***************************************************************************************/



void Bizniz::setOrderPaidValue(string fileName, int pureIndex, bool value){
    int size;
    Order* orders = orderRepo.retrieveOrderArray(fileName, size);
    orders[pureIndex].setPaid(value);
    orderRepo.clearOrderFile(fileName);
    for (int i = 0; i < size; i++) {
        orderRepo.storeOrder(orders[i]);
    }
}

void Bizniz::setOrderDeliveredValue(string fileName, int pureIndex, bool value){
    int size;
    Order* orders = orderRepo.retrieveOrderArray(fileName, size);
    orders[pureIndex].setDelivered(value);
    orderRepo.clearOrderFile(fileName);
    for (int i = 0; i < size; i++) {
        orderRepo.storeOrder(orders[i]);
    }
}
