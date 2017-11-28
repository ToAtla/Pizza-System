//
//  Order.hpp
//  PizzaKerfi
//
//  Created by Þórður Atlason on 28/11/2017.
//  Copyright © 2017 Þórður Atlason. All rights reserved.
//

#ifndef Order_hpp
#define Order_hpp

#include <stdio.h>
#include <string>
#include "Pizza.hpp"

using namespace std;

class Order {
public:
    Order();
private:
    //Þetta er dýnamískt því fjöldi pizza í einni pöntun er breytilegur
    Pizza* pizzaList;
    int linesInOrder;
};

#endif /* Order_hpp */
