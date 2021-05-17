//
//  EmployeeRepository.cpp
//  CoffeeManagement
//
//  Created by Khoi Hoang on 17/05/2021.
//

#include "../../Include/Employee/EmployeeRepository.hpp"
#include "../../Include/Helper.hpp"

void EmployeeRepository::AddEmployee(string name, string position) {
    employeeRepo.push_back(Employee(name, position));
}

void EmployeeRepository::ExportEmployee(string name) const {
    OutPut("EmployeeRepository::ExportEmployee", "Start export " + to_string(employeeRepo.size()));
    for (int i=0; i<employeeRepo.size(); ++i) {
        cout << "ID: " << employeeRepo[i].GetID() << endl;
        cout << "Name: " << employeeRepo[i].Name() << endl;
        cout << "Position: " << employeeRepo[i].Position() << endl;
    }

    OutPut("EmployeeRepository::ExportEmployee", "Export success");
}

bool EmployeeRepository::ImportDataFromFile(string fileName) {
    ifstream cin(fileName);

    if (!cin.is_open()) {
        PutError("EmployeeRepository::ImportDataFromFile", "File not Found", 1);
    }

    int n;
    cin >> n;
    string name, position;
    getline(cin, name);

    OutPut("EmployeeRepository::ImportDataFromFile", "Start import " + to_string(n));

    for(int i=0; i < n; i++){
       getline(cin, name);
       getline(cin, position);
       AddEmployee(name, position);
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
        if (employeeRepo[i].CheckDuplicate(name)) return i;
    return -1;
}