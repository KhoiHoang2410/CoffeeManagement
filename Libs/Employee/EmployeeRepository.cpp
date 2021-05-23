//
//  EmployeeRepository.cpp
//  CoffeeManagement
//
//  Created by Khoi Hoang on 17/05/2021.
//

#include "../../Include/Employee/EmployeeRepository.hpp"
#include "../../Include/Helper.hpp"

void EmployeeRepository::AddEmployee(string name, string position, int salary) {
    employeeRepo.push_back(Employee(name, position, salary));
}

bool EmployeeRepository::ExportEmployeeData() const {
    OutPut("EmployeeRepository::ExportEmployee", "Start export " + to_string(employeeRepo.size()));
    
    for (int i=0; i<employeeRepo.size(); ++i) {
        employeeRepo[i].ExportData();
        cout << endl;
    }

    OutPut("EmployeeRepository::ExportEmployee", "Export success");

    return 1;
}

bool EmployeeRepository::ImportDataFromFile(string fileName) {
    ifstream cin(fileName);

    if (!cin.is_open()) {
        PutError("EmployeeRepository::ImportDataFromFile", "File not Found", 1);
    }

    int n, salary;
    cin >> n;
    string name, position;

    OutPut("EmployeeRepository::ImportDataFromFile", fileName + " " + to_string(n));

    for(int i=0; i < n; i++){
       getline(cin, name);
       getline(cin, name);
       getline(cin, position);
       cin >> salary;
       AddEmployee(name, position, salary);
    }

    cin.close();

    OutPut("EmployeeRepository::ImportDataFromFile", "Import success");

    return 1;
}

void EmployeeRepository::EraseEmployee(string name) {
    int ID = getID(name);
    employeeRepo.erase(employeeRepo.begin() + ID);
}

Employee EmployeeRepository::GetEmployee(string name) {
    int ID = getID(name);
    return employeeRepo[ID];
}

int EmployeeRepository::getID(string name) {
    for (int i=0; i<employeeRepo.size(); ++i)
        if (employeeRepo[i].CheckDuplicateByName(name)) return i;
    return -1;
}

bool EmployeeRepository::IsExist(string employeeName) {
    for (int i=0; i<employeeRepo.size(); ++i) {
        if (employeeRepo[i].CheckDuplicateByName(employeeName)) return 1;
    }
    return 0;
}

bool EmployeeRepository::IsExist(vector<string> employeeNames) {
    for (int i=0; i<employeeNames.size(); ++i) {
        if (!IsExist(employeeNames[i])) return 0;
    }
    return 1;
}