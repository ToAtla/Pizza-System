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

//MUNA AÐ SKILJA EFTIR PLÁSS FYRIR NULLCHARACTER Í LOKIN


const char CHARFORSETFILL = '-';
const char CHARFORSUBACTION = '+';
const char CHARFORSPACE = ' ';
const int SIZEOFTABSTRING = 48;
const int SIZEOFSETW = 76;
const int SIZEOFSETWBIG = 100;
const int MAXCHARINBASENAME = 5;
const int MAXCHARINSIZENAME = 5;
const int MAXCHARINSIDENAME = 20;
const int MAXCHARINDRINKNAME = 10;
const int MAXCHARINLOCATIONNAME = 15;
const int MAXCHARINTOPPINGNAME = 4;
const int MAXSTUFFSINORDER = 20;
const int MAXCHARINSTATUSSTRING = 10;
const int MAXCHARINORDERSTATUSSTRING = 10;
const int MAXCHARINPRICESTRING = 5;
const int MAXCHARINSTATUSANDPRICESTRING = 40;
const int SIZEOFSPACEBETWEENPIZZASTATUSANDPRICE = 10;

const int SIZEOFTOPPINGSUBMENUNUM = 30;
const int SIZEOFTOPPINGSUBMENUCHAR = 24;
const int SIZEOFNUMBERLISTADMINUI = 20;
const int SIZEOFLISTNAMEADMINUI = 32;
const int SIZEOFADDTOPPINGSPACES = 42;

const int MAXTOPPINGSONPIZZA = 16;
const int MAXCHARSINPIZZANAME = 100;
const int MAXCHARSINPIZZASIZE = 4;
const int MAXPIZZASINPIZZAFILE = 20;
const int MAXCHARINORDERCOMMENT = SIZEOFSETWBIG-8;

const string TABSTRING = "\t\t\t\t\t\t\t\t\t\t\t\t\t";
const string HALFTABSTRING = "\t\t\t\t\t";
const string NINETABSTRING = "\t\t\t\t\t\t\t\t\t";
const string LONGLINE = "---------------------------------------------------------------------------";
enum status {WAITING, PREPPING, READY, OUTOFSHOP};
enum orderStatus {UNPAID, PAID, DELIVERED};

const string PIZZAFILE = "pizzas.dat";
const string ORDERFILE = "orders.dat";
const string BASEFILE = "bases.dat";
#endif /* Global_hpp */
