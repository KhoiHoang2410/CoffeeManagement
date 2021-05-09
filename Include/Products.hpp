//
//  Products.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef Products_hpp
#define Products_hpp

#include "../Include/Item.hpp"
#include "../Include/Recipe.hpp"

#include <vector>

using namespace std;

class Products {
private:
    vector <Item> products;
    vector <Recipe> recipts;
};

#endif /* Products_hpp */

