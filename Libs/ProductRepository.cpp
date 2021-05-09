//
//  ProductRepository.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 10/05/2021.
//

#include <fstream>

#include "../Include/ProductRepository.hpp"
#include "../Include/Products.hpp"
#include "../Include/ObjectManager.hpp"

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

bool ProductRepository::AddProduct(string productName, double price) {
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
        cout << "ProductRepository::ReadAllData\n";
        cout << "Can not open file.\n";
        exit(1);
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
    
    cout << "ProductRepository::UpdatePrice\n";
    cout << "Can not find Product.\n";
    return 0;
}

bool ProductRepository::UpdateRecipe(string productName, vector<string> materialNames, vector<int> numbers) {
    for (int i=0; i<productRepo.size(); ++i)
        if (productRepo[i].CheckDuplicate(productName)) {
            productRepo[i].UpdateRecipe(materialNames, numbers);
            return 1;
        }
    
    cout << "ProductRepository::UpdateRecipe\n";
    cout << "Can not find Product.\n";
    return 0;
}

bool ProductRepository::EraseProduct(string productName) {
    for (int i=0; i<productRepo.size(); ++i)
        if (productRepo[i].CheckDuplicate(productName)) {
            productRepo.erase(productRepo.begin() + i);
            return 1;
        }
    
    cout << "ProductRepository::EraseProduct\n";
    cout << "Can not find Product.\n";
    return 0;
}


