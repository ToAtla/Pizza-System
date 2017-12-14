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
        cout << setfill(' ') << setw(SIZEOFBIGCENTERHEADING+17) << right << "Sales" << endl;
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG) << "-" << endl << endl;
        cout << setfill(' ') << setw(SIZEFORSETWBIGSPACE) << "1: " << "New order" << endl;
        uiItemSeparator();
        cout << setw(SIZEFORSETWBIGSPACE) << "2: " << "View all orders" << endl;
        uiItemSeparator();
        cout << setw(SIZEFORSETWBIGSPACE) << "b: " << "back" << endl;
        uiItemSeparator();
        cin >> input;
        clearScreen();
        
        if(input == '1'){
            try {
                createOrder();
            } catch (InvalidFileLocationException) {
                cout << endl << setw(SIZEFORSETWBIGSPACE-3) << " " << "No locations available!" << endl << endl;
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
        cout << setfill(CHARFORSUBACTION) << setw(SIZEOFBIGCENTERHEADING+1) << "+" << "    Creating a new Order    " <<  setfill(CHARFORSUBACTION) << setw(SIZEOFBIGCENTERHEADING+1) << "+" << endl << endl;
        
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
        
        order.setID(bizniz.getIDForNextOrder());
       
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
            
            order.setTime(bizniz.getTimeNow());
            bizniz.storeOrder(order);
        }
    }
}

//Prompts the user for pick up or delivery
//Prompts the user to input a delivery destination
//Then retruns it
void SalesUI::deliveryCreationProcess(Order& order){
    string input;
    cout << endl << "Will this order be delivered(y/n) ";
    cin >> input;
    clearScreen();
    string addressString;
    char* address = new char[MAXCHARINLOCATIONNAME];
    if(input[0] == 'y'){
        cout << endl << "Write out the address (max " << MAXCHARINLOCATIONNAME-1 << " characters):";
        cin.ignore();
        getline(cin, addressString);
        if(bizniz.isValidNameLength(addressString, MAXCHARINLOCATIONNAME)){
            strcpy(address, addressString.c_str());
            order.setDelivery(true);
        }
    }
    else{
        address[0] = '\0';
        order.setDelivery(false);
    }
    order.setDeliveryAddress(address);
    delete [] address;
}

//Displays all orders from the orders list.
void SalesUI::displayOrders(){
    //Displaying all active orders in company
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
    
    cout << endl << setfill(CHARFORSETFILL) << setw(SIZEOFBIGCENTERHEADING) << "-" << "    List of available sizes    " << setfill(CHARFORSETFILL) << setw(SIZEOFBIGCENTERHEADING-1) << "-" << endl << endl;
    vector<Size> sizes = bizniz.getVectorOfSizes();
    cout << setfill(' ') << setw(SIZEOFPRICESPACE) << "Price" << endl;
    cout << setw(SIZEOFPRICESPACE) << "-----" << endl;
        
    for(int i = 0; i < sizes.size(); i++){
        Size temp = sizes.at(i);
        cout << setw(SIZEFORSETWBIGSPACE-3) << " " << "Size number " << i+1 << endl;
        cout << setw(SIZEFORSETWBIGSPACE) << temp.getName() << setw(60) << right << temp.getPrice() << endl;
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
    
    cout << endl << endl;
    cout << setfill(CHARFORSETFILL) << setw(SIZEOFBIGCENTERHEADING) << "-" << "    List of available bases    " << setfill(CHARFORSETFILL) << setw(SIZEOFBIGCENTERHEADING-1) << "-" << endl << endl;
    
    vector<Base> bases = bizniz.getVectorOfBases();
    
    cout << setfill(' ') << setw(SIZEOFPRICESPACE) << "Price" << endl;
    cout << setw(SIZEOFPRICESPACE) << "-----" << endl;
        
        
    for(int i = 0; i < bases.size(); i++){
        Base temp = bases.at(i);
        cout << setw(SIZEFORSETWBIGSPACE) << " " << "Base number " << i+1 << endl;
        cout << setw(SIZEFORSETWBIGSPACE) << temp.getName() << setw(60) << right << temp.getPrice() << endl;
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
    cout << endl;
    cout << setfill(CHARFORSETFILL) << setw(SIZEOFBIGCENTERHEADING-2) << "-" << "    List of available toppings    " << setfill(CHARFORSETFILL) << setw(SIZEOFBIGCENTERHEADING-2) << "-" << endl << endl;
    
    vector<Topping> allToppings = bizniz.getVectorOfToppings();
    
    if(allToppings.size() < 1){
        cout << endl << "*NOTE* No toppings available at this time." << endl;
        cout << endl << "Enter any key to continue." << endl;
        string input;
        cin >> input;
    }
    else{
        cout << setfill(' ') << setw(SIZEOFPRICESPACE) << "Price" << endl;
        cout << setw(SIZEOFPRICESPACE) << "-----" << endl;
        
        for (int i = 0; i < allToppings.size(); i++) {
            cout << setfill(' ') << setw(SIZEFORSETWBIGSPACE-3) << " " << "Topping nr: " << i+1 << endl;
            cout << setw(SIZEFORSETWBIGSPACE) << allToppings.at(i);
            uiItemSeparator();
        }
        int c = 0;
        while(true){
            //Veit ekki hvort þarf < eða <= hérna í næstu línu
            if(c <= MAXTOPPINGSONPIZZA){
                cout << setfill(' ') << setw(SIZEFORSETWBIGSPACE-3) << " "<< "Enter an index of topping to add or 0 to exit (no whitespaces): ";
                string input;
                cin >> input;
                
                if(bizniz.isInputDigit(input) && bizniz.isValidToppingInput(stoi(input), allToppings.size())){
                
                    int intInput = stoi(input);
                    
                    if(intInput != 0){
                        toppingsForPizza[c] = allToppings.at(intInput-1);
                        c++;
                        cout << setw(SIZEOFBIGCENTERHEADING-1) << "Topping number " << input << " added" << endl;
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
    
    cout << endl << setfill(CHARFORSETFILL) << setw(SIZEOFBIGCENTERHEADING+1) << "-" << "    Locations available    " << setfill(CHARFORSETFILL) << setw(SIZEOFBIGCENTERHEADING+2) << "-" << endl << endl;
        
    string locationNumber;

    for(unsigned int i = 0; i < locations.size(); i++){
        cout << setfill(' ') << setw(SIZEFORSETWBIGSPACE-3) << " " << "Location number: " << i+1 << endl;
        cout << setfill(' ') << setw(SIZEFORSETWBIGSPACE-3) << " " << locations.at(i) << endl;
        uiItemSeparator();
    }
    cout << "Choose a number corresponding to location (no whitespaces): ";
    cin >> locationNumber;
            
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
    int tellMeHowMany;
    MenuItem* menuItems = bizniz.getArrayOfMenuItems(MENUITEMFILE, tellMeHowMany);
    //
    while(true){
        cout << endl << "Assemble off menu pizza?(y/n) ";
        char input = '\0';
        cin >> input;
        if(input != 'y' && tellMeHowMany < 1){
                cout << endl << endl << "*NOTE* Sorry there are no menu pizzas available you will have assemble the toppings yourself *NOTE*" << endl << endl;
                int toppingCount = 0;
                Topping* pizzaToppings = toppingPickingProcess(toppingCount);
                Pizza returnPizza = bizniz.assemblePizza(pizzaSize, pizzaBase, pizzaToppings, toppingCount, locationOfOrderForPizzaToFollow);
                delete [] pizzaToppings;
                return returnPizza;
        }
        else if(input == 'y'){
            int toppingCount = 0;
            Topping* pizzaToppings = toppingPickingProcess(toppingCount);
            bool isMenuItem = false;
            MenuItem  tempMenuItem = bizniz.recognizeMenuItem(pizzaToppings, toppingCount, isMenuItem);
            if(isMenuItem){
                cout << "Your combination of toppings is on the menu under the name: " << tempMenuItem.getName() << endl;
                string input;
                cout << endl << "Enter any key to continue: " << endl << endl;
                cin >> input;
                Pizza returnPizza = bizniz.assemblePizzaWithMenuItem(pizzaSize, pizzaBase, tempMenuItem, locationOfOrderForPizzaToFollow);
                delete [] pizzaToppings;
                return returnPizza;
            }else{
                Pizza  returnPizza = bizniz.assemblePizza(pizzaSize, pizzaBase, pizzaToppings, toppingCount, locationOfOrderForPizzaToFollow);
                delete [] pizzaToppings;
                return returnPizza;
            }
            
        }else{
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFBIGCENTERHEADING) << "-" << "    List of menu Items    " << setfill(CHARFORSETFILL) << setw(SIZEOFBIGCENTERHEADING-1) << "-" << endl << endl;
            cout << setfill(' ') << setw(SIZEOFPRICESPACE) << "Price" << endl;
            cout << setw(SIZEOFPRICESPACE) << "-----" << endl;
                
            for (unsigned int i = 0; i < tellMeHowMany; i++) {
                MenuItem temp = menuItems[i];
                cout << setfill(' ') << setw(SIZEFORSETWSPACE-3) << " " << "Menu item number: " << i+1 << endl;
                cout << setfill(' ') << setw(SIZEFORSETWSPACE-3) << " " << setw(SIZEFORSETWSPACE+2) << left << temp.getName() << setw(SIZEFORSETWSPACE+7);
                cout << setfill(' ') << right << temp.getPrice() << endl;
                for(int i = 0; i < temp.getToppingCount(); i++){
                    cout << setfill(' ') << setw(SIZEFORSETWSPACE-3) << " " << setw(SIZEFORSETWSPACE+2) << left << temp.getCertainTopping(i).getName() << setw(SIZEFORSETWSPACE+7) << setfill(' ') << right << endl;
                }
                cout << setw(SIZEFORSETWSPACE-3) << " " << setfill(CHARFORSETFILL) << setw(SIZEOFSETW-33) << "-" << endl << endl;
            }
            cout << "Choose a number corresponding to menu item : ";
            string input;
            cin >> input;
            
            unsigned long longHowMany = tellMeHowMany;
                
            if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), longHowMany)){
            
                int intInput = stoi(input);
                
                Pizza returnPizza = bizniz.assemblePizzaWithMenuItem(pizzaSize, pizzaBase, menuItems[intInput-1], locationOfOrderForPizzaToFollow);
                
                return returnPizza;
            }
        }
        return Pizza();
    }
    
}


void SalesUI::sideListCreationProcess(Order &order){
    vector<Side> sides = bizniz.getVectorOfSides();
    
    if(sides.size() < 1){
        cout << endl << "*NOTE* There are no sides available at this time." << endl;
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
            
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFBIGCENTERHEADING) << "-" << "    List of available sides    " << setfill(CHARFORSETFILL) << setw(SIZEOFBIGCENTERHEADING-1) << "-" << endl << endl;
            cout << setfill(' ') << setw(SIZEOFPRICESPACE) << "Price" << endl;
            cout << setw(SIZEOFPRICESPACE) << "-----" << endl;
            
            for(unsigned int i = 0; i < sides.size(); i++){
                Side temp = sides.at(i);
                cout << setw(SIZEFORSETWBIGSPACE-3) << "Side number " << i+1 << endl;
                cout << setfill(' ') << setw(SIZEFORSETWBIGSPACE-3) << " " << setw(SIZEFORSETWBIGSPACE-3) << left << temp.getName() << setw(SIZEOFSETW-32) << right << temp.getPrice() << endl;
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
        cout << endl << "*NOTE* There are no drinks available at this time." << endl;
    }
    else{
        cout << endl << "Would you like to a drink with your order? 'y' for yes, anything else for no. ";
        cin >> input;
        order.setNumberOfDrinks(0);
        
        while(input == 'y') {
            vector<Drink> drinks = bizniz.getVectorOfDrinks();
            
            cout << endl << setfill(CHARFORSETFILL) << setw(SIZEOFBIGCENTERHEADING) << "-" << "    List of available drinks    " << setfill(CHARFORSETFILL) << setw(SIZEOFBIGCENTERHEADING-1) << "-";
            cout << endl << endl;
            cout << setfill(' ') << setw(SIZEOFPRICESPACE) << "Price" << endl;
            cout << setw(SIZEOFPRICESPACE) << "-----" << endl;
            
            for(unsigned int i = 0; i < drinks.size(); i++){
                Drink temp = drinks.at(i);
                cout << setfill(' ') << setw(SIZEOFBIGCENTERHEADING-3) << "Drink number " << i+1 << endl;
                cout << setfill(' ') << setw(SIZEFORSETWBIGSPACE-3) << " " << setw(SIZEFORSETWBIGSPACE-3) << left << temp.getName() << setw(SIZEOFSETW-32) << right << temp.getPrice() << endl;
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
    string input;
    cout << endl << "Any special comments?(y/n) ";
    cin >> input;
    clearScreen();
    string commentString;
    char* comment = new char[MAXCHARINORDERCOMMENT];
    if(input[0] == 'y'){
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
    cout << setw(SIZEFORSETWBIGSPACE-3) << " " << setfill(CHARFORSETFILL) << setw(SIZEOFSETWBIG-37) << "-" << endl << endl;
    cout << setfill(' ');
}
