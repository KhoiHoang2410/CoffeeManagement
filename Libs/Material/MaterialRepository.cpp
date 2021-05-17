//
//  MaterialRepository.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "../../Include/ObjectManager.hpp"
#include "../../Include/Material/MaterialRepository.hpp"
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
    materialCheckList.AddMaterial(materialName);
    return 1;
}


bool MaterialRepository::AddMaterialInCheckList(string materialName, double price, int number) {
    IDs.push_back(ObjectManager::GenerateNewID());
    materialRepo.push_back(materialCheckList.GetMaterial(materialName));
    stocks.push_back(number);
    importedPrices.push_back(price);
    importedDates.push_back(Date());
    expiredDates.push_back(Date());
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
        PutError("MaterialRepository::Update", "Error: do not have enough material", 1);
    }
    
    RestructureData();
    return 1;
}

bool MaterialRepository::ImportDataFromFile(string fileName) {
    ifstream cin(fileName);

    if (!cin.is_open()) {
        PutError("MaterialRepository::ImportDataFromFile", "Find not Found", 1);
    }

    int n;
    cin >> n;
    string name;
    int price, stock;
    
    for (int i=0; i<n; ++i) {
        cin >> name;
        cin >> price >> stock;

        AddMaterialInCheckList(name, price, stock);
    }

    cin.close();

    return 1;
}

bool MaterialRepository::ImportDataFromFileToCheckList(string fileName) {
    ifstream cin(fileName);

    if (!cin.is_open()) {
        cout << fileName << endl;
        PutError("MaterialRepository::ImportDataFromFileToCheckList", "File not Found", 1);
    }

    int n;
    cin >> n;
    string name;
    getline(cin, name);

    OutPut(cout, "MaterialRepository::ImportDataFromFileToCheckList", 
                "Start import with " + to_string(n) + " elements");
    
    for (int i=0; i<n; ++i) {
        getline(cin, name);
        AddMaterialToCheckList(name);
    }

    cin.close();

    OutPut(cout, "MaterialRepository::ImportDataFromFileToCheckList", "Import success");

    return 1;
}

bool MaterialRepository::ExportData() const {
    OutPut(cout, "MaterialRepository::ExportData", "Number of material: " + to_string(materialRepo.size()));
    
    for (int i=0; i<materialRepo.size(); ++i) {
        OutPut(cout, "Name", materialRepo[i].Name());
        OutPut(cout, "Price", importedPrices[i]);
        OutPut(cout, "Stocks", stocks[i]);
        OutPut(cout, "Imported_date", importedDates[i]);
        OutPut(cout, "Expired_date", expiredDates[i]);
    }

    OutPut(cout, "MaterialRepository::ExportData", "Import success");

    return 1;
}

bool MaterialRepository::ExportCheckListData() const {
    return materialCheckList.ExportData();
}