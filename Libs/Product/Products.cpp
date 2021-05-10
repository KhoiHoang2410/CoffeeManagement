//
//  Products.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 10/05/2021.
//

#include "../../Include/Product/Products.hpp"

#include <iostream>

bool Products::AddProduct(string productName, vector<string> materialNames, vector<int> numbers) {
    products.push_back(Product(productName));
    products.back().AddRecipe(materialNames, numbers);
    return 1;
}

int Products::GetID(string productName) {
    for (int i=0; i<products.size(); ++i)
        if (products[i].CheckDuplicate(productName))
            return i;
    return -1;
}

Product Products::GetProduct(string productName) {
    int id = GetID(productName);
    if (id == -1) {
        cout << "Products::GetProduct\n";
        cout << "ID not found.\n";
        exit(1);
    }
    return products[id];
}

Product Products::GetProduct(int ID) {
    return products[ID];
}

bool Products::UpdateProduct(string productName, vector<string> materialNames, vector<int> numbers) {
    int id = GetID(productName);
    if (id == -1) {
        cout << "Products::UpdateProduct\n";
        cout << "ID not found.\n";
        return 0;
    }
    
    products[id].AddRecipe(materialNames, numbers);
    return 1;
}

bool Products::EraseProduct(string productName) {
    int id = GetID(productName);
    if (id == -1) {
        cout << "Products::EraseProduct\n";
        cout << "ID not found.\n";
        return 0;
    }
    
    products.erase(products.begin() + id);
    return 1;
}
