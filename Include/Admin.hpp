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
#include "Employee/EmployeeRepository.hpp"

class Admin {
private:
    MaterialRepository materialRepo;
    ProductRepository productRepo;
    EmployeeRepository employeeRepo;
public:
    bool ImportMaterialToCheckList(string fileName);
    bool ImportProductToCheckList(string fileName);
    bool ImportNewMaterial(string fileName);
    bool ImportNewProduct(string fileName);

    bool ExportCheckListMaterial() const;
    bool ExportMaterialRepository() const;
    bool ExportCheckListProduct() const;
    bool ExportProductRepository() const;
    
    bool CalculateProductStockAndCapitalCost();
};

#endif /* Admin_hpp */
