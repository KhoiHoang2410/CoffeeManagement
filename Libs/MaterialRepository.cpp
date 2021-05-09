//
//  MaterialRepository.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include <fstream>

#include "../Include/MaterialRepository.hpp"
#include "../Include/Materials.hpp"

bool MaterialRepository::ClearData() {
    IDs.clear();
    materialRepo.clear();
    stocks.clear();
    importedDates.clear();
    expiredDates.clear();
    
    return 1;
}

bool MaterialRepository::RestructureData() {
    for (int i=0; i<materialRepo.size(); ++i) {
        if (stocks[i] == 0) {
            IDs.erase(IDs.begin() + i);
            materialRepo.erase(materialRepo.begin() + i);
            stocks.erase(stocks.begin() + i);
            importedDates.erase(importedDates.begin() + i);
            expiredDates.erase(expiredDates.begin() + i);
            
            --i;
        }
    }
    return 1;
}

bool MaterialRepository::Add(string materialName, double price, int number) {
    materialRepo.push_back(Materials::Get(materialName));
    importedPrices.push_back(price);
    stocks.push_back(number);
    importedDates.push_back(Date());
    expiredDates.push_back(Date());
    return 1;
}

bool MaterialRepository::ReadAllData(string fileName) const {
    ofstream cout(fileName);
    for (int i=0; i<materialRepo.size(); ++i) {
        cout << "Name: " << materialRepo[i].Name() << endl;
        cout << "Price: " << importedPrices[i] << endl;
        cout << "Stocks: " << stocks[i] << endl;
        cout << "Imported date: " << importedDates[i] << endl;
        cout << "Expired date: " << expiredDates[i] << endl;
    }
    return 1;
}

bool MaterialRepository::Update(string materialName, int noTaken) {
    for (int i=0; i<materialRepo.size(); ++i) {
        if (noTaken == 0) break;
        
        if (materialRepo[i].CheckDuplicate(materialName)) {
            int tmp = min(stocks[i], noTaken);
            stocks[i] -= tmp;
            noTaken -= tmp;
        }
    }
    
    if (noTaken != 0) {
        cout << "MaterialRepository::Update\n";
        cout << "Error: do not have enough material.\n";
        exit(0);
    }
    
    RestructureData();
    return 1;
}


