//
//  Admin.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 10/05/2021.
//

#ifndef Admin_hpp
#define Admin_hpp

#include "Material/MaterialRepository.hpp"
#include "Product/ProductRepository.hpp"

class Admin {
private:
    MaterialRepository materialRepo;
    ProductRepository productRepo;
public:
    bool AddMaterialsToCheckList(string fileName);
    bool AddProductsToCheckList(string fileName);
    
    bool AddNewMaterial(string fileName);
    bool AddNewProduct(string fileName);
    
    bool CalculateProductStockCanBeSolve();
};

#endif /* Admin_hpp */
