//
//  Product.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef Product_hpp
#define Product_hpp

#include "../Include/Item.hpp"
#include "../Include/Recipe.hpp"

#include <vector>
#include <string>

using namespace std;

class Product : public Item {
private:
    Recipe recipe;
public:
    Product(string name);
    
    void addMaterial(vector<string> materialNames, vector<string> numbers);
};

#endif /* Product_hpp */

