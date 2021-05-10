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
    bool ImportMaterialsToCheckList(string fileName);
    bool ImportProductsToCheckList(string fileName);
    
    bool ImportNewMaterial(string fileName);
    bool ImportNewProduct(string fileName);
    
    bool CalculateProductStockCanBeSolve();
};

#endif /* Admin_hpp */
