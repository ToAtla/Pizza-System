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
        cout << "Addin a topping!" << endl << endl;
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
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl << endl;
        }
        int input = 0;
        cout << "Choose a topping to change: ";
        cin >> input;

        for(int i = 0; i < toppings.size(); i++){
            if(input == i+1){
                cin >> toppings.at(i);
            }
        }
        bizniz.storeVectorOfToppings(toppings);
        cout << endl << "Topping changed" << endl << endl;
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

        for(int i = 0; i < toppings.size(); i++){
            if(input == i+1){
                toppings.erase(toppings.begin() + i);
            }
        }
        bizniz.storeVectorOfToppings(toppings);
        cout << endl << "Topping removed" << endl << endl;
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
        cout << "Addin a location!" << endl << endl;
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
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl << endl;
            
        }
        int input = 0;
        cout << "Choose a location to change: ";
        cin >> input;

        for(int i = 0; i < locations.size(); i++){
            if(input == i+1){
                cin >> locations.at(i);
            }
        }
        bizniz.storeVectorOfLocations(locations);
        cout << endl << "Location changed" << endl << endl;
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
            cout << setfill(CHARFORSETFILL) << setw(SIZEOFSETW) << "-" << endl << endl;
        }

        int input = 0;
        cout << "Choose a location to remove: ";
        cin >> input;

        for(int i = 0; i < locations.size(); i++){
            if(input == i+1){
                locations.erase(locations.begin() + i);
            }
        }
        bizniz.storeVectorOfLocations(locations);
        cout << endl << "Location removed" << endl << endl;
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
            cout << endl << "-----List of all sides-----" << endl << endl;
            displayAllSides();
            cout << endl;
        }
        else if(input == '2'){
            changeSide();
        }
        else if(input == '3'){
            addSide();
        }
        else if(input == '4'){
            removeSide();
        }
    }
}


void AdminUI::displayAllSides(){
    
    vector<Side> sides = bizniz.getVectorOfSides();
    
    if(sides.size() < 1){
        cout << "The file is empty :(" << endl << endl;
    }
    
    for (int i = 0; i < sides.size(); i++) {
        Side temp = sides.at(i);
        cout << temp << endl;
    }
}


void AdminUI::addSide(){
    char input = 'y';

    while(input == 'y'){
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
        for(int i = 0; i < sides.size(); i++){
            Side temp = sides.at(i);
            cout << "Side number: " << i+1 << endl;
            cout <<  temp << endl;
        }
        int input = 0;
        cout << "Choose a side to change: ";
        cin >> input;

        for(int i = 0; i < sides.size(); i++){
            if(input == i+1){
                cin >> sides.at(i);
            }
        }
        bizniz.storeVectorOfSides(sides);
        cout << endl << "Side changed" << endl << endl;
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
        for(int i = 0; i < sides.size(); i++){
            Side temp = sides.at(i);
            cout << "Side number: " << i+1 << endl;
            cout <<  temp << endl;
        }

        int input = 0;
        cout << "Choose a side to remove: ";
        cin >> input;

        for(int i = 0; i < sides.size(); i++){
            if(input == i+1){
                sides.erase(sides.begin() + i);
            }
        }
        bizniz.storeVectorOfSides(sides);
        cout << endl << "Side removed" << endl << endl;
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
            cout << endl << "-----List of all drinks-----" << endl << endl;
            displayAllDrinks();
            cout << endl;
        }
        else if(input == '2'){
            changeDrink();
        }
        else if(input == '3'){
            addDrink();
        }
        else if(input == '4'){
            removeDrink();
        }
    }
}

void AdminUI::displayAllDrinks(){
    
    vector<Drink> drinks = bizniz.getVectorOfDrinks();
    
    if(drinks.size() < 1){
        cout << "The file is empty :(" << endl << endl;
    }
    
    for (int i = 0; i < drinks.size(); i++) {
        Drink temp = drinks.at(i);
        cout << temp << endl << endl;
    }
}

void AdminUI::changeDrink(){
    
    vector<Drink> drinks = bizniz.getVectorOfDrinks();
    cout << endl;

    char choice = 'y';

    while(choice == 'y')
    {
        for(int i = 0; i < drinks.size(); i++){
            Drink temp = drinks.at(i);
            cout << "Drink number: " << i+1 << endl;
            cout <<  temp << endl;
        }
        int input = 0;
        cout << "Choose a drink to change: ";
        cin >> input;

        for(int i = 0; i < drinks.size(); i++){
            if(input == i+1){
                cin >> drinks.at(i);
            }
        }
        bizniz.storeVectorOfDrinks(drinks);
        cout << endl << "Drink changed" << endl << endl;
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
        DrinkRepo drinkRepo;
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
        for(int i = 0; i < drinks.size(); i++){
            Drink temp = drinks.at(i);
            cout << "Drink number: " << i+1 << endl;
            cout <<  temp << endl;
        }

        int input = 0;
        cout << "Choose a drink to remove: ";
        cin >> input;

        for(int i = 0; i < drinks.size(); i++){
            if(input == i+1){
                drinks.erase(drinks.begin() + i);
            }
        }
        bizniz.storeVectorOfDrinks(drinks);
        cout << endl << "Drink removed" << endl << endl;
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
            cout << endl << "-----List of all sizes-----" << endl << endl;
            displayAllSizes();
            cout << endl;
        }
        else if(input == '2'){
            changeSize();
        }
        else if(input == '3'){
            addSize();
        }
        else if(input == '4'){
            removeSize();
        }
    }
}

void AdminUI::displayAllSizes(){
    
    vector<Size> sizes = bizniz.getVectorOfSizes();
    
    if(sizes.size() < 1){
        cout << "The file is empty :(" << endl << endl;
    }
    
    for (int i = 0; i < sizes.size(); i++) {
        Size temp = sizes.at(i);
        cout << temp << endl;
    }
}


void AdminUI::changeSize(){
    
    vector<Size> sizes = bizniz.getVectorOfSizes();
    cout << endl;

    char choice = 'y';

    while(choice == 'y')
    {
        for(int i = 0; i < sizes.size(); i++){
            Size temp = sizes.at(i);
            cout << "Size number: " << i+1 << endl;
            cout <<  temp << endl;
        }
        int input = 0;
        cout << "Choose a size to change: ";
        cin >> input;

        for(int i = 0; i < sizes.size(); i++){
            if(input == i+1){
                cin >> sizes.at(i);
            }
        }
        bizniz.storeVectorOfSizes(sizes);
        cout << endl << "Size changed" << endl << endl;
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
        for(int i = 0; i < sizes.size(); i++){
            Size temp = sizes.at(i);
            cout << "Size number: " << i+1 << endl;
            cout <<  temp << endl;
        }

        int input = 0;
        cout << "Choose a drink to remove: ";
        cin >> input;

        for(int i = 0; i < sizes.size(); i++){
            if(input == i+1){
                sizes.erase(sizes.begin() + i);
            }
        }
        bizniz.storeVectorOfSizes(sizes);
        cout << endl << "Size removed" << endl << endl;
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
            cout << endl << "-----List of all bases-----" << endl << endl;
            displayAllBases();
            cout << endl;
        }
        else if(input == '2'){
            changeBase();
        }
        else if(input == '3'){
            addBase();
        }
        else if(input == '4'){
            removeBase();
        }
    }
}
void AdminUI::displayAllBases(){
    
    vector<Base> bases = bizniz.getVectorOfBases();
    
    if(bases.size() < 1){
        cout << "The file is empty :(" << endl << endl;
    }
    
    for (unsigned int i = 0; i < bases.size(); i++) {
        Base temp = bases.at(i);
        cout << temp << endl;
    }
}

void AdminUI::changeBase(){
    
    vector<Base> bases = bizniz.getVectorOfBases();
    cout << endl;

    char choice = 'y';

    while(choice == 'y')
    {
        for(int i = 0; i < bases.size(); i++){
            Base temp = bases.at(i);
            cout << "Base number: " << i+1 << endl;
            cout <<  temp << endl;
        }
        int input = 0;
        cout << "Choose a base to change: ";
        cin >> input;

        for(int i = 0; i < bases.size(); i++){
            if(input == i+1){
                cin >> bases.at(i);
            }
        }
        bizniz.storeVectorOfBases(bases);
        cout << endl << "Base changed" << endl << endl;
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
        for(int i = 0; i < bases.size(); i++){
            Base temp = bases.at(i);
            cout << "Size number: " << i+1 << endl;
            cout <<  temp << endl;
        }

        int input = 0;
        cout << "Choose a drink to remove: ";
        cin >> input;

        for(int i = 0; i < bases.size(); i++){
            if(input == i+1){
                bases.erase(bases.begin() + i);
            }
        }
        bizniz.storeVectorOfBases(bases);
        cout << endl << "Size removed" << endl << endl;
        cout << "do you want to change another sizeb: y/n ";
        cin >> choice;
        cout << endl;
        while(choice != 'y' && choice != 'n'){
            cout << "Please enter either 'y' or 'n' ";
            cin >> choice;
            cout << endl;
        }
    }
}
