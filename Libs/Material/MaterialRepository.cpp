//
//  MaterialRepository.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "../../Include/ObjectManager.hpp"
#include "../../Include/Material/MaterialRepository.hpp"
#include "../../Include/Material/Materials.hpp"
#include "../../Include/Helper.hpp"

#include <fstream>

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
            importedPrices.erase(importedPrices.begin() + i);
            importedDates.erase(importedDates.begin() + i);
            expiredDates.erase(expiredDates.begin() + i);
            
            --i;
        }
    }
    return 1;
}


bool MaterialRepository::AddMaterialToCheckList(string materialName) {
    Materials::AddMaterial(materialName);
    return 1;
}


bool MaterialRepository::AddMaterialInCheckList(string materialName, double price, int number) {
    IDs.push_back(ObjectManager::GenerateNewID());
    materialRepo.push_back(Materials::GetMaterial(materialName));
    stocks.push_back(number);
    importedPrices.push_back(price);
    importedDates.push_back(Date());
    expiredDates.push_back(Date());
    return 1;
}

bool MaterialRepository::ReadAllData(string fileName) const {
    ofstream cout(fileName);
    
    if (!cout.is_open()) {
        putError("MaterialRepository::ReadAllData\n", "Cannot open file", 1);
    }
    
    for (int i=0; i<materialRepo.size(); ++i) {
        cout << "Name: " << materialRepo[i].Name() << endl;
        cout << "Price: " << importedPrices[i] << endl;
        cout << "Stocks: " << stocks[i] << endl;
        cout << "Imported date: " << importedDates[i] << endl;
        cout << "Expired date: " << expiredDates[i] << endl;
    }
    cout.close();
    return 1;
}

bool MaterialRepository::UpdateStock(string materialName, int noTaken) {
    for (int i=0; i<materialRepo.size(); ++i) {
        if (noTaken == 0) break;
        
        if (materialRepo[i].CheckDuplicate(materialName)) {
            int tmp = min(stocks[i], noTaken);
            stocks[i] -= tmp;
            noTaken -= tmp;
        }
    }
    
    if (noTaken != 0) {
        putError("MaterialRepository::Update", "Error: do not have enough material", 1);
    }
    
    RestructureData();
    return 1;
}


