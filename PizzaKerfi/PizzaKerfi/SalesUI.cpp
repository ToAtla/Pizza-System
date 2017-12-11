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
        cout << NINETABSTRING << "3: delete an order DO WE REALLY NEED THIS OPTION?" << endl;
        cout << NINETABSTRING << "b: back" << endl << endl << NINETABSTRING;
        cin >> input;
        clearScreen();
        
        if(input == '1'){
            try {
                createOrder();
            } catch (InvalidFileLocationException) {
                cout << endl << "No locations available!" << endl << endl;
            }
        }
        else if(input == '2'){
            displayOrders();
        }
        else if(input == '3'){
            deleteOrder();
        }
    }
}

//Býr til pöntun og vistar hana
//vistar svo pizzurnar sérstaklega í pizzuskjal
void SalesUI::createOrder(){
   
    if(bizniz.isValidLocationFile()){
        
        Order order;
        cout << setfill(CHARFORSUBACTION) << setw(36) << "+" << "    Creating a new Order    " <<  setfill(CHARFORSUBACTION) << setw(36) << "+" << endl << endl;
        
        try {
            order.setLocation(locationPickingProcess());
        } catch (InvalidInputException e) {
            cout << endl << endl << e.getMessage() << endl << endl;
            return;
        }
        
        order.setID(bizniz.getNumberForNextOrder());
       
        try {
            pizzaListCreationProcess(order);
        } catch (InvalidFileSizeBaseException e) {
            cout << endl << e.getMessage() << endl << endl;
        } catch (InvalidInputException) {
            cout << endl << "Invalid input! (input can't be a character and has to match a number on the list) Try again" << endl << endl;
            return;
        }
        
        try {
            sideListCreationProcess(order);
        } catch (InvalidInputException) {
            cout << endl << "Invalid input! (input can't be a character and has to match a number on the list)" << endl << endl;
        }
        
        try {
            drinkListCreationProcess(order);
        } catch (InvalidInputException) {
            cout << endl << "Invalid input! (input can't be a character and has to match a number on the list)" << endl << endl;
        }
        
        
        try{
            commentCreationProcess(order);
        }catch(InvalidNameException){
            cout << endl << "Hey there! I said only " << MAXCHARINORDERCOMMENT-1 << " characters" << endl << endl;
            char comment[MAXCHARINORDERCOMMENT];
            comment[0] = '\0';
            order.setOrderComment(comment);
        }
        
        
        //Passar að þú bætir ekki við tómri pöntun í skránna.
        if(order.getNumberOfSides() == 0 && order.getNumberOfPizzas() == 0 && order.getNumberOfDrinks() == 0){
            return;
        } else {
            bizniz.storeOrder(order);
        }
    }
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

void SalesUI::deleteOrder(){
    
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
    cout << HALFTABSTRING << TABSTRING << "Price" << endl;
    cout << HALFTABSTRING << TABSTRING << "-----" << endl;
        
    for(int i = 0; i < sizes.size(); i++){
        Size temp = sizes.at(i);
        cout << HALFTABSTRING << "Size number " << i+1 << endl;
        cout << HALFTABSTRING << temp << endl;
    }
    string input;
    cout << "Please choose a size for your pizza (no whitespaces): ";
    cin.ignore();
    getline(cin, input);
        
    if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), sizes.size())){
        
        int intInput = stoi(input);
        
        for(int i = 0; i < sizes.size(); i++){
            if(intInput == i+1){
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
    
    cout << HALFTABSTRING << TABSTRING << "Price" << endl;
    cout << HALFTABSTRING << TABSTRING << "-----" << endl;
        
        
    for(int i = 0; i < bases.size(); i++){
        Base temp = bases.at(i);
        cout << HALFTABSTRING << "Base number " << i+1 << endl;
        cout << HALFTABSTRING << temp << endl;
    }
    string input;
    cout << "Please choose a base for your pizza (no whitespaces): ";
    cin >> input;
    
    if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), bases.size())){
        
        int intInput = stoi(input);
        
        baseForPizza = bases.at(intInput-1);
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
                cout << HALFTABSTRING << "Enter an index of topping to add or 0 to exit (no whitespaces): ";
                string input;
                cin >> input;
                
                if(bizniz.isInputDigit(input) && bizniz.isValidToppingInput(stoi(input), allToppings.size())){
                
                    int intInput = stoi(input);
                    
                    if(intInput != 0){
                        toppingsForPizza[c] = allToppings.at(intInput-1);
                        c++;
                        cout << "Topping number " << input << " added" << endl;
                    }else{
                        break;
                    }
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
    
    cout << endl << setfill(CHARFORSETFILL) << setw(36) << "-" << "    Locations available    " << setfill(CHARFORSETFILL) << setw(37) << "-" << endl << endl;
        
    string locationNumber;

    for(unsigned int i = 0; i < locations.size(); i++){
        cout << NINETABSTRING << " Location number: " << i+1 << endl;
        cout << NINETABSTRING << " " << locations.at(i) << endl << endl;
    }
    cout << "Choose a number corresponding to location: ";
    cin.ignore();
    getline(cin, locationNumber);
            
    if(bizniz.isInputDigit(locationNumber) && bizniz.isValidInput(stoi(locationNumber), locations.size())){
            
        int intLocationNumber = stoi(locationNumber);
                
        for(unsigned int i = 0; i < locations.size(); i++){
                if(intLocationNumber == i+1){
                    returnLocation = locations.at(i);
                }
        }
    }
    return returnLocation;
}

void SalesUI::pizzaListCreationProcess(Order& order){
    
    if(bizniz.isValidBaseSizeFile()){
        cout << endl << "Enter number of pizzas to add to order (no whitespaces): ";
        string sInNumPizz;
        cin >> sInNumPizz;
       
        if(bizniz.isInputDigit(sInNumPizz)){
            
            int inNumPizz = stoi(sInNumPizz);
            
            order.setNumberOfPizzas(inNumPizz);
            
            for (int i = 0; i < order.getNumberOfPizzas(); i++) {
                cout << endl << "Pizza number: " << i+1 << endl;
                order.getPizzasInOrder()[i] = pizzaCreationProcess(order.getLocation());
                order.getPizzasInOrder()[i].setParentID(order.getID());
                order.setTotalPrice(order.getTotalPrice() + order.getPizzasInOrder()[i].getPrice());
            }
        }
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
        cout << endl << endl << "Would you like a side with your order? 'y' for yes, anything else for no. ";
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
            cout << "Choose a number corresponding to side (no whitespaces): ";
            string sideNumber;
            cin >> sideNumber;
            
            if(bizniz.isInputDigit(sideNumber) && bizniz.isValidInput(stoi(sideNumber), sides.size())){
            
                int intSideNumber = stoi(sideNumber);
                
                for(unsigned int i = 0; i < sides.size(); i++){
                    if(intSideNumber == i+1){
                        order.getSideList()[c] = sides.at(i);
                        
                        order.setTotalPrice(order.getTotalPrice() + sides.at(i).getPrice());
                        
                        order.setNumberofSides(order.getNumberOfSides() + 1);
                        
                        c++;
                    }
                }
            
            
                cout << endl << "Would you like to add another side? 'y' for yes, anything else for no. ";
                cin >> input;
            }
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
        cout << endl << "Would you like to a drink with your order? 'y' for yes, anything else for no. ";
        cin >> input;
        order.setNumberOfDrinks(0);
        
        while(input == 'y') {
            vector<Drink> drinks = bizniz.getVectorOfDrinks();
            
            cout << endl;
            for(unsigned int i = 0; i < drinks.size(); i++){
                cout << "Drink number: " << i+1 << endl;
                cout << drinks.at(i) << endl << endl;
            }
            cout << "Choose a number corresponding to drink (no whitespaces): ";
            string drinkNumber;
            cin >> drinkNumber;
            
            if(bizniz.isInputDigit(drinkNumber) && bizniz.isValidInput(stoi(drinkNumber), drinks.size())){
            
                int intDrinkNumber = stoi(drinkNumber);
                
                for(unsigned int i = 0; i < drinks.size(); i++){
                    if(intDrinkNumber == i+1){
                        order.getDrinkList()[c] = drinks.at(i);
                        order.setTotalPrice(order.getTotalPrice() + drinks.at(i).getPrice());
                        order.setNumberOfDrinks(order.getNumberOfDrinks() + 1);
                        c++;
                    }
                }
                
                cout << endl <<"Would you like do add another drink? 'y' for yes, anything else for no. ";
                cin >> input;
                }
        }
        
    }
}
void SalesUI::commentCreationProcess(Order& order){
    char input = '\0';
    cout << "Any special comments?(y/n)";
    cin >> input;
    string commentString;
    char* comment = new char[MAXCHARINORDERCOMMENT];
    if(input == 'y'){
        cout << "Write out the comment(max " << MAXCHARINORDERCOMMENT-1 << " characters):";
        cin.ignore();
        getline(cin, commentString);
        if(bizniz.isValidNameLength(commentString, MAXCHARINORDERCOMMENT)){
           strcpy(comment, commentString.c_str());
        }
    }
    else{
        comment[0] = '\0';
    }
    order.setOrderComment(comment);
    delete [] comment;
}

void SalesUI::clearScreen(){
    ConsoleMagic consoleMagic;
    consoleMagic.clearScreen();
}


