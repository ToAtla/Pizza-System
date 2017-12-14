//
//  OfferRepo.cpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/14/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "OfferRepo.hpp"


void OfferRepo::writeOfferStatus(bool status){
    
    ofstream fout;
    fout.open("offers.dat", ios::binary);
    fout.write((char*)(&status), sizeof(bool));
    fout.close();
}

bool OfferRepo::readOfferStatus(){
    
    ifstream fin;
    bool status;
    fin.open("offers.dat", ios::binary);
    fin.read((char*)(&status), sizeof(bool));
    fin.close();
    return status;
}
