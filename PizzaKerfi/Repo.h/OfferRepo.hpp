//
//  OfferRepo.hpp
//  PizzaKerfi
//
//  Created by Nokkvi Karlsson on 12/14/17.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef OfferRepo_hpp
#define OfferRepo_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

class OfferRepo{
    
    public:
        void writeOfferStatus(bool status);
        bool readOfferStatus();
    private:
};

#endif /* OfferRepo_hpp */
