//
//  AdminUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "AdminUI.hpp"



//Prentar út valmynd sem býður notandanum að velja það sem hann vill fikta í.
void AdminUI::startAdminUI(){

    
    
    char input = 0;
    while(input != 'b'){
        magic.clearScreen();
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        cout << setfill (' ') << setw(40) << "Admin" << endl;
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << setfill(' ') << endl << endl;
        cout << setw(SIZEOFNUMBERLISTADMINUI) << "1: " << setw(SIZEOFLISTNAMEADMINUI) << "Add/change the topping list" << endl;
        uiItemSeparator();
        cout << setw(SIZEOFNUMBERLISTADMINUI) << "2: " << setw(SIZEOFLISTNAMEADMINUI) << "Add/change the location list" << endl;
        uiItemSeparator();
        cout << setw(SIZEOFNUMBERLISTADMINUI) << "3: " << setw(SIZEOFLISTNAMEADMINUI) << "Add/change the side list" << endl;
        uiItemSeparator();
        cout << setw(SIZEOFNUMBERLISTADMINUI) << "4: " << setw(SIZEOFLISTNAMEADMINUI) << "Add/change the drink list" << endl;
        uiItemSeparator();
        cout << setw(SIZEOFNUMBERLISTADMINUI) << "5: " << setw(SIZEOFLISTNAMEADMINUI) << "Add/change the size list" << endl;
        uiItemSeparator();
        cout << setw(SIZEOFNUMBERLISTADMINUI) << "6: " << setw(SIZEOFLISTNAMEADMINUI) << "Add/change the base list" << endl;
        uiItemSeparator();
        cout << setw(SIZEOFNUMBERLISTADMINUI) << "b: " << setw(SIZEOFLISTNAMEADMINUI) << "back" << endl;
        uiItemSeparator();
        cin >> input;
        magic.clearScreen();
        cout << endl;

        if(input == '1'){
            magic.clearScreen();
            displayToppingMenu();
        }
        else if(input == '2'){
            magic.clearScreen();
            displayLocationMenu();
        }
        else if(input == '3'){
            magic.clearScreen();
            displaySideMenu();
        }
        else if(input == '4'){
            magic.clearScreen();
            displayDrinkMenu();
        }
        else if(input == '5'){
            magic.clearScreen();
            displaySizeMenu();
        }
        else if(input == '6'){
            magic.clearScreen();
            displayBaseMenu();
        }
    }
}

//Prentar út valmynd sem býður notandanum uppá að velja það sem hann vill gera með topping listann.
void AdminUI::displayToppingMenu(){
    
    char input = '\0';
    while(input != 'b'){
        cout << setfill(CHARFORSETFILL) << setw(30) << "-" << "    Toppings    " << setfill(CHARFORSETFILL) << setw(30) << "-" << endl << endl;
        cout << setfill(' ') << setw(20) << "1: " << setw(32) << "List toppings" << endl;
        uiItemSeparator();
        cout << setw(20) << "2: " << setw(32) << "Change a topping" << endl;
        uiItemSeparator();
        cout << setw(20) << "3: " << setw(32) << "Add a topping" << endl;
        uiItemSeparator();
        cout << setw(20) << "4: " << setw(32) << "Remove a topping" << endl;
        uiItemSeparator();
        cout << setw(20) << "b: " << setw(32) << "back" << endl;
        uiItemSeparator();
        cin >> input;
        cout << endl;

        if(input == '1'){
            magic.clearScreen();
            displayAllToppings();
        }
        else if(input == '2'){
            magic.clearScreen();
            try {
                changeTopping();
            } catch (InvalidInputException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidNameException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidPriceException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
            
        }
        else if(input == '3'){
            magic.clearScreen();
            try {
                addTopping();
            } catch (InvalidNameException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidPriceException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
        }
        else if(input == '4'){
            magic.clearScreen();
            try {
                removeTopping();
            } catch (InvalidInputException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
        }
    }
}

//Prentar út lista yfir öll álegg sem eru í toppings.txt
void AdminUI::displayAllToppings(){

    ToppingRepo toppingRepo;
    vector<Topping> toppings = bizniz.getVectorOfToppings();
    cout << endl << setfill(CHARFORSETFILL)<< setw(24) << "-" << "    List of all toppings    " << setfill(CHARFORSETFILL) << setw(24) << "-" << endl << endl;
    if(toppings.size() < 1){
        cout << endl << setfill(' ') << setw(48) << "The file is empty :(" << endl << endl;
    }
    else{
        for (int i = 0; i < toppings.size(); i++) {
            Topping temp = toppings.at(i);
            cout << temp;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
    }
    
    cout << endl;
    
}

//Bætir við áleggi í textaskránna toppings.txt
void AdminUI::addTopping(){
    
    string name;
    string price;

    
    cout << setfill(CHARFORSETFILL) << setw(25) << "-" << "    Adding a topping!    " << setfill(CHARFORSETFILL) << setw(26) << "-" << endl << endl;
    cout << setfill(' ') << setw(SIZEOFADDTOPPINGSPACES) << "Enter topping name (Max " << MAXCHARINTOPPINGNAME-1 << " letters): ";
    cin >> name;
    cout << setw(SIZEOFADDTOPPINGSPACES-3) << "Enter topping price: ";
    cin >> price;
    if(bizniz.isValidName(name) && bizniz.isPriceDigit(price) && bizniz.isValidNameLength(name, MAXCHARINTOPPINGNAME)){
            
        int intPrice = stoi(price);
        char tempName[MAXCHARINTOPPINGNAME];
        strcpy(tempName, name.c_str());
        Topping temp(tempName, intPrice);
            
        bizniz.addTopping(temp);
        
    }
    cout << endl << setw(SIZEOFADDTOPPINGSPACES-10) << "Topping added!" << endl << endl;
}

//Tekur á móti vector af öllum áleggjum úr toppings.txt skránni og birtir það sem lista.
//Gerir notandanum kleift að velja álegg af listanum og breyta nafninu og verðinu á því.
void AdminUI::changeTopping(){

    vector<Topping> toppings = bizniz.getVectorOfToppings();
    cout << endl;
    cout << endl << setfill(CHARFORSETFILL) << setw(24) << "-" << "    List of all toppings    " << setfill(CHARFORSETFILL) << setw(24) << "-" << endl << endl;
    cout << setfill(' ') << setw(58) << "Price" << endl;
    cout << setw(58) << "-----" << endl;
    if(toppings.size() < 1){
        cout << endl << setfill(' ') << setw(48) << "The file is empty :(" << endl << endl;
    }
    else{
        for(int i = 0; i < toppings.size(); i++){
            Topping temp = toppings.at(i);
            cout << setfill(' ') << setw(30) << "Topping number: " << i+1 << endl;
            cout << setw(17) << temp.getName() << setw(40) << temp.getPrice() << endl;
            cout << setw(14) << " " << setfill(CHARFORSETFILL) << setw(43) << "-" << endl;
        }
        string input;
        cout << setfill(' ') << setw(42) << "Choose a topping to change: ";
        cin >> input;
        
        
        
        if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), toppings.size())){
            int intInput = stoi(input);
            
            for(int i = 0; i < toppings.size(); i++){
                if(intInput == i+1){
                    cout << setw(SIZEOFADDTOPPINGSPACES-4) << "Enter topping name (Max " << MAXCHARINTOPPINGNAME-1 << " letters): ";
                    string name;
                    cin >> name;
                    cout << setw(SIZEOFADDTOPPINGSPACES-7) << "Enter toppine price: ";
                    string price;
                    cin >> price;
                    if(bizniz.isValidName(name) && bizniz.isPriceDigit(price) && bizniz.isValidNameLength(name, MAXCHARINTOPPINGNAME)){
                        
                        int intPrice = stoi(price);
                        
                        if(bizniz.isValidPrice(intPrice)){
                            char tempName[MAXCHARINTOPPINGNAME];
                            strcpy(tempName, name.c_str());
                            
                            Topping temp(tempName, intPrice);
                            toppings.at(i) = temp;
                            cout << endl << setw(SIZEOFADDTOPPINGSPACES-12) << "Topping changed!" << endl << endl;
                        }
                    }
                }
            }
            bizniz.storeVectorOfToppings(toppings);
        }
    }
}

//Tekur á móti vector af af öllum áleggjum úr toppings.txt skránni og birtir það sem lista.
//Gerir notandanum kleift að velja álegg af listanum og eyða því.
void AdminUI::removeTopping(){

        vector<Topping> toppings = bizniz.getVectorOfToppings();
        cout << endl;
    
        cout << endl << setfill(CHARFORSETFILL) << setw(24) << "-" << "    List of all toppings    " << setfill(CHARFORSETFILL) << setw(24) << "-" << endl << endl;
        if(toppings.size() < 1){
                cout << endl << setfill(' ') << setw(48) << "The file is empty :(" << endl << endl;
        }  else {
            for(int i = 0; i < toppings.size(); i++){
                Topping temp = toppings.at(i);
                cout << setfill(' ') << setw(30) << "Topping number: " << i+1 << endl;
                cout << setw(17) << temp.getName() << setw(40) << temp.getPrice() << endl;
                cout << setw(14) << " " << setfill(CHARFORSETFILL) << setw(43) << "-" << endl;
            }

            string input;
            cout << setfill(' ') << setw(42) << "Choose a topping to remove: ";
            cin >> input;
        
            if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), toppings.size())){
                int intInput = stoi(input);

                if(intInput < 1 ||intInput > (toppings.size())){
                    cout << endl << setw(36) << "No topping chosen" << endl << endl;
                } else {
                    bizniz.removeTopping(toppings, intInput);
                    cout << endl << setw(29) << "Topping removed" << endl << endl;
                }
            }
        }
}


void AdminUI::displayLocationMenu(){
   
    char input = '\0';
    while(input != 'b'){
        cout << "1: List locations" << endl;
        cout << "2: Change a location" << endl;
        cout << "3: Add a location" << endl;
        cout << "4: Remove a location" << endl;
        cout << "b: back" << endl;
        cin >> input;
        cout << endl;

        if(input == '1'){
            magic.clearScreen();
            displayAllLocations();
        }
        else if(input == '2'){
            magic.clearScreen();
            try {
                changeLocation();
            } catch (InvalidInputException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidNameException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
        }
        else if(input == '3'){
            magic.clearScreen();
            try {
                addLocation();
            } catch (InvalidNameException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
        }
        else if(input == '4'){
            magic.clearScreen();
            try {
                removeLocation();
            } catch (InvalidInputException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
            
        }
    }
}

//Prentar út lista yfir alla afhendingarstaði.
void AdminUI::displayAllLocations(){
    
    vector<Location> locations = bizniz.getVectorOfLocations();
    cout << endl << "----------------------------List of all locations---------------------------" << endl;
    if(locations.size() < 1){
        cout << endl << "The file is empty :("  << endl;
    }
    
    for (int i = 0; i < locations.size(); i++) {
        Location temp = locations.at(i);
        cout << temp << endl;
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
    }
    cout << endl;
}

void AdminUI::addLocation(){

    string name;
    cout << "Adding a location!" << endl << endl;
    cout << "Enter location name (Max " << MAXCHARINLOCATIONNAME-1 << " letters): ";
    cin.ignore();
    getline(cin, name);
    char tempName[MAXCHARINLOCATIONNAME];
    
    strcpy(tempName, name.c_str());
    
    if(bizniz.isValidNameLength(name, MAXCHARINLOCATIONNAME)){
        Location temp(tempName);
        bizniz.addLocation(temp);
        cout << endl << "Location added!" << endl << endl;
    }
}

void AdminUI::changeLocation(){
   
    vector<Location> locations = bizniz.getVectorOfLocations();
    cout << endl;
    cout << endl << "----------------------------List of all locations----------------------------" << endl;
    
    if(locations.size() > 0){
    for(int i = 0; i < locations.size(); i++){
        Location temp = locations.at(i);
        cout << "Location number: " << i+1 << endl;
        cout <<  temp << endl;
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
    }
    string input;
    cout << "Choose a location to change: ";
    cin >> input;
    
    
        if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), locations.size())){
        int intInput = stoi(input);
            
        for(int i = 0; i < locations.size(); i++){
            if(intInput == i+1){
                cout << "Enter location name (Max " << MAXCHARINLOCATIONNAME-1 << " letters): ";
                string name;
                cin.ignore();
                getline(cin, name);
                char tempName[MAXCHARINLOCATIONNAME];
                
                strcpy(tempName, name.c_str());
                
                if(bizniz.isValidNameLength(name, MAXCHARINLOCATIONNAME)){
                    Location temp(tempName);
                    locations.at(i) = temp;
                    cout << endl << "Location changed" << endl << endl;
                }
            }
        }
        bizniz.storeVectorOfLocations(locations);
    }
    }
    else{
        cout << endl << "The file is empty :(" << endl << endl;
    }
}

void AdminUI::removeLocation(){

    
    vector<Location> locations = bizniz.getVectorOfLocations();
    cout << endl;
    cout << endl << "----------------------------List of all locations---------------------------" << endl;
    if(locations.size() < 1){
        cout << endl << "The file is empty :(" << endl << endl;
    } else {
        for(int i = 0; i < locations.size(); i++){
            Location temp = locations.at(i);
            cout << "Location number: " << i+1 << endl;
            cout <<  temp << endl;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }

        string input;
        cout << "Choose a location to remove: ";
        cin >> input;
        
        if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), locations.size())){
            int intInput = stoi(input);
            
            if(intInput < 1 ||intInput > (locations.size())){
                cout << endl << "No location chosen" << endl << endl;
            } else {
                bizniz.removeLocation(locations, intInput);
                cout << endl << "Location removed" << endl << endl;
            }
        }
    }
}


void AdminUI::displaySideMenu(){
    char input = '\0';
    while(input != 'b'){
        cout << "1: List sides" << endl;
        cout << "2: Change a side" << endl;
        cout << "3: Add a side" << endl;
        cout << "4: Remove a side" << endl;
        cout << "b: back" << endl;
        cin >> input;
        cout << endl;

        if(input == '1'){
            magic.clearScreen();
            displayAllSides();
        }
        else if(input == '2'){
            magic.clearScreen();
            try {
                changeSide();
            } catch (InvalidInputException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidNameException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidPriceException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
            
        }
        else if(input == '3'){
            magic.clearScreen();
            try {
                addSide();
            } catch (InvalidNameException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidPriceException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
        }
        else if(input == '4'){
            magic.clearScreen();
            try {
                removeSide();
            } catch (InvalidInputException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
        }
    }
}


void AdminUI::displayAllSides(){
    
    vector<Side> sides = bizniz.getVectorOfSides();
    
    cout << endl << "----------------------------List of all sides-------------------------------" << endl;
    
    if(sides.size() < 1){
        cout << endl << "The file is empty :(" << endl;
    }
    else {
        for (int i = 0; i < sides.size(); i++) {
            
            Side temp = sides.at(i);
            cout << temp << endl;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
        
    }
    cout << endl;
}


void AdminUI::addSide(){
    
    cout << "Adding a side!" << endl << endl;
    cout << "Enter side name (Max " << MAXCHARINSIDENAME-1 << " letters): ";
    string name;
    cin.ignore();
    getline(cin, name);
    cout << "Enter price: ";
    string price;
    cin >> price;
    
    if(bizniz.isValidName(name) && bizniz.isPriceDigit(price) && bizniz.isValidNameLength(name, MAXCHARINSIDENAME)){
       
        int intPrice = stoi(price);
        char tempName[MAXCHARINSIDENAME];
        strcpy(tempName, name.c_str());
        Side temp(tempName, intPrice);
        bizniz.addSide(temp);
        cout << endl << "Side added!" << endl << endl;
    }
}


void AdminUI::changeSide(){

    vector<Side> sides = bizniz.getVectorOfSides();
    cout << endl;
    cout << endl << "----------------------------List of all sides-------------------------------" << endl;
    
    if(sides.size() < 1){
        cout << endl <<"The file is empty :(" << endl << endl;
    } else {
        for(int i = 0; i < sides.size(); i++){
            Side temp = sides.at(i);
            cout << "Side number: " << i+1 << endl;
            cout <<  temp << endl;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
        string input;
        cout << "Choose a side to change: ";
        cin >> input;

        if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), sides.size())){
        
            int intInput = stoi(input);
            
            for(int i = 0; i < sides.size(); i++){
                if(intInput == i+1){
                    cout << "Enter side name (Max " << MAXCHARINSIDENAME-1 << " letters): ";
                    string name;
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter price: ";
                    string price;
                    cin >> price;
                    
                    if(bizniz.isValidName(name) && bizniz.isPriceDigit(price) && bizniz.isValidNameLength(name, MAXCHARINSIDENAME)){
                        int intPrice = stoi(price);
                        char tempName[MAXCHARINSIDENAME];
                        strcpy(tempName, name.c_str());
                        Side temp(tempName, intPrice);
                        sides.at(i) = temp;
                        cout << endl << "Side changed" << endl << endl;
                    }
                }
            }
            bizniz.storeVectorOfSides(sides);
        }
    }
}


void AdminUI::removeSide(){
    
    vector<Side> sides = bizniz.getVectorOfSides();
    cout << endl;
    cout << endl << "----------------------------List of all sides-------------------------------" << endl;
    
    if(sides.size() < 1){
        cout << endl << "The file is empty :(" << endl << endl;
    } else {
        for(int i = 0; i < sides.size(); i++){
            Side temp = sides.at(i);
            cout << "Side number: " << i+1 << endl;
            cout <<  temp << endl;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }

        string input;
        cout << "Choose a side to remove: ";
        cin >> input;

        if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), sides.size())){
        
            int intInput = stoi(input);
            
            if(intInput < 1 ||intInput > (sides.size())){
                cout << "No side chosen" << endl << endl;
            } else {
                bizniz.removeSide(sides, intInput);
                cout << endl << "Side removed!" << endl << endl;
            }
        }
    }
}


void AdminUI::displayDrinkMenu(){
    char input = '\0';
    while(input != 'b'){
        cout << "1: List drinks" << endl;
        cout << "2: Change a drink" << endl;
        cout << "3: Add a drink" << endl;
        cout << "4: Remove a drink" << endl;
        cout << "b: back" << endl;
        cin >> input;
        cout << endl;

        if(input == '1'){
            magic.clearScreen();
            displayAllDrinks();
        }
        else if(input == '2'){
            magic.clearScreen();
            try {
                changeDrink();
            } catch (InvalidInputException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidNameException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidPriceException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
        }
        else if(input == '3'){
            magic.clearScreen();
            try {
                addDrink();
            } catch (InvalidNameException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidPriceException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
        }
        else if(input == '4'){
            magic.clearScreen();
            try {
                removeDrink();
            } catch (InvalidInputException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
        }
    }
}

void AdminUI::displayAllDrinks(){
    
    vector<Drink> drinks = bizniz.getVectorOfDrinks();
    cout << endl << "----------------------------List of all drinks------------------------------" << endl;
    if(drinks.size() < 1){
        cout << endl << "The file is empty :(" << endl;
    }
    else {
        for (int i = 0; i < drinks.size(); i++) {
            Drink temp = drinks.at(i);
            cout << temp << endl;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
    }
    cout << endl;
}

void AdminUI::changeDrink(){
    
    vector<Drink> drinks = bizniz.getVectorOfDrinks();
    cout << endl;
    cout << endl << "----------------------------List of all drinks------------------------------" << endl;
    
    if(drinks.size() < 1){
        cout << endl << "The file is empty :(" << endl << endl;
    } else {
        for(int i = 0; i < drinks.size(); i++){
            Drink temp = drinks.at(i);
            cout << "Drink number: " << i+1 << endl;
            cout <<  temp << endl;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
        string input;
        cout << "Choose a drink to change: ";
        cin >> input;
        
        if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), drinks.size())){
            
            int intInput = stoi(input);
            
            for(int i = 0; i < drinks.size(); i++){
                if(intInput == i+1){
                    cout << "Enter drink name (Max " << MAXCHARINDRINKNAME-1 << " letters): ";
                    string name;
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter price: ";
                    string price;
                    cin >> price;
                    
                    if(bizniz.isValidName(name) && bizniz.isPriceDigit(price) && bizniz.isValidNameLength(name, MAXCHARINDRINKNAME)){
                        int intPrice = stoi(price);
                        char tempName[MAXCHARINDRINKNAME];
                        strcpy(tempName, name.c_str());
                        Drink temp(tempName, intPrice);
                        drinks.at(i) = temp;
                        cout << endl << "Drink changed" << endl << endl;
                    }
                }
            }
            bizniz.storeVectorOfDrinks(drinks);
        }
    }
}

void AdminUI::addDrink(){
    
    
    cout << "Adding a drink!" << endl << endl;
    cout << "Enter Drink name (Max " << MAXCHARINDRINKNAME-1 << " letters): ";
    string name;
    cin.ignore();
    getline(cin, name);
    cout << "Enter price: ";
    string price;
    cin >> price;
    
    if(bizniz.isValidName(name) && bizniz.isPriceDigit(price) && bizniz.isValidNameLength(name, MAXCHARINDRINKNAME)){
        
        int intPrice = stoi(price);
        char tempName[MAXCHARINDRINKNAME];
        strcpy(tempName, name.c_str());
        Drink temp(tempName, intPrice);
        bizniz.addDrink(temp);
        cout << endl << "Drink added!" << endl << endl;
    }
}


void AdminUI::removeDrink(){
    
    vector<Drink> drinks = bizniz.getVectorOfDrinks();
    cout << endl;
    cout << endl << "----------------------------List of all drinks------------------------------" << endl;
    
    if(drinks.size() < 1){
        cout << endl << "The file is empyt :(" << endl << endl;
    } else {
        for(int i = 0; i < drinks.size(); i++){
            Drink temp = drinks.at(i);
            cout << "Drink number: " << i+1 << endl;
            cout <<  temp << endl;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
        
        string input;
        cout << "Choose a drink to remove: ";
        cin >> input;
        
        if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), drinks.size())){
            
            int intInput = stoi(input);
            
            if(intInput < 1 ||intInput > (drinks.size())){
                cout << "No drink chosen" << endl << endl;
            } else {
                bizniz.removeDrink(drinks, intInput);
                cout << endl << "Drink removed!" << endl << endl;
            }
        }
    }
}



void AdminUI::displaySizeMenu(){
    char input = '\0';
    while(input != 'b'){
        cout << "1: List sizes" << endl;
        cout << "2: Change a size" << endl;
        cout << "3: Add a size" << endl;
        cout << "4: Remove a size" << endl;
        cout << "b: back" << endl;
        cin >> input;
        cout << endl;

        if(input == '1'){
            magic.clearScreen();
            displayAllSizes();
        }
        else if(input == '2'){
            magic.clearScreen();
            try {
                changeSize();
            } catch (InvalidInputException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidNameException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidPriceException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
        }
        else if(input == '3'){
            magic.clearScreen();
            try {
                addSize();
            } catch (InvalidNameException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidPriceException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
        }
        else if(input == '4'){
            magic.clearScreen();
            try {
                removeSize();
            } catch (InvalidInputException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
        }
    }
}

void AdminUI::displayAllSizes(){
    
    vector<Size> sizes = bizniz.getVectorOfSizes();
    cout << endl << "----------------------------List of all sizes-------------------------------" << endl;
    
    if(sizes.size() < 1){
        cout << endl << "The file is empty :(" << endl;
    } else {
        for (int i = 0; i < sizes.size(); i++) {
            Size temp = sizes.at(i);
            cout << temp;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
    }
    cout << endl;
}


void AdminUI::changeSize(){
    
    vector<Size> sizes = bizniz.getVectorOfSizes();
    cout << endl;
    cout << endl << "----------------------------List of all sizes-------------------------------" << endl;
    
    if(sizes.size() < 1){
        cout << endl << "The file is empty :(" << endl << endl;
    } else {
        for(int i = 0; i < sizes.size(); i++){
            Size temp = sizes.at(i);
            cout << "Size number: " << i+1 << endl;
            cout <<  temp;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
        
        string input;
        cout << "Choose a size to change: ";
        cin >> input;
        
        if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), sizes.size())){
            
            int intInput = stoi(input);
            
            for(int i = 0; i < sizes.size(); i++){
                if(intInput == i+1){
                    cout << "Enter size name (Max " << MAXCHARINSIZENAME-1-1 << " letters): ";
                    string name;
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter price: ";
                    string price;
                    cin >> price;
                    
                    if(bizniz.isValidName(name) && bizniz.isPriceDigit(price) && bizniz.isValidNameLength(name, MAXCHARINSIZENAME-1)){
                        int intPrice = stoi(price);
                        char tempName[MAXCHARINSIZENAME];
                        strcpy(tempName, name.c_str());
                        Size temp(tempName, intPrice);
                        sizes.at(i) = temp;
                        cout << endl << "Size changed" << endl << endl;
                    }
                }
            }
            bizniz.storeVectorOfSizes(sizes);
        }
    }
}


void AdminUI::addSize(){

    cout << "Adding a size!" << endl << endl;
    cout << "Enter size name (Max " << MAXCHARINSIZENAME-1-1 << " letters): ";
    string name;
    cin.ignore();
    getline(cin, name);
    cout << "Enter price: ";
    string price;
    cin >> price;
    
    if(bizniz.isValidName(name) && bizniz.isPriceDigit(price) && bizniz.isValidNameLength(name, MAXCHARINSIZENAME-1)){
        
        int intPrice = stoi(price);
        char tempName[MAXCHARINSIZENAME];
        strcpy(tempName, name.c_str());
        Size temp(tempName, intPrice);
        bizniz.addSize(temp);
        cout << endl << "Size added!" << endl << endl;
    }
}


void AdminUI::removeSize(){
    
    vector<Size> sizes = bizniz.getVectorOfSizes();
    cout << endl;
    cout << endl << "----------------------------List of all sizes-------------------------------" << endl;
    
    if(sizes.size() < 1){
        cout << endl << "The file is empty :(" << endl << endl;
    } else {
        for(int i = 0; i < sizes.size(); i++){
            Size temp = sizes.at(i);
            cout << "Size number: " << i+1 << endl;
            cout <<  temp;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }

        
        string input;
        cout << "Choose a size to remove: ";
        cin >> input;
        
        if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), sizes.size())){
            
            int intInput = stoi(input);
            
            if(intInput < 1 ||intInput > (sizes.size())){
                cout << "No size chosen" << endl << endl;
            } else {
                bizniz.removeSize(sizes, intInput);
                cout << endl << "Size removed!" << endl << endl;
            }
        }
    }
}


void AdminUI::displayBaseMenu(){
    char input = '\0';
    while(input != 'b'){
        cout << "1: List bases" << endl;
        cout << "2: Change a base" << endl;
        cout << "3: Add a base" << endl;
        cout << "4: Remove a base" << endl;
        cout << "b: back" << endl;
        cin >> input;
        cout << endl;

        if(input == '1'){
            magic.clearScreen();
            displayAllBases();
        }
        else if(input == '2'){
            magic.clearScreen();
            try {
                changeBase();
            } catch (InvalidInputException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidNameException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidPriceException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
        }
        else if(input == '3'){
            magic.clearScreen();
            try {
                addBase();
            } catch (InvalidNameException e) {
                cout << endl << e.getMessage() << endl << endl;
            } catch (InvalidPriceException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
            
        }
        else if(input == '4'){
            magic.clearScreen();
            try {
                removeBase();
            } catch (InvalidInputException e) {
                cout << endl << e.getMessage() << endl << endl;
            }
            
        }
    }
}
void AdminUI::displayAllBases(){
    
    vector<Base> bases = bizniz.getVectorOfBases();
    cout << endl << "----------------------------List of all bases-------------------------------" << endl;
    if(bases.size() < 1){
        cout << endl << "The file is empty :("<< endl;
    } else {
        for (unsigned int i = 0; i < bases.size(); i++) {
            Base temp = bases.at(i);
            cout << temp;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
    }
    cout << endl;
}

void AdminUI::changeBase(){
    
    vector<Base> bases = bizniz.getVectorOfBases();
    cout << endl;
    cout << endl << "----------------------------List of all bases-------------------------------" << endl;
    
    if(bases.size() < 1){
        cout << endl << "The file is empty :(" << endl << endl;
    } else {
        for(int i = 0; i < bases.size(); i++){
            Base temp = bases.at(i);
            cout << "Base number: " << i+1 << endl;
            cout <<  temp;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
        
        string input;
        cout << "Choose a base to change: ";
        cin >> input;
        
        if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), bases.size())){
            
            int intInput = stoi(input);
            
            for(int i = 0; i < bases.size(); i++){
                if(intInput == i+1){
                    cout << "Enter size name (Max " << MAXCHARINBASENAME-1-1 << " letters): ";
                    string name;
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter price: ";
                    string price;
                    cin >> price;
                    
                    if(bizniz.isValidName(name) && bizniz.isPriceDigit(price) && bizniz.isValidNameLength(name, MAXCHARINBASENAME-1)){
                        int intPrice = stoi(price);
                        char tempName[MAXCHARINBASENAME];
                        strcpy(tempName, name.c_str());
                        Base temp(tempName, intPrice);
                        bases.at(i) = temp;
                        cout << endl << "Size changed" << endl << endl;
                    }
                }
            }
            bizniz.storeVectorOfBases(bases);
        }
    }
}

void AdminUI::addBase(){
    
    cout << "Adding a base!" << endl << endl;
    cout << "Enter base name (Max " << MAXCHARINBASENAME-1-1 << " letters): ";
    string name;
    cin.ignore();
    getline(cin, name);
    cout << "Enter price: ";
    string price;
    cin >> price;
    
    if(bizniz.isValidName(name) && bizniz.isPriceDigit(price) && bizniz.isValidNameLength(name, MAXCHARINBASENAME-1)){
        
        int intPrice = stoi(price);
        char tempName[MAXCHARINBASENAME];
        strcpy(tempName, name.c_str());
        Base temp(tempName, intPrice);
        bizniz.addBase(temp);
        cout << endl << "Base added!" << endl << endl;
    }
}

void AdminUI::removeBase(){
    
    vector<Base> bases = bizniz.getVectorOfBases();
    cout << endl;
    cout << endl << "----------------------------List of all bases-------------------------------" << endl;
    
    if(bases.size() < 1){
        cout << endl << "The file is empty :(" << endl << endl;
    } else {
        for(int i = 0; i < bases.size(); i++){
            Base temp = bases.at(i);
            cout << "Base number: " << i+1 << endl;
            cout <<  temp;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
        cout << endl;

        string input;
        cout << "Choose a base to remove: ";
        cin >> input;
        
        if(bizniz.isInputDigit(input) && bizniz.isValidInput(stoi(input), bases.size())){
            
            int intInput = stoi(input);
            
            if(intInput < 1 ||intInput > (bases.size())){
                cout << "No base chosen" << endl << endl;
            } else {
                bizniz.removeBase(bases, intInput);
                cout << endl << "Base removed!" << endl << endl;
            }
        }
    }
}

void AdminUI::uiItemSeparator () {
    cout << setw(17) << " " << setfill(CHARFORSETFILL) << setw(SIZEOFSETW-41) << "-" << endl << endl;
    cout << setfill(' ');
}
