//
//  Recipt.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "../../Include/Material/Materials.hpp"
#include "../../Include/Product/Products.hpp"
#include "../../Include/Product/Recipe.hpp"
#include "../../Include/Helper.hpp"

Recipe::Recipe() {
    ID = -1;
}

Recipe::Recipe(int ID, string productName) { // check ID is in Products
    if (Products::GetID(productName) != ID) {
        putError("Recipe::Recipe", "Product name and Product ID not match", 1);
    }
    this->ID = ID;
}

void Recipe::ClearData() {
    this->materialID.clear();
    this->noMaterial.clear();
}

bool Recipe::AddMaterial(vector<string> materialNames, vector<int> numbers) {
    ClearData();
    for (int i=0; i<materialNames.size(); ++i) {
        materialID.push_back(Materials::GetID(materialNames[i]));
        noMaterial.push_back(numbers[i]);
    }
    return 1;
}
