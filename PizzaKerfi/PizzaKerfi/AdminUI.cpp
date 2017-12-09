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
        cout << "1: Add/change the topping list" << endl;
        cout << "2: Add/change the location list" << endl;
        cout << "3: Add/change the side list" << endl;
        cout << "4: Add/change the drink list" << endl;
        cout << "5: Add/change the size list" << endl;
        cout << "6: Add/change the base list" << endl;
        cout << "b: back" << endl;
        cin >> input;
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
        cout << "1: List toppings" << endl;
        cout << "2: Change a topping" << endl;
        cout << "3: Add a topping" << endl;
        cout << "4: Remove a topping" << endl;
        cout << "b: back" << endl;
        cin >> input;
        cout << endl;

        if(input == '1'){
            magic.clearScreen();
            displayAllToppings();
        }
        else if(input == '2'){
            magic.clearScreen();
            changeTopping();
        }
        else if(input == '3'){
            magic.clearScreen();
            addTopping();
        }
        else if(input == '4'){
            magic.clearScreen();
            removeTopping();
        }
    }
}

//Prentar út lista yfir öll álegg sem eru í toppings.txt
void AdminUI::displayAllToppings(){

    ToppingRepo toppingRepo;
    vector<Topping> toppings = bizniz.getVectorOfToppings();
    cout << endl << "----------------------------List of all toppings----------------------------" << endl;
    if(toppings.size() < 1){
        cout << "The file is empty :(" << endl << endl;
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
    char input = 'y';

    while(input == 'y'){
        Topping temp;
        cout << "Adding a topping!" << endl << endl;
        cin >> temp;
        bizniz.addTopping(temp);
        cout << endl << "Do you want to add another topping? y/n" << endl;
        cin >> input;
        while(input != 'y' && input != 'n'){
            cout << endl << "Please enter either 'y' or 'n' " << endl;
            cin >> input;
        }
        cout << endl;
    }
}

//Tekur á móti vector af öllum áleggjum úr toppings.txt skránni og birtir það sem lista.
//Gerir notandanum kleift að velja álegg af listanum og breyta nafninu og verðinu á því.
void AdminUI::changeTopping(){

    vector<Topping> toppings = bizniz.getVectorOfToppings();
    cout << endl;

    char choice = 'y';

    while(choice == 'y')
    {
        cout << endl << "----------------------------List of all toppings----------------------------" << endl;
        for(int i = 0; i < toppings.size(); i++){
            Topping temp = toppings.at(i);
            cout << "Topping number: " << i+1 << endl;
            cout <<  temp;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
        int input = 0;
        cout << "Choose a topping to change: ";
        cin >> input;
        
        for(int i = 0; i < toppings.size(); i++){
            if(input == i+1){
                cin >> toppings.at(i);
                cout << endl << "Topping changed" << endl << endl;
            }
 
        }
        bizniz.storeVectorOfToppings(toppings);
        cout << "do you want to change another topping: y/n ";
        cin >> choice;
        cout << endl;
        while(choice != 'y' && choice != 'n'){
            cout << "Please enter either 'y' or 'n' ";
            cin >> choice;
            cout << endl;
        }
    }

}

//Tekur á móti vector af af öllum áleggjum úr toppings.txt skránni og birtir það sem lista.
//Gerir notandanum kleift að velja álegg af listanum og eyða því.
void AdminUI::removeTopping()
{
    vector<Topping> toppings = bizniz.getVectorOfToppings();
    cout << endl;

    char choice = 'y';

    while(choice == 'y'){
        cout << endl << "----------------------------List of all toppings----------------------------" << endl;
        for(int i = 0; i < toppings.size(); i++){
            Topping temp = toppings.at(i);
            cout << "Topping number: " << i+1 << endl;
            cout <<  temp;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }

        int input = 0;
        cout << "Choose a topping to remove: ";
        cin >> input;

        if(input < 1 ||input > (toppings.size())){
            cout << endl << "No topping chosen" << endl << endl;
        } else {
            bizniz.removeTopping(toppings, input);
            
            cout << endl << "Topping removed" << endl << endl;
        }
        cout << "do you want to change another topping: y/n ";
        cin >> choice;
        cout << endl;
        while(choice != 'y' && choice != 'n'){
            cout << "Please enter either 'y' or 'n' ";
            cin >> choice;
            cout << endl;
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
            cout << endl << "----------------------------List of all locations----------------------------" << endl;
            displayAllLocations();
            cout << endl;
        }
        else if(input == '2'){
            magic.clearScreen();
            changeLocation();
        }
        else if(input == '3'){
            magic.clearScreen();
            addLocation();
        }
        else if(input == '4'){
            magic.clearScreen();
            removeLocation();
        }
    }
}

//Prentar út lista yfir alla afhendingarstaði.
void AdminUI::displayAllLocations(){
    
    vector<Location> locations = bizniz.getVectorOfLocations();
    
    if(locations.size() < 1){
        cout << "The file is empty :(" << endl << endl;
    }
    
    for (int i = 0; i < locations.size(); i++) {
        Location temp = locations.at(i);
        cout << temp << endl;
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
    }
}

void AdminUI::addLocation(){
    
    char input = 'y';

    while(input == 'y'){
        Location temp;
        cout << "Adding a location!" << endl << endl;
        cin >> temp;
        bizniz.addLocation(temp);
        cout << endl << "Do you want to add another location? y/n ";
        cin >> input;
        while(input != 'y' && input != 'n'){
            cout << endl << "Please enter either 'y' or 'n' " << endl;
            cin >> input;
        }
        cout << endl;
    }
}
void AdminUI::changeLocation(){
   
    vector<Location> locations = bizniz.getVectorOfLocations();
    cout << endl;

    char choice = 'y';

    while(choice == 'y'){
        
        cout << endl << "----------------------------List of all locations----------------------------" << endl;
        for(int i = 0; i < locations.size(); i++){
            Location temp = locations.at(i);
            cout << "Location number: " << i+1 << endl;
            cout <<  temp << endl;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
        int input = 0;
        cout << "Choose a location to change: ";
        cin >> input;

        for(int i = 0; i < locations.size(); i++){
            if(input == i+1){
                cin >> locations.at(i);
                cout << endl << "Location changed" << endl << endl;
            }
        }
        bizniz.storeVectorOfLocations(locations);
        cout << "do you want to change another location: y/n ";
        cin >> choice;
        cout << endl;
        while(choice != 'y' && choice != 'n'){
            cout << "Please enter either 'y' or 'n' ";
            cin >> choice;
            cout << endl;
        }
    }
}

void AdminUI::removeLocation(){

    vector<Location> locations = bizniz.getVectorOfLocations();
    cout << endl;

    char choice = 'y';

    while(choice == 'y'){
        cout << endl << "----------------------------List of all locations----------------------------" << endl;
        for(int i = 0; i < locations.size(); i++){
            Location temp = locations.at(i);
            cout << "Location number: " << i+1 << endl;
            cout <<  temp << endl;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }

        int input = 0;
        cout << "Choose a location to remove: ";
        cin >> input;

        if(input < 1 ||input > (locations.size())){
            cout << endl << "No location chosen" << endl << endl;
        } else {
            bizniz.removeLocation(locations, input);
            
            cout << endl << "Location removed" << endl << endl;
        }
        cout << "do you want to change another location: y/n ";
        cin >> choice;
        cout << endl;
        while(choice != 'y' && choice != 'n'){
            cout << "Please enter either 'y' or 'n' ";
            cin >> choice;
            cout << endl;
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
            changeSide();
        }
        else if(input == '3'){
            magic.clearScreen();
            addSide();
        }
        else if(input == '4'){
            magic.clearScreen();
            removeSide();
        }
    }
}


void AdminUI::displayAllSides(){
    
    vector<Side> sides = bizniz.getVectorOfSides();
    
    cout << endl << "----------------------------List of all sides----------------------------" << endl;
    
    if(sides.size() < 1){
        cout << "The file is empty :(" << endl << endl;
    }
    
    for (int i = 0; i < sides.size(); i++) {
        
        Side temp = sides.at(i);
        cout << temp << endl;
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
    }
    cout << endl;
}


void AdminUI::addSide(){
    char input = 'y';

    while(input == 'y'){
        cout << "Adding a side!" << endl << endl;
        Side temp;
        cin >> temp;
        bizniz.addSide(temp);
        cout << endl << "Do you want to add another side? y/n" << endl;
        cin >> input;
        while(input != 'y' && input != 'n'){
            cout << endl << "Please enter either 'y' or 'n' " << endl;
            cin >> input;
        }
        cout << endl;
    }
}


void AdminUI::changeSide(){

    vector<Side> sides = bizniz.getVectorOfSides();
    cout << endl;

    char choice = 'y';

    while(choice == 'y')
    {
        cout << endl << "----------------------------List of all sides----------------------------" << endl;
        for(int i = 0; i < sides.size(); i++){
            Side temp = sides.at(i);
            cout << "Side number: " << i+1 << endl;
            cout <<  temp << endl;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
        int input = 0;
        cout << "Choose a side to change: ";
        cin >> input;

        for(int i = 0; i < sides.size(); i++){
            if(input == i+1){
                cin >> sides.at(i);
                cout << endl << "Side changed" << endl << endl;
            }
        }
        bizniz.storeVectorOfSides(sides);
        cout << "do you want to change another side: y/n ";
        cin >> choice;
        cout << endl;
        while(choice != 'y' && choice != 'n'){
            cout << "Please enter either 'y' or 'n' ";
            cin >> choice;
            cout << endl;
        }
    }
}


void AdminUI::removeSide(){
    
    vector<Side> sides = bizniz.getVectorOfSides();
    cout << endl;

    char choice = 'y';

    while(choice == 'y'){
        cout << endl << "----------------------------List of all sides----------------------------" << endl;
        for(int i = 0; i < sides.size(); i++){
            Side temp = sides.at(i);
            cout << "Side number: " << i+1 << endl;
            cout <<  temp << endl;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }

        int input = 0;
        cout << "Choose a side to remove: ";
        cin >> input;

        if(input < 1 ||input > (sides.size())){
            cout << "No side chosen" << endl << endl;
        } else {
            bizniz.removeSide(sides, input);
            cout << endl << "Side removed" << endl << endl;
        }
        cout << "Do you want to change another side: y/n ";
        cin >> choice;
        cout << endl;
        while(choice != 'y' && choice != 'n'){
            cout << "Please enter either 'y' or 'n' ";
            cin >> choice;
            cout << endl;
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
            changeDrink();
        }
        else if(input == '3'){
            magic.clearScreen();
            addDrink();
        }
        else if(input == '4'){
            magic.clearScreen();
            removeDrink();
        }
    }
}

void AdminUI::displayAllDrinks(){
    
    vector<Drink> drinks = bizniz.getVectorOfDrinks();
    cout << endl << "----------------------------List of all drinks----------------------------" << endl;
    if(drinks.size() < 1){
        cout << "The file is empty :(" << endl << endl;
    }
    
    for (int i = 0; i < drinks.size(); i++) {
        Drink temp = drinks.at(i);
        cout << temp << endl;
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
    }
    cout << endl;
}

void AdminUI::changeDrink(){
    
    vector<Drink> drinks = bizniz.getVectorOfDrinks();
    cout << endl;

    char choice = 'y';

    while(choice == 'y'){
        cout << endl << "----------------------------List of all drinks----------------------------" << endl;
        for(int i = 0; i < drinks.size(); i++){
            Drink temp = drinks.at(i);
            cout << "Drink number: " << i+1 << endl;
            cout <<  temp;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
        int input = 0;
        cout << "Choose a drink to change: ";
        cin >> input;

        for(int i = 0; i < drinks.size(); i++){
            if(input == i+1){
                cin >> drinks.at(i);
                cout << endl << "Drink changed" << endl << endl;
            }
        }
        bizniz.storeVectorOfDrinks(drinks);
        cout << "Do you want to change another drink: y/n ";
        cin >> choice;
        cout << endl;
        while(choice != 'y' && choice != 'n'){
            cout << "Please enter either 'y' or 'n' ";
            cin >> choice;
            cout << endl;
        }
    }
}

void AdminUI::addDrink(){
    char input = 'y';

    while(input == 'y'){
        cout << "Adding drink!" << endl;
        Drink temp;
        cin >> temp;
        bizniz.addDrink(temp);
        cout << endl << "Do you want to add another drink? y/n" << endl;
        cin >> input;
        while(input != 'y' && input != 'n'){
            cout << endl << "Please enter either 'y' or 'n' " << endl;
            cin >> input;
        }
        cout << endl;
    }
}


void AdminUI::removeDrink(){
    
    vector<Drink> drinks = bizniz.getVectorOfDrinks();
    cout << endl;

    char choice = 'y';

    while(choice == 'y'){
        cout << endl << "----------------------------List of all drinks----------------------------" << endl;
        for(int i = 0; i < drinks.size(); i++){
            Drink temp = drinks.at(i);
            cout << "Drink number: " << i+1 << endl;
            cout <<  temp << endl;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }

        int input = 0;
        cout << "Choose a drink to remove: ";
        cin >> input;

        if(input < 1 ||input > (drinks.size())){
            cout << endl << "No drink chosen" << endl << endl;
        }
        else{
            bizniz.removeDrink(drinks, input);
            
            cout << endl << "Drink removed" << endl << endl;
        }
        cout << "do you want to change another drink: y/n ";
        cin >> choice;
        cout << endl;
        while(choice != 'y' && choice != 'n'){
            cout << "Please enter either 'y' or 'n' ";
            cin >> choice;
            cout << endl;
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
            changeSize();
        }
        else if(input == '3'){
            magic.clearScreen();
            addSize();
        }
        else if(input == '4'){
            magic.clearScreen();
            removeSize();
        }
    }
}

void AdminUI::displayAllSizes(){
    
    vector<Size> sizes = bizniz.getVectorOfSizes();
    cout << endl << "----------------------------List of all sizes----------------------------" << endl;
    if(sizes.size() < 1){
        cout << "The file is empty :(" << endl << endl;
    }
    
    for (int i = 0; i < sizes.size(); i++) {
        Size temp = sizes.at(i);
        cout << temp;
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
    }
}


void AdminUI::changeSize(){
    
    vector<Size> sizes = bizniz.getVectorOfSizes();
    cout << endl;

    char choice = 'y';

    while(choice == 'y')
    {
        cout << endl << "----------------------------List of all sizes----------------------------" << endl;
        for(int i = 0; i < sizes.size(); i++){
            Size temp = sizes.at(i);
            cout << "Size number: " << i+1 << endl;
            cout <<  temp;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
        int input = 0;
        cout << "Choose a size to change: ";
        cin >> input;

        for(int i = 0; i < sizes.size(); i++){
            if(input == i+1){
                cin >> sizes.at(i);
                cout << endl << "Size changed" << endl << endl;
            }
        }
        bizniz.storeVectorOfSizes(sizes);
        cout << "Do you want to change another size: y/n ";
        cin >> choice;
        cout << endl;
        while(choice != 'y' && choice != 'n'){
            cout << "Please enter either 'y' or 'n' ";
            cin >> choice;
            cout << endl;
        }
    }
}


void AdminUI::addSize(){
    char input = 'y';

    while(input == 'y'){
        Size temp;
        cout << "Adding size!" << endl << endl;
        cin >> temp;
        bizniz.addSize(temp);
        cout << endl << "Do you want to add another size? y/n" << endl;
        cin >> input;
        while(input != 'y' && input != 'n'){
            cout << endl << "Please enter either 'y' or 'n' " << endl;
            cin >> input;
        }
        cout << endl;
    }
}


void AdminUI::removeSize(){
    
    vector<Size> sizes = bizniz.getVectorOfSizes();
    cout << endl;

    char choice = 'y';

    while(choice == 'y'){
        cout << endl << "----------------------------List of all sizes----------------------------" << endl;
        for(int i = 0; i < sizes.size(); i++){
            Size temp = sizes.at(i);
            cout << "Size number: " << i+1 << endl;
            cout <<  temp;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }

        int input = 0;
        cout << "Choose a size to remove: ";
        cin >> input;

        if(input < 1 ||input > (sizes.size())){
            cout << endl << "No size chosen" << endl << endl;
        }
        else {
            bizniz.removeSize(sizes, input);
            
            cout << endl << "Size removed" << endl << endl;
        }
        cout << "do you want to change another size: y/n ";
        cin >> choice;
        cout << endl;
        while(choice != 'y' && choice != 'n'){
            cout << "Please enter either 'y' or 'n' ";
            cin >> choice;
            cout << endl;
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
            changeBase();
        }
        else if(input == '3'){
            magic.clearScreen();
            addBase();
        }
        else if(input == '4'){
            magic.clearScreen();
            removeBase();
        }
    }
}
void AdminUI::displayAllBases(){
    
    vector<Base> bases = bizniz.getVectorOfBases();
    cout << endl << "----------------------------List of all bases----------------------------" << endl;
    if(bases.size() < 1){
        cout << "The file is empty :(" << endl << endl;
    }
    
    for (unsigned int i = 0; i < bases.size(); i++) {
        Base temp = bases.at(i);
        cout << temp;
        cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
    }
    
}

void AdminUI::changeBase(){
    
    vector<Base> bases = bizniz.getVectorOfBases();
    cout << endl;

    char choice = 'y';

    while(choice == 'y')
    {
        cout << endl << "----------------------------List of all bases----------------------------" << endl;
        for(int i = 0; i < bases.size(); i++){
            Base temp = bases.at(i);
            cout << "Base number: " << i+1 << endl;
            cout <<  temp;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }
        int input = 0;
        cout << "Choose a base to change: ";
        cin >> input;
        
        if(input < 1 ||input > (bases.size())){
            cout << "No base chosen" << endl << endl;
        }
        else {
            for(int i = 0; i < bases.size(); i++){
                if(input == i+1){
                    cin >> bases.at(i);
                }
            }
            bizniz.storeVectorOfBases(bases);
            cout << endl << "Base changed" << endl << endl;
        }
        cout << "Do you want to change another base: y/n ";
        cin >> choice;
        cout << endl;
        while(choice != 'y' && choice != 'n'){
            cout << "Please enter either 'y' or 'n' ";
            cin >> choice;
            cout << endl;
            }
        
    }
}

void AdminUI::addBase(){
    char input = 'y';

    while(input == 'y'){
        
        Base temp;
        cout << "Add bases!" << endl << endl;
        cin >> temp;
        bizniz.addBase(temp);
        cout << endl << "Do you want to add another base? y/n" << endl;
        cin >> input;
        while(input != 'y' && input != 'n'){
            cout << endl << "Please enter either 'y' or 'n' " << endl;
            cin >> input;
        }
        cout << endl;
    }

}


void AdminUI::removeBase(){
    
    vector<Base> bases = bizniz.getVectorOfBases();
    cout << endl;

    char choice = 'y';

    while(choice == 'y'){
        cout << endl << "----------------------------List of all bases----------------------------" << endl;
        for(int i = 0; i < bases.size(); i++){
            Base temp = bases.at(i);
            cout << "Size number: " << i+1 << endl;
            cout <<  temp;
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl;
        }

        int input = 0;
        cout << "Choose a base to remove: ";
        cin >> input;

        if(input < 1 ||input > (bases.size())){
            cout << endl << "No base chosen" << endl << endl;
        }
        else{
            bizniz.removeBase(bases, input);
            cout << endl << "Size removed" << endl << endl;
        }
        cout << "do you want to change another base: y/n ";
        cin >> choice;
        cout << endl;
        while(choice != 'y' && choice != 'n'){
            cout << "Please enter either 'y' or 'n' ";
            cin >> choice;
            cout << endl;
        }
    }
}
