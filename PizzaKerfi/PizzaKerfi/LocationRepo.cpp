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


void LocationRepo::storeLocation(Location& location){
    ofstream fout;
    fout.open("Branches.txt", ios::app);
    location.setVerbose(false);
    fout << location;
    fout.close();
    location.setVerbose(true);
}

vector<Location> LocationRepo::getVectorOfLocations(){
     vector<Location> locations;
    ifstream fin;
    fin.open("Branches.txt");
    while(!fin.eof()){
        Location temp;
        temp.setVerbose(false);
        fin >> temp;
        temp.setVerbose(true);
        locations.push_back(temp);
    }
    locations.pop_back();
    return locations;
}

void LocationRepo::storeVectorOfLocations(vector<Location> locations){
    clearLocations();

    ofstream fout;
    fout.open("Branches.txt");
    for(int i = 0; i < locations.size(); i++){
        locations[i].setVerbose(false);
        fout << locations[i];
    }
    fout.close();

}

void LocationRepo::clearLocations(){
    ofstream fout;
    fout.open("Branches.txt");
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




