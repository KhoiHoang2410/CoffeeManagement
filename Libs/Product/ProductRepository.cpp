//
//  ProductRepository.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 10/05/2021.
//

#include "../../Include/Product/ProductRepository.hpp"
#include "../../Include/ObjectManager.hpp"
#include "../../Include/Helper.hpp"

#include <fstream>

using namespace std;

bool ProductRepository::ClearData() {
    ID.clear();
    productRepo.clear();
    stock.clear();
    capitalCost.clear();
    importedDate.clear();
    
    return 1;
}

bool ProductRepository::UpdateCapitalCostAndStock(vector <pair<double, int> > src) {
    if (src.size() != productRepo.size()) { 
        PutError("ProductRepository::UpdateCapitalCostAndStock", "Invalid input data", 1);
    }

    stock.resize(src.size());
    capitalCost.resize(src.size());

    for (int i=0; i<src.size(); ++i) {
        capitalCost[i] = src[i].first;
        stock[i] = src[i].second;
    }

    return 1;
}

bool ProductRepository::AddProductToCheckList(string productName, vector<string> materialNames, vector<int> numbers) {
    productCheckList.AddProduct(productName, materialNames, numbers);
    return 1;
}

bool ProductRepository::AddProductFromCheckList(string productName, double price) {
    ID.push_back(ObjectManager::GenerateNewID());
    productRepo.push_back(productCheckList.GetProduct(productName));
    sellPrice.push_back(price);
    importedDate.push_back(Date());
    return 1;
}

bool ProductRepository::UpdatePrice(string productName, double newPrice) {
    for (int i=0; i<productRepo.size(); ++i)
        if (productRepo[i].CheckDuplicateByName(productName)) {
            sellPrice[i] = newPrice;
            return 1;
        }
    
    PutError("ProductRepository::UpdatePrice", "Cannot find Product");
    return 0;
}

bool ProductRepository::UpdateRecipe(string productName, vector<string> materialNames, vector<int> numbers) {
    for (int i=0; i<productRepo.size(); ++i)
        if (productRepo[i].CheckDuplicateByName(productName)) {
            productRepo[i].UpdateRecipe(materialNames, numbers);
            return 1;
        }
    
    PutError("ProductRepository::UpdateRecipe", "Cannot find Product");
    return 0;
}

bool ProductRepository::EraseProduct(string productName) {
    for (int i=0; i<productRepo.size(); ++i)
        if (productRepo[i].CheckDuplicateByName(productName)) {
            productRepo.erase(productRepo.begin() + i);
            return 1;
        }
    
    PutError("ProductRepository::EraseProduct", "Cannot find Product");
    return 0;
}

bool ProductRepository::ImportDataFromFileToCheckList(string fileName){
    ifstream cin(fileName);

    if (!cin.is_open()) {
        PutError("ProductRepository::ImportDataFromFileToCheckList", "File not Found");
        return false;
    }

    int n;
    string productName, materialName;
    int m, p;
    vector<string> materialNames;
    vector<int> materialNumbers;
    
    cin >> n;

    OutPut("ProductRepository::ImportDataFromFileToCheckList", fileName + " " 
            + to_string(n));
    
    for(int i=0; i < n; i++){
        getline(cin, productName);
        getline(cin, productName);

        cin>>m;
        for(int j=0; j<m; j++){
            getline(cin, materialName);
            getline(cin, materialName);
            cin>>p;
            materialNames.push_back(materialName);
            materialNumbers.push_back(p);
        }

        AddProductToCheckList(productName,materialNames,materialNumbers);

        materialNames.clear();
        materialNumbers.clear();
    }
    cin.close();

    OutPut("ProductRepository::ImportDataFromFileToCheckList", "Import success");

    return 1;
}

bool ProductRepository::ImportDataFromFile(string fileName){
    ifstream cin(fileName);

    if (!cin.is_open()) {
        PutError("ProductRepository::ImportDataFromFile", "File not Found");
        return 0;
    }

    int n;
    cin >> n;
    string name;
    int price;

    OutPut("ProductRepository::ImportDataFromFile", fileName + " " + to_string(n));

    for(int i=0; i < n; i++){
       getline(cin, name);
       getline(cin, name);
       cin>>price;
       AddProductFromCheckList(name, price);
    }

    cin.close();

    OutPut("ProductRepository::ImportDataFromFile", "Import success");

    return 1;
}

bool ProductRepository::ExportData() const {
    OutPut("ProductRepository::ExportData", "Start export " + to_string(productRepo.size()));

    for (int i=0; i<productRepo.size(); ++i) {
        cout << "ID: " << ID[i] << endl;
        cout << "Product_name: " << productRepo[i].Name() << endl;
        cout << "Capital cost: " << capitalCost[i] << endl;
        cout << "Price: " << sellPrice[i] << endl;
        cout << "Stock: " << stock[i] << endl;
        cout << "Imported_day: " << importedDate[i] << endl;
        cout << endl;
    }

    OutPut("ProductRepository::ExportData", "Export success " + to_string(productRepo.size()));
    
    return 1;
}

bool ProductRepository::ExportCheckListData() const {
    return productCheckList.ExportData();
}

int ProductRepository::Size() {
    return productRepo.size();
}

vector<vector<pair<string, int> > > ProductRepository::GetListMaterialForEachProduct() {
    vector<vector<pair<string, int> > > res;
    for (int i=0; i<productRepo.size(); ++i) {
        res.push_back(productRepo[i].GetDetailMaterial());
    }
    return res;
}

bool ProductRepository::IsExist(string productName) {
    for (int i=0; i<productRepo.size(); ++i) {
        if (productRepo[i].CheckDuplicateByName(productName)) {
            if (stock[i] > 0) return 1;
            return 0;
        }
    }
    return 0;
}

bool ProductRepository::IsExist(vector<string> productNames) {
    for (int i=0; i<productNames.size(); ++i) {
        if (!IsExist(productNames[i])) return 0;
    }
    return 1;
}

double ProductRepository::GetPrice(string productName) {
    for (int i=0; i<productRepo.size(); ++i) {
        if (productRepo[i].CheckDuplicateByName(productName)) return sellPrice[i];
    }
    PutError("ProductRepository::GetPrice", "Product not exist", 1);
}

vector<pair<string, int> > ProductRepository::GetDetailMaterial(string name) {
    for (int i=0; i<productRepo.size(); ++i)
        if (productRepo[i].CheckDuplicateByName(name)) 
            return productRepo[i].GetDetailMaterial();
    PutError("ProductRepository::GetDetailMaterial", "Do not find material", 1);
}

pair<vector<string>, vector<int> > ProductRepository::GetDetailMaterial(pair<vector<string>, vector<int> > src) {
    vector<string> materials;
    vector<int> amounts;
    for (int i=0;i<src.first.size(); ++i) {
        vector<pair<string, int> > tmp = GetDetailMaterial(src.first[i]);
        for (int j=0; j<tmp.size(); ++j) {
            materials.push_back(tmp[j].first);
            amounts.push_back(tmp[j].second);
        }
    }

    for (int i=0; i<materials.size(); ++i) {
        for (int j=i+1; j<materials.size(); ++j) {
            if (materials[i] == materials[j]) {
                amounts[i] += amounts[j];
                materials.erase(materials.begin() + j);
                amounts.erase(amounts.begin() + j);
                
                --j;
            }
        }
    }

    return make_pair(materials, amounts);
}