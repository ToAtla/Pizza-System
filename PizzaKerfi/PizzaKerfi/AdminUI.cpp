//
//  AdminUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "AdminUI.hpp"
#include "ToppingRepo.hpp"
#include "LocationRepo.hpp"
#include "Location.hpp"
#include <fstream>
#include <iostream>

using namespace std;


//Prentar út valmynd sem býður notandanum að velja það sem hann vill fikta í.
void AdminUI::startAdminUI(){

    char input = 0;
    while(input != 'b'){
        cout << "1: Add/change the topping list" << endl;
        cout << "2: Add/change the location list" << endl;
        cout << "b: back" << endl;
        cin >> input;
        cout << endl;

        if(input == '1'){
            displayToppingMenu();

        }
        if(input == '2'){
            displayLocationMenu();
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
            cout << endl << "-----List of all topings-----" << endl;
            cout << endl << endl;
            displayAllToppings();
            cout << endl;
        }
        else if(input == '2'){
            changeTopping();
        }
        else if(input == '3'){
            addTopping();
        }
        else if(input == '4'){
            removeTopping();
        }
    }
}

//Prentar út lista yfir öll álegg sem eru í toppings.txt
void AdminUI::displayAllToppings(){

    ToppingRepo toppingRepo;
    vector<Topping> toppings = toppingRepo.getVectorOfToppings();
    for (int i = 0; i < toppings.size(); i++) {
        Topping temp = toppings.at(i);
        cout << temp << endl;
    }
}

//Bætir við áleggi í textaskránna toppings.txt
void AdminUI::addTopping(){
    char input = 'y';

    while(input == 'y'){
        ToppingRepo toppingRepo;
        Topping temp;
        cin >> temp;
        toppingRepo.addTopping(temp);
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

    ToppingRepo toppingRepo;
    vector<Topping> toppings = toppingRepo.getVectorOfToppings();
    cout << endl;

    char choice = 'y';

    while(choice == 'y')
    {
        for(int i = 0; i < toppings.size(); i++){
            Topping temp = toppings.at(i);
            cout << "Topping number: " << i+1 << endl;
            cout <<  temp << endl;
        }
        int input = 0;
        cout << "Choose a topping to change: ";
        cin >> input;

        for(int i = 0; i < toppings.size(); i++){
            if(input == i+1){
                cin >> toppings.at(i);
            }
        }
        toppingRepo.storeVectorOfToppings(toppings);
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
    ToppingRepo toppingRepo;
    vector<Topping> toppings = toppingRepo.getVectorOfToppings();
    cout << endl;

    char choice = 'y';

    while(choice == 'y'){
    for(int i = 0; i < toppings.size(); i++){
        Topping temp = toppings.at(i);
        cout << "Topping number: " << i+1 << endl;
        cout <<  temp << endl;
    }

    int input = 0;
    cout << "Choose a topping to remove: ";
    cin >> input;

    for(int i = 0; i < toppings.size(); i++){
        if(input == i+1){
            toppings.erase(toppings.begin() + i);
        }
    }
    toppingRepo.storeVectorOfToppings(toppings);
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
            cout << endl << "-----List of all locations-----" << endl << endl;
            displayAllLocations();
            cout << endl;
        }
        else if(input == '2'){
            changeLocation();
        }
        else if(input == '3'){
            addLocation();
        }
        else if(input == '4'){
            removeLocation();
        }
    }
}

void AdminUI::displayAllLocations(){
       //Prentar út lista yfir öll álegg.
    LocationRepo locationRepo;
    vector<Location> locations = locationRepo.getVectorOfLocations();
    for (int i = 0; i < locations.size(); i++) {
        Location temp = locations.at(i);
        cout << temp << endl;
    }
}

void AdminUI::addLocation(){
 char input = 'y';

    while(input == 'y'){
        LocationRepo LocationRepo;
        Location temp;
        cin >> temp;
        LocationRepo.storeLocation(temp);
        cout << endl << "Do you want to add another location? y/n" << endl;
        cin >> input;
        while(input != 'y' && input != 'n'){
            cout << endl << "Please enter either 'y' or 'n' " << endl;
            cin >> input;
        }
        cout << endl;
    }
}
void AdminUI::changeLocation(){
    LocationRepo locationRepo;
    vector<Location> locations = locationRepo.getVectorOfLocations();
    cout << endl;

    char choice = 'y';

    while(choice == 'y')
    {
        for(int i = 0; i < locations.size(); i++){
            Location temp = locations.at(i);
            cout << "Location number: " << i+1 << endl;
            cout <<  temp << endl;
        }
        int input = 0;
        cout << "Choose a location to change: ";
        cin >> input;

        for(int i = 0; i < locations.size(); i++){
            if(input == i+1){
                cin >> locations.at(i);
            }
        }
        locationRepo.storeVectorOfLocations(locations);
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
    LocationRepo locationRepo;
    vector<Location> locations = locationRepo.getVectorOfLocations();
    cout << endl;

    char choice = 'y';

    while(choice == 'y'){
    for(int i = 0; i < locations.size(); i++){
        Location temp = locations.at(i);
        cout << "Location number: " << i+1 << endl;
        cout <<  temp << endl;
    }

    int input = 0;
    cout << "Choose a location to remove: ";
    cin >> input;

    for(int i = 0; i < locations.size(); i++){
        if(input == i+1){
            locations.erase(locations.begin() + i);
        }
    }
    locationRepo.storeVectorOfLocations(locations);
    cout << endl << "Location removed" << endl << endl;
    cout << "do you want to change another Location: y/n ";
    cin >> choice;
    cout << endl;
    while(choice != 'y' && choice != 'n'){
        cout << "Please enter either 'y' or 'n' ";
        cin >> choice;
        cout << endl;
    }
    }

}
