//
//  MenuItemRepo.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/13/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "MenuItemRepo.hpp"

void MenuItemRepo::addMenuItem(MenuItem& menuItem){
    ofstream fout;
    fout.open(MENUITEMFILE, ios::binary|ios::app);
    fout.write((char*)(&menuItem), sizeof(MenuItem));
    fout.close();
}

MenuItem* MenuItemRepo::getArrayOfMenuItems(int& tellMeHowMany){
    
    MenuItem* menuItems = new MenuItem[MAXPIZZASINPIZZAFILE];
    ifstream fin;
    fin.open(MENUITEMFILE, ios::binary);
    fin.seekg(0, fin.end);
    tellMeHowMany = (int)(fin.tellg()/sizeof(MenuItem));
    fin.seekg(0, fin.beg);
    fin.read((char*)(menuItems), sizeof(MenuItem)*tellMeHowMany);
    fin.close();
    
    return menuItems;
}
