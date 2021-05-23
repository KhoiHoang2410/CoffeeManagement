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
#include "Bill/BillRepository.hpp"

class Admin {
private:
    MaterialRepository materialRepo;
    ProductRepository productRepo;
    EmployeeRepository employeeRepo;
    BillRepository billRepo;
public:
    bool ImportMaterialToCheckList(string fileName);
    bool ImportProductToCheckList(string fileName);
    bool ImportNewMaterial(string fileName);
    bool ImportNewProduct(string fileName);
    bool ImportEmployee(string fileName);
    bool ImportBill(string fileName);

    bool ExportCheckListMaterial() const;
    bool ExportMaterialRepository() const;
    bool ExportCheckListProduct() const;
    bool ExportProductRepository() const;
    bool ExportEmployeeRepository() const;
    bool ExportBillRepository() const;

    pair<bool, string> GetEmployee(string name);
    tuple<bool, string, double> GetProduct(string name);
    void AddBill(Bill bill);

    bool CalculateProductStockAndCapitalCost();
};

#endif /* Admin_hpp */
