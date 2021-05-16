//
//  Admin.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 10/05/2021.
//

#include "../Include/Admin.hpp"

bool Admin::ImportMaterialsToCheckList(string fileName){
    materialRepo.ImportDataFromFileToCheckList(fileName);
}

bool Admin::ImportProductsToCheckList(string fileName){
    productRepo.ImportDataFromFileToCheckList(fileName);
}

bool Admin::ImportNewMaterial(string fileName){
    materialRepo.ImportDataFromFile(fileName);
}

bool Admin::ImportNewProduct(string fileName){
    productRepo.ImportDataFromFile(fileName);
}