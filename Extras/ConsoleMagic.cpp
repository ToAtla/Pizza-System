//
//  ConsoleMagic.cpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 03/12/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#include "ConsoleMagic.hpp"

void ConsoleMagic::clearScreen(){
    int n;
    for (n = 0; n < 10; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );
}
