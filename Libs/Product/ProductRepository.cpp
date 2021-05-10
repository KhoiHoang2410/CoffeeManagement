//
//  ProductRepository.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 10/05/2021.
//

#include <fstream>

#include "../../Include/Product/ProductRepository.hpp"
#include "../../Include/ObjectManager.hpp"
#include "../../Include/Helper.hpp"
#include "Products.hpp"

using namespace std;

bool ProductRepository::ClearData() {
    IDs.clear();
    productRepo.clear();
    stocks.clear();
    importedPrices.clear();
    importedDates.clear();
    
    return 1;
}

bool ProductRepository::CalculateStock() {
    return 0;
}

bool ProductRepository::AddProductToCheckList(string productName, vector<string> materialNames, vector<int> numbers) {
    Products::AddProduct(productName, materialNames, numbers);
    return 1;
}

bool ProductRepository::AddProductInCheckList(string productName, double price) {
    IDs.push_back(ObjectManager::GenerateNewID());
    productRepo.push_back(Products::GetProduct(productName));
    importedPrices.push_back(price);
    importedDates.push_back(Date());
    CalculateStock();
    return 1;
}

bool ProductRepository::ReadAllData(string fileName) const {
    ofstream cout (fileName);
    
    if (!cout.is_open()) {
        putError("ProductRepository::ReadAllData", "Cannot open file", 1);
    }
    
    for (int i=0; i<productRepo.size(); ++i) {
        cout << "Product name: " << productRepo[i].Name() << endl;
        cout << "Price: " << importedPrices[i] << endl;
        cout << "Stock: " << stocks[i] << endl;
        cout << "Imported day" << importedDates[i] << endl;
    }
    cout.close();
    return 1;
}

bool ProductRepository::UpdatePrice(string productName, double newPrice) {
    for (int i=0; i<productRepo.size(); ++i)
        if (productRepo[i].CheckDuplicate(productName)) {
            importedPrices[i] = newPrice;
            return 1;
        }
    
    putError("ProductRepository::UpdatePrice", "Cannot find Product");
    return 0;
}

bool ProductRepository::UpdateRecipe(string productName, vector<string> materialNames, vector<int> numbers) {
    for (int i=0; i<productRepo.size(); ++i)
        if (productRepo[i].CheckDuplicate(productName)) {
            productRepo[i].UpdateRecipe(materialNames, numbers);
            return 1;
        }
    
    putError("ProductRepository::UpdateRecipe", "Cannot find Product");
    return 0;
}

bool ProductRepository::EraseProduct(string productName) {
    for (int i=0; i<productRepo.size(); ++i)
        if (productRepo[i].CheckDuplicate(productName)) {
            productRepo.erase(productRepo.begin() + i);
            return 1;
        }
    
    putError("ProductRepository::EraseProduct", "Cannot find Product");
    return 0;
}


