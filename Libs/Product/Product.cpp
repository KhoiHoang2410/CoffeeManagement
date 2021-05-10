//
//  Products.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "../../Include/Product/Product.hpp"

void Product::AddRecipe(vector<string> materialNames, vector<int> numbers) {
    recipe.AddMaterial(materialNames, numbers);
}

void Product::UpdateRecipe(vector<string> materialNames, vector<int> numbers) {
    recipe.AddMaterial(materialNames, numbers);
}


