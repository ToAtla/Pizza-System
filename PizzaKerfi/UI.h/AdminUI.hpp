//
//  AdminUI.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef AdminUI_hpp
#define AdminUI_hpp

#include <stdio.h>
#include <iostream>
#include "ConsoleMagic.hpp"
#include "ToppingRepo.hpp"
#include "LocationRepo.hpp"
#include "Location.hpp"
#include "SideRepo.hpp"
#include "DrinkRepo.hpp"
#include "SizeRepo.hpp"
#include "BaseRepo.hpp"
#include "Bizniz.hpp"
#include <fstream>
#include <iostream>
#include "Global.hpp"

using namespace std;

class AdminUI{

    public:
        void startAdminUI();
    private:
        Bizniz bizniz;
        ConsoleMagic magic;
    
        void displayToppingMenu();
        //Prentar út valmynd sem býður notandanum uppá að velja það sem hann vill gera með topping listann.
        //Sub menu undir Topping.
        void displayAllToppings();
        //Prentar út lista yfir öll álegg í boði.
        void addTopping();
        //Bætir við áleggi á listann.
        void changeTopping();
        //Gerir notandanum kleift að velja alegg af listanum og breyta nafninu og verðinu á því.
        void removeTopping();
        //Gerir notandanum kleift að velja álegg af listanum og eyða því.

        void displayLocationMenu();
        //Prentar út valmynd sem býður notandanum uppá að velja það sem hann vill gera með location listann.
        //Sub menu undir Location.
        void displayAllLocations();
        //Prentar út lista yfir alla afhendingarstaði í boði.
        void addLocation();
        //Bætir við afhendingarstaði á listann.
        void changeLocation();
        //Gerir notandanum kleift að velja afhengindarstað af listanum og breyta nafninu á honum.
        void removeLocation();
        //Gerir notandanum kleift að velja afhendingar af listanum og eyða honum.

        void displaySideMenu();
        //Prentar út valmynd sem býður notandanum uppá að velja það sem hann vill gera með side listann.
        //Sub menu undir Side.
        void displayAllSides();
        //Prentar út lista yfir öll meðlæti í boði.
        void addSide();
        //Bætir við meðlæti á listann.
        void changeSide();
        //Gerir notandanum kleift að velja stærð af listanum og breyta nafninu á og verðinu á því.
        void removeSide();
        //Gerir notandanum kleift að velja stærð af listanum og eyða henni.

        void displayDrinkMenu();
        //Prentar út valmynd sem býður notandanum uppá að velja það sem hann vill gera með drink listann.
        //Sub menu undir Drink.
        void displayAllDrinks();
        //Prentar út lista yfir alla drykki í boði.
        void addDrink();
        //Bætir við drykk á listann.
        void changeDrink();
        //Gerir notandanum kleift að velja drykk af listanum og breyta nafninu og verðinu á honum.
        void removeDrink();
        //Gerir notandanum kleift að velja drykk af listanum og eyða honum.
        
        void displaySizeMenu();
        //Prentar út valmynd sem býður notandanum uppá að velja það sem hann vill gera með size listann.
        //Sub menu undir Size.
        void displayAllSizes();
        //Prentar út lista yfir allar stærðir í boði.
        void addSize();
        //Bætir við stærð á listann.
        void changeSize();
        //Gerir notandanum kleift að velja stærð af listanum og breyta nafninu og verðinu á því.
        void removeSize();
        //Gerir notandanum kleift að velja stærð af listanum og eyða henni.
        
        void displayBaseMenu();
        //Prentar út valmynd sem býður notandanum uppá að velja það sem hann vill gera með base listann.
        //Sub menu undir Base.
        void displayAllBases();
        //Prentar út lista yfir alla botna í boði.
        void addBase();
        //Bætir við botn á listann.
        void changeBase();
        //Gerir notandanum kleift að velja botn af listanum og breyta nafninu og verðinu á því.
        void removeBase();
        //Gerir notandanum kleift að velja botn af listanum og eyða honum.
    
        void uiItemSeparator();
        void locationUIItemSeperator();
};

#endif /* AdminUI_hpp */
