//
//  SalesUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "SalesUI.hpp"
#include "Order.hpp"
#include "Bizniz.hpp"


void SalesUI::startSalesUI(){
    
    char input = 0;
    while(input != 'b'){
        
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << "Sales" << endl;
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << endl << endl;
        cout << NINETABSTRING << "1: New order" << endl;
        cout << NINETABSTRING << "2: View all orders" << endl;
        cout << NINETABSTRING << "3: Change an order BROKEN" << endl;
        cout << NINETABSTRING << "4: delete an order BROKEN" << endl;
        cout << NINETABSTRING << "b: back" << endl << endl << NINETABSTRING;
        cin >> input;
        clearScreen();
        
        if(input == '1'){
            createOrder();
        }
        else if(input == '2'){
            displayOrders();
        }
        else if(input == '3'){
            
        }
        else if(input == '4'){
            
        }
    }
}

//Býr til pöntun og vistar hana
//vistar svo pizzurnar sérstaklega í pizzuskjal
void SalesUI::createOrder(){
    Order order;
    cout << setfill(CHARFORSUBACTION) << setw(36) << "+" << "    Creating a new Order    " <<  setfill(CHARFORSUBACTION) << setw(36) << "+" << endl << endl;
    
    order.setLocation(locationPickingProcess());

    
    order.setID(bizniz.getNumberForNextOrder());
   
    pizzaListCreationProcess(order);
    
    sideListCreationProcess(order);
    
    drinkListCreationProcess(order);
    
    bizniz.storeOrder(order);
    //bizniz.extractPizzasForPrepUI(order);
}


void SalesUI::displayOrders(){
    int orderCnt = 0;
    Order* orderList = bizniz.getArrayOfOrders(ORDERFILE, orderCnt);
    if(orderCnt  == 0){
        cout << endl;
        cout << "List is empty" << endl;
        cout << endl;
        cout << "Press any key to continue" << endl;
        cin >> ws;
    }else{
        for (int i = 0; i < orderCnt; i++) {
            cout << orderList[i];
        }
    }
    delete [] orderList;
}


Size SalesUI::sizePickingProcess(){
    Size sizeForPizza;
    
    cout << endl << setfill(CHARFORSETFILL) << setw(35) << "-" << "    List of available sizes    " << setfill(CHARFORSETFILL) << setw(34) << "-" << endl << endl;
    vector<Size> sizes = bizniz.getVectorOfSizes();
    if(sizes.size() < 1){
        cout << endl << "No sizes available at this time." << endl;
    }
    else{
        cout << HALFTABSTRING << TABSTRING << "Price" << endl;
        cout << HALFTABSTRING << TABSTRING << "-----" << endl;
        
        for(int i = 0; i < sizes.size(); i++){
            Size temp = sizes.at(i);
            cout << HALFTABSTRING << "Size number " << i+1 << endl;
            cout << HALFTABSTRING << temp << endl;
        }
        int input = 0;
        cout << "Please choose a size for your pizza: ";
        cin >> input;
        for(int i = 0; i < sizes.size(); i++){
            if(input == i+1){
                sizeForPizza = sizes.at(i);
            }
        }
        
        
    }
    return sizeForPizza;
}




Base SalesUI::basePickingProcess(){
    Base baseForPizza;
    
    cout << endl << setfill(CHARFORSETFILL) << setw(35) << "-" << "    List of available bases    " << setfill(CHARFORSETFILL) << setw(34) << "-" << endl << endl;
    
    vector<Base> bases = bizniz.getVectorOfBases();
    
    if(bases.size() < 1){
        
        cout << endl << "No bases available at this time." << endl;
        
    }
    else{
        cout << HALFTABSTRING << TABSTRING << "Price" << endl;
        cout << HALFTABSTRING << TABSTRING << "-----" << endl;
        
        
        for(int i = 0; i < bases.size(); i++){
            Base temp = bases.at(i);
            cout << HALFTABSTRING << "Base number " << i+1 << endl;
            cout << HALFTABSTRING << temp << endl;
        }
        int input = 0;
        cout << "Please choose a base for your pizza: ";
        cin >> input;
        baseForPizza = bases.at(input-1);
    }
    return baseForPizza;
}


Topping* SalesUI::toppingPickingProcess(int& toppingCount){
    
    Topping* toppingsForPizza = new Topping[MAXTOPPINGSONPIZZA];
    cout << endl << setfill(CHARFORSETFILL) << setw(33) << "-" << "    List of available toppings    " << setfill(CHARFORSETFILL) << setw(33) << "-" << endl << endl;
    
    vector<Topping> allToppings = bizniz.getVectorOfToppings();
    
    if(allToppings.size() < 1){
        cout << endl << "No toppings available at this time." << endl;
    }
    else{
        cout << HALFTABSTRING << TABSTRING << "Price" << endl;
        cout << HALFTABSTRING << TABSTRING << "-----" << endl;
        
        for (int i = 0; i < allToppings.size(); i++) {
            cout << HALFTABSTRING << "Topping nr: " << i+1 << endl;
            cout << HALFTABSTRING << allToppings.at(i) << endl << endl;
        }
        int c = 0;
        while(true){
            //Veit ekki hvort þarf < eða <= hérna í næstu línu
            if(c <= MAXTOPPINGSONPIZZA){
                cout << HALFTABSTRING << "Enter an index of topping to add or 0 to exit: ";
                int input;
                cin >> input;
                if(input != 0){
                    toppingsForPizza[c] = allToppings.at(input-1);
                    c++;
                    cout << "Topping number " << input << " added" << endl;
                }else{
                    break;
                }
            }
        }
        toppingCount = c;
    }
    return toppingsForPizza;
}


Location SalesUI::locationPickingProcess(){
    Location returnLocation;
    vector<Location> locations = bizniz.getVectorOfLocations();
    
    if(locations.size() < 1){
        cout << endl << "No locations available at this time" << endl << endl;
    }
    else{
        cout << endl << setfill(CHARFORSETFILL) << setw(36) << "-" << "    Locations available    " << setfill(CHARFORSETFILL) << setw(37) << "-" << endl << endl;
        
        int locationNumber = 0;
        
        bool invalidInput = true;
        
        while(invalidInput){
            vector<Location> locations = bizniz.getVectorOfLocations();
            
            for(unsigned int i = 0; i < locations.size(); i++){
                cout << NINETABSTRING << " Location number: " << i+1 << endl;
                cout << NINETABSTRING << " " << locations.at(i) << endl << endl;
            }
            cout << "Choose a location for your order: ";
            cin >> locationNumber;
            
            for(unsigned int i = 0; i < locations.size(); i++){
                if(locationNumber == i+1){
                    returnLocation = locations.at(i);
                    invalidInput = false;
                }
            }
            
            if(invalidInput){
                cout << "Please enter a valid location: " << endl;
                
            }
        }
        
    }
    return returnLocation;
}

void SalesUI::pizzaListCreationProcess(Order& order){
    
    cout << endl << "Enter number of pizzas to add to order: ";
    int inNumPizz;
    cin >> inNumPizz;
    order.setNumberOfPizzas(inNumPizz);
    
    for (int i = 0; i < order.getNumberOfPizzas(); i++) {
        cout << endl << "Pizza number: " << i+1 << endl;
        order.getPizzasInOrder()[i] = pizzaCreationProcess(order.getLocation());
        order.getPizzasInOrder()[i].setParentID(order.getID());
        order.setTotalPrice(order.getTotalPrice() + order.getPizzasInOrder()[i].getPrice());
    }
}


Pizza SalesUI::pizzaCreationProcess(Location locationOfOrderForPizzaToFollow){
   
    Size pizzaSize = sizePickingProcess();
    Base pizzaBase = basePickingProcess();
    int toppingCount = 0;
    Topping* pizzaToppings = toppingPickingProcess(toppingCount);
    Pizza returnPizza = bizniz.assemblePizza(pizzaSize, pizzaBase, pizzaToppings, toppingCount, locationOfOrderForPizzaToFollow);
    delete [] pizzaToppings;
    return returnPizza;
}


void SalesUI::sideListCreationProcess(Order &order){
    vector<Side> sides = bizniz.getVectorOfSides();
    
    if(sides.size() < 1){
        cout << endl << "There are no sides available at this time." << endl;
    }
    else{
        cout << endl << "Would you like a side with your order? y: yes ";
        char input = '0';
        cin >> input;
        cout << endl;
        
        int c = 0;
        order.setNumberofSides(0);
        
        while(input == 'y') {
            vector<Side> sides = bizniz.getVectorOfSides();
            
            cout << setfill(CHARFORSETFILL) << setw(35) << "-" << "    List of available sides    " << setfill(CHARFORSETFILL) << setw(34) << "-" << endl << endl;
            cout << HALFTABSTRING << TABSTRING << "Price" << endl;
            cout << HALFTABSTRING << TABSTRING << "-----" << endl;
            
            for(unsigned int i = 0; i < sides.size(); i++){
                cout << HALFTABSTRING << "Side number: " << i+1 << endl;
                cout << HALFTABSTRING << sides.at(i) << endl << endl;
            }
            cout << "Choose a side you want to add to your order: ";
            int sideNumber = 0;
            cin >> sideNumber;
            for(unsigned int i = 0; i < sides.size(); i++){
                if(sideNumber == i+1){
                    order.getSideList()[c] = sides.at(i);
                    
                    order.setTotalPrice(order.getTotalPrice() + sides.at(i).getPrice());
                    
                    order.setNumberofSides(order.getNumberOfSides() + 1);
                    
                    c++;
                }
            }
            
            cout << endl << "Would you like to add another side? y: yes ";
            cin >> input;
        }
        
        
    }
}

void SalesUI::drinkListCreationProcess(Order &order){
    
    int c = 0;
    char input = '\0';
    vector<Drink> drinks = bizniz.getVectorOfDrinks();
    
    if(drinks.size() < 1){
        cout << endl << "There are no drinks available at this time." << endl;
    }
    else{
        cout << endl << "Would you like to a drink with your order? y: yes ";
        cin >> input;
        order.setNumberOfDrinks(0);
        
        while(input == 'y') {
            vector<Drink> drinks = bizniz.getVectorOfDrinks();
            
            for(unsigned int i = 0; i < drinks.size(); i++){
                cout << "Drink number: " << i+1 << endl;
                cout << drinks.at(i) << endl;
            }
            cout << "Choose a drink you want to add to your order: ";
            int drinkNumber = 0;
            cin >> drinkNumber;
            for(unsigned int i = 0; i < drinks.size(); i++){
                if(drinkNumber == i+1){
                    order.getDrinkList()[c] = drinks.at(i);
                    order.setTotalPrice(order.getTotalPrice() + drinks.at(i).getPrice());
                    order.setNumberOfDrinks(order.getNumberOfDrinks() + 1);
                    c++;
                }
            }
            
            cout << endl <<"Would you like do add another drink? y: yes ";
            cin >> input;
        }
        
    }
}

void SalesUI::clearScreen(){
    ConsoleMagic consoleMagic;
    consoleMagic.clearScreen();
}

/*
 Bráðabirgðaföll til að sjá hvort það virki að vista pizzur í skrár
*/
/*
void SalesUI::createASinglePizzaToTest(){
    //Also saves to file
    
    Size pizzaSize = sizePickingProcess();
    Base pizzaBase = basePickingProcess();
    int toppingCount;
    Topping* pizzaToppings = toppingPickingProcess(toppingCount);
    Location pizzaLocation = locationPickingProcess();
    
    Pizza newPizza = bizniz.assemblePizza(pizzaSize, pizzaBase, pizzaToppings, toppingCount, pizzaLocation);
    delete [] pizzaToppings;
    bizniz.appendPizzaToFile(PIZZAFILE, newPizza);
}
*/


