//
//  Recipt.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "../../Include/Material/MaterialCheckList.hpp"
#include "../../Include/Product/ProductCheckList.hpp"
#include "../../Include/Product/Recipe.hpp"
#include "../../Include/Helper.hpp"

void Recipe::ClearData() {
    this->materials.clear();
    this->noMaterial.clear();
}

bool Recipe::AddMaterial(vector<string> materialNames, vector<int> numbers) {
    ClearData();
    this->materials = materialNames;
    this->noMaterial = numbers;
    return 1;
}
