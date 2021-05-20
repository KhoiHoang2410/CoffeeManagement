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
    ID.clear();
    materialRepo.clear();
    stock.clear();
    importedDate.clear();
    expiredDate.clear();
    
    return 1;
}

bool MaterialRepository::RestructureData() {
    for (int i=0; i<materialRepo.size(); ++i) {
        if (stock[i] == 0) {
            ID.erase(ID.begin() + i);
            materialRepo.erase(materialRepo.begin() + i);
            stock.erase(stock.begin() + i);
            importedPrice.erase(importedPrice.begin() + i);
            importedDate.erase(importedDate.begin() + i);
            expiredDate.erase(expiredDate.begin() + i);
            
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
    ID.push_back(ObjectManager::GenerateNewID());
    materialRepo.push_back(materialCheckList.GetMaterial(materialName));
    stock.push_back(number);
    importedPrice.push_back(price);
    importedDate.push_back(Date());
    expiredDate.push_back(Date());
    return 1;
}

bool MaterialRepository::UpdateStock(string materialName, int noTaken) {
    for (int i=0; i<materialRepo.size(); ++i) {
        if (noTaken == 0) break;
        
        if (materialRepo[i].CheckDuplicate(materialName)) {
            int tmp = min(stock[i], noTaken);
            stock[i] -= tmp;
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
        PutError("MaterialRepository::ImportDataFromFile", "File not Found");
        return false;
    }

    int n;
    cin >> n;
    string name;
    int price, stock;


    OutPut( "MaterialRepository::ImportDataFromFile", fileName + " " 
            + to_string(n));
    
    for (int i=0; i<n; ++i) {
        getline(cin, name);
        getline(cin, name);
        cin >> price >> stock;

        AddMaterialInCheckList(name, price, stock);
    }

    cin.close();

    OutPut( "MaterialRepository::ImportDataFromFile", "Import success");

    return 1;
}

bool MaterialRepository::ImportDataFromFileToCheckList(string fileName) {
    ifstream cin(fileName);

    if (!cin.is_open()) {
        PutError("MaterialRepository::ImportDataFromFileToCheckList", "File not Found");
        return false;
    }

    int n;
    cin >> n;
    string name;
    getline(cin, name);

    OutPut( "MaterialRepository::ImportDataFromFileToCheckList", fileName + " "
                + to_string(n));

    for (int i=0; i<n; ++i) {
        getline(cin, name);
        AddMaterialToCheckList(name);
    }

    cin.close();

    OutPut( "MaterialRepository::ImportDataFromFileToCheckList", "Import success");

    return 1;
}

bool MaterialRepository::ExportData() const {
    OutPut( "MaterialRepository::ExportData", "Number of material: " + to_string(materialRepo.size()));
    
    for (int i=0; i<materialRepo.size(); ++i) {
        cout << "ID: " << ID[i] << endl;
        cout << "Name: " << materialRepo[i].Name() << endl;
        cout << "Price: " << importedPrice[i] << endl;
        cout << "Stocks: " << stock[i] << endl;
        cout << "Imported_date: " << importedDate[i] << endl;
        cout << "Expired_date: " << expiredDate[i] << endl;

        cout << endl;
    }

    OutPut( "MaterialRepository::ExportData", "Export success");

    return 1;
}

bool MaterialRepository::ExportCheckListData() const {
    return materialCheckList.ExportData();
}


vector<int> MaterialRepository::GetIDsForThisMaterial(string name) {
    vector<int> res;
    for (int i=0; i<materialRepo.size(); ++i)
        if (materialRepo[i].CheckDuplicate(name)) {
            res.push_back(i);
        }
    return res;
}

int MaterialRepository::CalcPriceForAllMaterial(string name) {
    vector<int> IDs = GetIDsForThisMaterial(name);
    if (IDs.size() == 0) {
        PutError("MaterialRepository::CalcPriceForAllMaterial", "Material not existed");
        return -1;
    }

    int res = 0;

    for (int i=0; i<IDs.size(); ++i) {
        res += stock[IDs[i]] * importedPrice[IDs[i]];
    }
    return res;
}

int MaterialRepository::GetStock(string name) {
    vector<int> IDs = GetIDsForThisMaterial(name);
    if (IDs.size() == 0) {
        PutError("MaterialRepository::GetStock", "Material not imported: " + name);
        return 0;
    }
    
    int res = 0;

    for (int i=0; i<IDs.size(); ++i)
        res += stock[IDs[i]];
    return res;
}

pair<double, int> MaterialRepository::GetCapitalCostAndStock(vector<pair<string, int> > src) {
    double avgPrice = 0;
    int stock = INT_MAX;
 
    for (int i=0; i<src.size(); ++i) {
        if (!materialCheckList.GetID(src[i].first)) {
            PutError("MaterialRepository::GetCapitalCostAndStock", "Material: " + src[i].first + " not exist", 1);
        }
        
        if (GetStock(src[i].first) < src[i].second) 
            return make_pair(-1, 0);

        avgPrice += CalcPriceForAllMaterial(src[i].first) / double(GetStock(src[i].first)) * src[i].second;
        stock = min(stock, GetStock(src[i].first) / src[i].second);
    }

    return make_pair(avgPrice, stock);
}

vector<pair<double, int> > MaterialRepository::GetCapitalCostAndStock(vector<vector<pair<string, int> > > src) {
    vector<pair<double, int> > res;
    for (int i=0; i<src.size(); ++i) {
        res.push_back(GetCapitalCostAndStock(src[i]));
    }
    return res;
}