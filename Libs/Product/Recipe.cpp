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

void Recipe::Display() const {
    for (int i=0; i<materials.size(); ++i) {
        cout << materials[i] << " : " << noMaterial[i] << endl;
    }
}

vector<pair<string, int> > Recipe::GetDetailMaterial() {
    vector<pair<string, int> > res;
    for (int i=0; i<materials.size(); ++i) {
        res.push_back(make_pair(materials[i], noMaterial[i]));
    }
    return res;
}