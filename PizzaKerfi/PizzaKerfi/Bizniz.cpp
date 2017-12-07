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
 
                                    PIZZA
 
 ***************************************************************************************/


Pizza* Bizniz::getArrayOfPizzasAtLocationWithSomeStatus(status status, Location location, int &sizeOfReturnPizzaList){
    
    int sizeOfEntirePizzaList;
    Pizza* allPizzas = pizzaRepo.retrievePizzaArray(PIZZAFILE, sizeOfEntirePizzaList);
    Pizza* returnPizzas = new Pizza[sizeOfEntirePizzaList];
    sizeOfReturnPizzaList = 0;
    for (int i = 0; i < sizeOfEntirePizzaList; i++) {
        if((allPizzas[i].getStatus()) == status && allPizzas[i].getLocation().getLocation() == location.getLocation()){
            returnPizzas[sizeOfReturnPizzaList] = allPizzas[i];
            sizeOfReturnPizzaList++;
        }
    }
    return returnPizzas;
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
