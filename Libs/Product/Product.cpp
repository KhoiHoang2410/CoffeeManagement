//
//  Products.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "../../Include/Product/Product.hpp"

Product::Product() {
    recipe = Recipe(ID, Name());
}

Product::Product(string productName) {
    recipe = Recipe(ID, productName);
}

void Product::AddRecipe(vector<string> materialNames, vector<int> numbers) {
    recipe.AddMaterial(materialNames, numbers);
}

void Product::UpdateRecipe(vector<string> materialNames, vector<int> numbers) {
    recipe.AddMaterial(materialNames, numbers);
}


