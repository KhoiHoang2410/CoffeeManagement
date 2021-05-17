//
//  Products.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 10/05/2021.
//

#include "../../Include/Product/ProductCheckList.hpp"
#include "../../Include/Helper.hpp"

#include <iostream>

bool ProductCheckList::AddProduct(string productName, vector<string> materialNames, vector<int> numbers) {
    if (GetID(productName) != -1) {
        PutError("Products::AddProduct", "Add existing product to check list", 1);
    }
    
    products.push_back(Product(productName));
    products.back().AddRecipe(materialNames, numbers);
    return 1;
}

int ProductCheckList::GetID(string productName) {
    for (int i=0; i<products.size(); ++i)
        if (products[i].CheckDuplicate(productName))
            return i;
    return -1;
}

Product ProductCheckList::GetProduct(string productName) {
    int id = GetID(productName);
    if (id == -1) {
        PutError("Products::GetProduct", "ID not found: " + productName, 1);
    }
    return products[id];
}

Product ProductCheckList::GetProduct(int ID) {
    return products[ID];
}

bool ProductCheckList::UpdateProduct(string productName, vector<string> materialNames, vector<int> numbers) {
    int id = GetID(productName);
    if (id == -1) {
        PutError("Products::UpdateProduct", "ID not found");
        return 0;
    }
    
    products[id].AddRecipe(materialNames, numbers);
    return 1;
}

bool ProductCheckList::EraseProduct(string productName) {
    int id = GetID(productName);
    if (id == -1) {
        PutError("Products::EraseProduct", "ID not found");
        return 0;
    }
    
    products.erase(products.begin() + id);
    return 1;
}

bool ProductCheckList::ExportData() const {
    OutPut("ProductCheckList::ExportData", "Start Export " + to_string(products.size()));

    for (int i=0; i<products.size(); ++i) {
        cout << "ID: " << products[i].GetID() << endl;
        cout << "Name: " << products[i].Name() << endl;
        cout << "Recipe:" << endl;
        products[i].DisplayRecipe();
        cout << endl;
    }

    OutPut("ProductCheckList::ExportData", "Export success");

    return 1;
}