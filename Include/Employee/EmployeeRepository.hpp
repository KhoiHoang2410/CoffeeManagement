//
//  EmployeeRepository.hpp
//  CoffeeManagement
//
//  Created by Khoi Hoang on 16/05/2021.
//

#ifndef EmployeeRepository_hpp
#define EmployeeRepository_hpp

#include "Employee.hpp"

#include <vector>

class EmployeeRepository {
private:
    vector <Employee> employeeRepo;
public:
    EmployeeRepository() = default;

    void AddEmployee(string name, string position, int salary);
    bool ExportEmployeeData() const;
    void EraseEmployee(string name);
    Employee GetEmployee(string name);
    bool ImportDataFromFile(string fileName);
    void ExportData();

    int getID(string name);
};

#endif /* EmployeeRepository_hpp */
