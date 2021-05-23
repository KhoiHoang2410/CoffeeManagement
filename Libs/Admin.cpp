//
//  Admin.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 10/05/2021.
//

#include "../Include/Admin.hpp"

bool Admin::ImportMaterialToCheckList(string fileName) {
    return materialRepo.ImportDataFromFileToCheckList(fileName);
}

bool Admin::ImportProductToCheckList(string fileName) {
    return productRepo.ImportDataFromFileToCheckList(fileName);
}

bool Admin::ImportNewMaterial(string fileName) {
    return materialRepo.ImportDataFromFile(fileName);
}

bool Admin::ImportNewProduct(string fileName) {
    return productRepo.ImportDataFromFile(fileName);
}

bool Admin::ImportBill(string fileName) {
    pair<pair<vector<string>, vector<vector<string> > >, pair<vector<vector<int> >, vector<vector<double> > > > 
            tmp = billRepo.ImportDataFromFile(fileName);
    
    if (!employeeRepo.IsExist(tmp.first.first)) return false;

    for (int i=0; i<tmp.first.second.size(); ++i)
        if (!productRepo.IsExist(tmp.first.second[i])) return false;
    
    for (int i=0; i<tmp.first.first.size(); ++i) {
        billRepo.AddBill(tmp.first.first[i], tmp.first.second[i], tmp.second.second[i], tmp.second.first[i]);
    }
    return 1;
}

bool Admin::ExportCheckListMaterial() const {
    return materialRepo.ExportCheckListData();
}

bool Admin::ExportMaterialRepository() const {
    return materialRepo.ExportData();
}

bool Admin::ExportCheckListProduct() const {
    return productRepo.ExportCheckListData();
}

bool Admin::ExportProductRepository() const {
    return productRepo.ExportData();
}

bool Admin::ExportBillRepository() const {
    return billRepo.ExportAllData();
}

bool Admin::CalculateProductStockAndCapitalCost() {
    vector<vector<pair<string, int> > > list = productRepo.GetListMaterialForEachProduct(); // vector<vector<Material, int> >
    vector<pair<double, int> > res = materialRepo.GetCapitalCostAndStock(list); // vector <double, int>
    return productRepo.UpdateCapitalCostAndStock(res);
}

bool Admin::ImportEmployee(string fileName) {
    return employeeRepo.ImportDataFromFile(fileName);
}

bool Admin::ExportEmployeeRepository() const {
    return employeeRepo.ExportEmployeeData();
}