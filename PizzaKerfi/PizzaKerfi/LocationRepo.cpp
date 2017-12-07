//
//  LocationRepo.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 30/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "LocationRepo.hpp"
#include "Location.hpp"
#include <iostream>
#include <fstream>
using namespace std;


LocationRepo::LocationRepo(){
}


void LocationRepo::addLocation(Location& location){
    ofstream fout;
    fout.open("locations.dat", ios::binary|ios::app);
    fout.write((char*)(&location), sizeof(Location));
    fout.close();
}

vector<Location> LocationRepo::getVectorOfLocations(){
    
    vector<Location> locations;
    ifstream fin;
    fin.open("locations.dat", ios::binary);
    fin.seekg(0, fin.end);
    int numberOfLocations = (int)(fin.tellg() / sizeof(Location));
    fin.seekg(0, fin.beg);
    
    //Almennt gerum við svona.
    //fin.read((char*)(&drinks), sizeof(Drink)*numberOfDrinks);
    //En ekki í þessu tilviki
    //Því búið er að hanna klasan í kringum vektora
    
    for (int i = 0; i < numberOfLocations; i++) {
        Location tempLocation;
        fin.read((char*)(&tempLocation), sizeof(Location));
        locations.push_back(tempLocation);
    }
    return locations;
}

void LocationRepo::storeVectorOfLocations(vector<Location> locations){
    
    clearLocations();
    
    ofstream fout;
    fout.open("locations.dat", ios::binary|ios::app);
    for(int i = 0; i < locations.size(); i++){
        Location tempLocation = locations.at(i);
        fout.write((char*)(&tempLocation), sizeof(Location));
    }
    fout.close();

}

void LocationRepo::clearLocations(){
    ofstream fout;
    fout.open("locations.dat", ios::binary);
    fout.close();
}









//Les inn heimilisföng úr textaskjali inn í vector.
/*
vector<string> LocationRepo::displayLocations(){

vector<string> branches;
ifstream textFile ("Branches.txt");
string line;

while(getline(textFile, line)){
    string new_line;
    new_line = line + "\n";
    branches.push_back(new_line);
}
cout << "Enter your location: " << "\n" << "\n";
for(unsigned int i = 0; i<branches.size(); i++){
cout << i+1 << ": " << branches.at(i);
}
return branches;
}
*/




