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
    IDs.clear();
    productRepo.clear();
    stocks.clear();
    importedPrices.clear();
    importedDates.clear();
    
    return 1;
}

bool ProductRepository::UpdateStock(vector <int> stocks) {
    this->stocks = stocks;
    return 1;
}

bool ProductRepository::AddProductToCheckList(string productName, vector<string> materialNames, vector<int> numbers) {
    productCheckList.AddProduct(productName, materialNames, numbers);
    return 1;
}

bool ProductRepository::AddProductInCheckList(string productName, double price) {
    IDs.push_back(ObjectManager::GenerateNewID());
    productRepo.push_back(productCheckList.GetProduct(productName));
    importedPrices.push_back(price);
    importedDates.push_back(Date());
    return 1;
}

bool ProductRepository::ExportData() const {
    for (int i=0; i<productRepo.size(); ++i) {
        cout << "Product_name: " << productRepo[i].Name() << endl;
        cout << "Price: " << importedPrices[i] << endl;
        cout << "Stock: " << stocks[i] << endl;
        cout << "Imported_day" << importedDates[i] << endl;
    }
    
    return 1;
}

bool ProductRepository::UpdatePrice(string productName, double newPrice) {
    for (int i=0; i<productRepo.size(); ++i)
        if (productRepo[i].CheckDuplicate(productName)) {
            importedPrices[i] = newPrice;
            return 1;
        }
    
    PutError("ProductRepository::UpdatePrice", "Cannot find Product");
    return 0;
}

bool ProductRepository::UpdateRecipe(string productName, vector<string> materialNames, vector<int> numbers) {
    for (int i=0; i<productRepo.size(); ++i)
        if (productRepo[i].CheckDuplicate(productName)) {
            productRepo[i].UpdateRecipe(materialNames, numbers);
            return 1;
        }
    
    PutError("ProductRepository::UpdateRecipe", "Cannot find Product");
    return 0;
}

bool ProductRepository::EraseProduct(string productName) {
    for (int i=0; i<productRepo.size(); ++i)
        if (productRepo[i].CheckDuplicate(productName)) {
            productRepo.erase(productRepo.begin() + i);
            return 1;
        }
    
    PutError("ProductRepository::EraseProduct", "Cannot find Product");
    return 0;
}

bool ProductRepository::ImportDataFromFileToCheckList(string fileName){
    ifstream cin(fileName);

    if (!cin.is_open()) {
        PutError("ProductRepository::ImportDataFromFileToCheckList", "File not Found", 1);
    }

    int n;
    cin >> n;
    string productName, materialName;
    int m, p;
    vector<string> materialNames;
    vector<int> materialNumbers;
    for(int i; i < n; i++){
        getline(cin, productName);
        cin>>m;
        for(int i=0; i<m; i++){
            getline(cin, materialName);
            cin>>p;
            materialNames.push_back(materialName);
            materialNumbers.push_back(p);
        }
        AddProductToCheckList(productName,materialNames,materialNumbers);
    }
    cin.close();

    return 1;
}

bool ProductRepository::ImportDataFromFile(string fileName){
    ifstream cin(fileName);

    if (!cin.is_open()) {
        PutError("ProductRepository::ImportDataFromFile", "File not Found", 1);
    }

    int n;
    cin >> n;
    string name;
    int price;
    for(int i; i < n; i++){
       getline(cin, name);
       cin>>price;
       AddProductInCheckList(name, price);
    }
    cin.close();

    return 1;
}

