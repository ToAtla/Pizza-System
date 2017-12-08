//
//  Global.hpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 06/12/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef Global_hpp
#define Global_hpp

#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

const char CHARFORSETFILL = '-';
const int INTFORADMINUISETW = 76;
const int MAXCHARSINBASENAME = 4;
const int MAXCHARINSIZENAME = 15;
const int MAXCHARINSIDENAME = 30;
const int MAXCHARINDRINKNAME = 10;
const int MAXCHARINLOCATIONNAME = 30;
const int MAXTOPPINGS = 16;
const int MAXCHARSINTOPPINGNAME = 20;
const int MAXSTUFFSINORDER = 20;
const int MAXCHARINSTATUSSTRING = 10;
const int MAXCHARINPRICESTRING = 5;
const int MAXCHARINSTATUSANDPRICESTRING = 40;
const int SIZEOFSPACEBETWEENPIZZASTATUSANDPRICE = 10;

const string TABSTRING = "\t\t\t\t\t\t\t\t\t\t\t\t\t";
const string HALFTABSTRING = "\t\t\t\t\t";
const string LONGLINE = "-----------------------------------------------------------------";
enum status {WAITING, PREPPING, READY, DELIVERED};

const string PIZZAFILE = "pizzas.dat";
#endif /* Global_hpp */
