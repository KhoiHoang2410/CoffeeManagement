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