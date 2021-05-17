//
//  Admin.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 10/05/2021.
//

#include "../Include/Admin.hpp"

bool Admin::ImportMaterialsToCheckList(string fileName){
    return materialRepo.ImportDataFromFileToCheckList(fileName);
}

bool Admin::ImportProductsToCheckList(string fileName){
    return productRepo.ImportDataFromFileToCheckList(fileName);
}

bool Admin::ImportNewMaterial(string fileName){
    return materialRepo.ImportDataFromFile(fileName);
}

bool Admin::ImportNewProduct(string fileName){
    return productRepo.ImportDataFromFile(fileName);
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

bool Admin::CalculateProductStockCanBeSolve() {
    productRepo.UpdateStock(vector<int>(productRepo.Size()));
}