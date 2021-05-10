//
//  Product.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef Product_hpp
#define Product_hpp

#include "../Item.hpp"
#include "Recipe.hpp"

#include <vector>
#include <string>

using namespace std;

class Product : public Item {
private:
    Recipe recipe;
public:
    Product();
    Product(string productName);
    
    void AddRecipe(vector<string> materialNames, vector<int> numbers);
    void UpdateRecipe(vector<string> materialNames, vector<int> numbers);
};

#endif /* Product_hpp */

