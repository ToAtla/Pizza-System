//
//  MainUI.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 11/29/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "MainUI.hpp"

#include <stdlib.h>

void MainUI::startUI(){
    
    
    
    char input = '\0';
    while(input != 'q'){
        magic.clearScreen();
        cout << " _   _                          _____  ___                     " << endl;
        cout << "| | | |                        |  _  |/  |                     " << endl;
        cout << "| |_| | ___  _ __  _   _ _ __   \\ V / `| |                     " << endl;
        cout << "|  _  |/ _ \\| '_ \\| | | | '__|  / _ \\  | |                     " << endl;
        cout << "| | | | (_) | |_) | |_| | |    | |_| |_| |_                    " << endl;
        cout << "\\_| |_/\\___/| .__/ \\__,_|_|    \\_____/\\___/                    " << endl;
        cout << "| |                                                            " << endl;
        cout << "|_|                                                            " << endl;
        cout << " _   _           _    _            _   _      _     _          " << endl;
        cout << "| | | |         | |  | |          | | | |    (_)   | |         " << endl;
        cout << "| | | | ___ _ __| | _| | ___  __ _| | | | ___ _ ___| | __ _    " << endl;
        cout << "| | | |/ _ \\ '__| |/ / |/ _ \\/ _` | | | |/ _ \\ / __| |/ _` |   " << endl;
        cout << "\\ \\_/ /  __/ |  |   <| |  __/ (_| \\ \\_/ /  __/ \\__ \\ | (_| |   " << endl;
        cout << " \\___/ \\___|_|  |_|\\_\\_|\\___|\\__, |\\___/ \\___|_|___/_|\\__,_|   " << endl;
        cout << "                              __/ |                            " << endl;
        cout << "                              |___/                            " << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << " -------------------------------" << endl;
        cout << "|1: Manager     |2: Sales       |" << endl;
        cout << " -------------------------------" << endl;
        cout << "|3: Prep        |4: Delivery    |" << endl;
        cout << " -------------------------------" << endl;
        cout << "|q: quit        |" << endl;
        cout << " ---------------" << endl;
        cin >> input;
        cout << endl;
        
        if(input == '1'){
            magic.clearScreen();
            AdminUI adminUI;
            adminUI.startAdminUI();
        }
        else if(input == '2'){
            magic.clearScreen();
            SalesUI salesUI;
            salesUI.startSalesUI();
        }
        else if(input == '3'){
            magic.clearScreen();
            PrepUI prepUI;
            
            //The catch block catches an exceptions if the Location file is empty so the user can't access the prepUI if there are no locations available.
            try {
                prepUI.startPrepUI();
            } catch (InvalidFileLocationException) {
                magic.clearScreen();
                cout << endl << "You can't acces the prep menu because there are no locations available at this time!" << endl;
                cout << endl << "Please contact the manager." << endl << endl;
                cout << "Press any key to continue: ";
                string sInput;
                cin.ignore();
                getline(cin, sInput);
            }
            
        }
        else if(input == '4'){
            magic.clearScreen();
            DeliveryUI deliveryUI;
            
            //The catch block catches an exceptions if the Location file is empty so the user can't access the deliveryUI if there are no locations available.
            try {
                deliveryUI.startDeliveryUI();
            } catch (InvalidFileLocationException) {
                magic.clearScreen();
                cout << endl << "You can't acces the delivery menu because there are no locations available at this time!" << endl;
                cout << endl << "Please contact the manager." << endl << endl;
                cout << "Press any key to continue: ";
                string sInput;
                cin.ignore();
                getline(cin, sInput);
            }
            
        }
        else if(input == 'q'){
            break;
        }
       
    }
}
