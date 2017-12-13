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
        cout << setfill(' ') << setw(52) << right << "Sales" << endl;
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << endl << endl;
        cout << setfill(' ') << setw(22) << "1: " << "New order" << endl;
        uiItemSeparator();
        cout << setw(22) << "2: " << "View all orders" << endl;
        uiItemSeparator();
        cout << setw(22) << "b: " << "back" << endl;
        uiItemSeparator();
        cin >> input;
        clearScreen();
        
        if(input == '1'){
            try {
                createOrder();
            } catch (InvalidFileLocationException) {
                cout << endl << setw(42) << "No locations available!" << endl << endl;
            }
        }
        else if(input == '2'){
            displayOrders();
        }
    }
}

//Býr til pöntun og vistar hana
//vistar svo pizzurnar sérstaklega í pizzuskjal svo PrepUI getur unnið með þær.
void SalesUI::createOrder(){
   
    //Throws an exception if the location file is empty (YOU CAN'T ORDER A PIZZA IF THERE ARE NO LOACTIONS AVAILABLE).
    if(bizniz.isValidLocationFile()){
        
        Order order;
        cout << setfill(CHARFORSUBACTION) << setw(36) << "+" << "    Creating a new Order    " <<  setfill(CHARFORSUBACTION) << setw(36) << "+" << endl << endl;
        
        try{
            deliveryCreationProcess(order);
        } catch (InvalidNameException e) {
            e.getMessage();
        }
        
        
        try {
            order.setLocation(locationPickingProcess());
        } catch (InvalidInputException e) {
            cout << endl << endl << e.getMessage() << endl << endl;
            return;
        }
        
        order.setID(bizniz.getNumberForNextOrder());
       
        try {
            pizzaListCreationProcess(order);
        //Catches an exception if there are no sizes or bases available to make a pizza.
        } catch (InvalidFileSizeBaseException e) {
            cout << endl << e.getMessage() << endl << endl;
        } catch (InvalidInputException) {
            cout << endl << "*ERROR* Invalid input! (input can't be a character and has to match a number on the list) Try again" << endl << endl;
            return;
        }
        
        try {
            sideListCreationProcess(order);
        } catch (InvalidInputException) {
            cout << endl << "*ERROR* Invalid input! (input can't be a character and has to match a number on the list)" << endl << endl;
        }
        
        try {
            drinkListCreationProcess(order);
        } catch (InvalidInputException) {
            cout << endl << "*ERROR* Invalid input! (input can't be a character and has to match a number on the list)" << endl << endl;
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
            cout << endl << "*MESSEGE* Order was not created because an order needs to contain something" << endl << endl;
            return;
        } else {
            bizniz.storeOrder(order);
        }
    }
}

//Prompts the user for pick up or delivery
//Prompts the user to input a delivery destination
//Then retruns it
void SalesUI::deliveryCreationProcess(Order& order){
    char input = '\0';
    cout << endl << "Will this order be delivered(y/n)";
    cin >> input;
    clearScreen();
    string addressString;
    char* address = new char[MAXCHARINORDERCOMMENT];
    if(input == 'y'){
        cout << endl << "Write out the address (max " << MAXCHARINORDERCOMMENT-1 << " characters):";
        cin.ignore();
        getline(cin, addressString  );
        if(bizniz.isValidNameLength(addressString, MAXCHARINORDERCOMMENT)){
            strcpy(address, addressString.c_str());
        }
    }
    else{
        address[0] = '\0';
    }
    order.setOrderComment(address);
    delete [] address;
}

//Displays all orders from the orders list.
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
            cout << orderList[i] << endl << endl;
        }
    }
    delete [] orderList;
}

//Prints out a list of all available sizes from the "sizes.dat" and lets the user choose a size from the list by taking in an input from him
//and gives that pizza the size chosen.
Size SalesUI::sizePickingProcess(){
   
    Size sizeForPizza;
    
    cout << endl << setfill(CHARFORSETFILL) << setw(35) << "-" << "    List of available sizes    " << setfill(CHARFORSETFILL) << setw(34) << "-" << endl << endl;
    vector<Size> sizes = bizniz.getVectorOfSizes();
    cout << setfill(' ') << setw(82) << "Price" << endl;
    cout << setw(82) << "-----" << endl;
        
    for(int i = 0; i < sizes.size(); i++){
        Size temp = sizes.at(i);
        cout << setw(31) << "Size number " << i+1 << endl;
        cout << setw(22) << temp.getName() << setw(60) << right << temp.getPrice() << endl;
        uiItemSeparator();
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

//Prints out a list of all available bases from the "sizes.dat" and lets the user choose a base from the list by taking in an input from him
//and gives that pizza the base chosen.
Base SalesUI::basePickingProcess(){
    Base baseForPizza;
    
    cout << endl << endl << setfill(CHARFORSETFILL) << setw(35) << "-" << "    List of available bases    " << setfill(CHARFORSETFILL) << setw(34) << "-" << endl << endl;
    
    vector<Base> bases = bizniz.getVectorOfBases();
    
    cout << setfill(' ') << setw(82) << "Price" << endl;
    cout << setw(82) << "-----" << endl;
        
        
    for(int i = 0; i < bases.size(); i++){
        Base temp = bases.at(i);
        cout << setw(31) << "Base number " << i+1 << endl;
        cout << setw(22) << temp.getName() << setw(60) << right << temp.getPrice() << endl;
        uiItemSeparator();
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
        cout << setfill(' ') << setw(82) << "Price" << endl;
        cout << setw(82) << "-----" << endl;
        
        for (int i = 0; i < allToppings.size(); i++) {
            cout << setfill(' ') << setw(31) << "Topping nr: " << i+1 << endl;
            cout << setw(22) << allToppings.at(i);
            uiItemSeparator();
        }
        int c = 0;
        while(true){
            //Veit ekki hvort þarf < eða <= hérna í næstu línu
            if(c <= MAXTOPPINGSONPIZZA){
                cout << setfill(' ') << setw(19) << " "<< "Enter an index of topping to add or 0 to exit (no whitespaces): ";
                string input;
                cin >> input;
                
                if(bizniz.isInputDigit(input) && bizniz.isValidToppingInput(stoi(input), allToppings.size())){
                
                    int intInput = stoi(input);
                    
                    if(intInput != 0){
                        toppingsForPizza[c] = allToppings.at(intInput-1);
                        c++;
                        cout << setw(34) << "Topping number " << input << " added" << endl;
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
        cout << setfill(' ') << setw(19) << " " << "Location number: " << i+1 << endl;
        cout << setfill(' ') << setw(19) << " " << locations.at(i) << endl;
        uiItemSeparator();
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
    
    //Throws an exception if there are either no bases or no sizes available because you can't make a pizza without those.
    if(bizniz.isValidBaseSizeFile()){
        cout << endl << "Enter number of pizzas to add to order (no whitespaces): ";
        string sInNumPizz;
        cin >> sInNumPizz;
        clearScreen();
       
        if(bizniz.isInputDigit(sInNumPizz)){
            
            int inNumPizz = stoi(sInNumPizz);
            
            order.setNumberOfPizzas(inNumPizz);
            
            for (int i = 0; i < order.getNumberOfPizzas(); i++) {
                cout << endl << "Pizza number: " << i+1 << endl;
                order.getPizzasInOrder()[i] = pizzaCreationProcess(order.getLocation());
                order.getPizzasInOrder()[i].setParentID(order.getID());
                order.setTotalPrice(order.getTotalPrice() + order.getPizzasInOrder()[i].getPrice());
                clearScreen();
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
            cout << setfill(' ') << setw(82) << "Price" << endl;
            cout << setw(82) << "-----" << endl;
            
            for(unsigned int i = 0; i < sides.size(); i++){
                Side temp = sides.at(i);
                cout << setw(31) << "Side number " << i+1 << endl;
                cout << setfill(' ') << setw(19) << " " << setw(19) << left << temp.getName() << setw(44) << right << temp.getPrice() << endl;
                uiItemSeparator();
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
            
            cout << endl << setfill(CHARFORSETFILL) << setw(35) << "-" << "    List of available drinks    " << setfill(CHARFORSETFILL) << setw(34) << "-" << endl << endl;
            cout << setfill(' ') << setw(82) << "Price" << endl;
            cout << setw(82) << "-----" << endl;
            
            for(unsigned int i = 0; i < drinks.size(); i++){
                Drink temp = drinks.at(i);
                cout << setfill(' ') << setw(32) << "Drink number " << i+1 << endl;
                cout << setfill(' ') << setw(19) << " " << setw(19) << left << temp.getName() << setw(44) << right << temp.getPrice() << endl;
                uiItemSeparator();
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
    cout << endl << "Any special comments?(y/n)";
    cin >> input;
    clearScreen();
    string commentString;
    char* comment = new char[MAXCHARINORDERCOMMENT];
    if(input == 'y'){
        cout << endl << "Write out the comment(max " << MAXCHARINORDERCOMMENT-1 << " characters):";
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

void SalesUI::uiItemSeparator(){
    cout << setw(19) << " " << setfill(CHARFORSETFILL) << setw(63) << "-" << endl << endl;
    cout << setfill(' ');
}
