//
//  MenuItemRepo.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/13/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef MenuItemRepo_hpp
#define MenuItemRepo_hpp

#include <stdio.h>

#include <vector>
#include "MenuItem.hpp"
#include "Global.hpp"

using namespace std;

class MenuItemRepo{
    
public:
    void addMenuItem(MenuItem& MenuItem);
    void displayMenuItem();
    MenuItem* getArrayOfMenuItems(int& tellMeHowMany);
    void storeArrayOfMenuItems(char menuItems[]);
private:
    void clearMenuItems();
    void createMenuItem();
};


#endif /* MenuItemRepo_hpp */
