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
#include <string>

#include "../Include/Recipe.hpp"

using namespace std;

class Product {
private:
    int ID;
    string name;
    Recipe recipe;
public:
    Product(string name);
    
    void addMaterial(vector<string> materialNames, vector<string> numbers);
};

#endif /* Products_hpp */

