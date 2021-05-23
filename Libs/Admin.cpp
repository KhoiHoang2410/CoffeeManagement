//
//  Admin.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 10/05/2021.
//

#include <tuple>
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
    auto tmp = billRepo.ImportDataFromFile(fileName);
    
    if (!employeeRepo.IsExist(get<0>(tmp))) return false;

    for (int i=0; i<get<1>(tmp).size(); ++i)
        if (!productRepo.IsExist(get<1>(tmp)[i])) return false;
    
    for (int i=0; i<get<0>(tmp).size(); ++i) {
        billRepo.AddBill(get<0>(tmp)[i], get<1>(tmp)[i], get<3>(tmp)[i], get<2>(tmp)[i]);
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

pair<bool, string> Admin::GetEmployee(string name) {
    if (!employeeRepo.IsExist(name)) return make_pair(0, "");
    return make_pair(1, name);
}

tuple<bool, string, double> Admin::GetProduct(string name) {
    if (!productRepo.IsExist(name)) return make_tuple(0, "", 0);
    return make_tuple(1, name, productRepo.GetPrice(name));
}

void Admin::AddBill(Bill bill) {
    materialRepo.UpdateStock(productRepo.GetDetailMaterial(bill.GetDetailProduct()));
    CalculateProductStockAndCapitalCost();
    billRepo.AddBill(bill);
}