//
//  Employee.cpp
//  CoffeeManagement
//
//  Created by Khoi Hoang on 16/05/2021.
//

#include "../../Include/Employee/Employee.hpp"


Employee::Employee(string name, string position, int salary, Date startDate) : Item(name) {
    this->position = position;
    isWorking = 1;
    startWorkingDate = startDate;
    this->salary = salary;
}

void Employee::Display(ostream& out) const {
    out << this->GetID() << " " ;
    out << this->Name() << " " ;
    out << this->isWorking << " " ;
    out << this->startWorkingDate << " " ;
    out << this->stopWorkingDate << endl;
}

string Employee::Position() const {
    return this->position;
}

ostream& operator <<(ostream& out, const Employee& src) {
    src.Display(out);
    return out;
}

void Employee::ExportData() const {
    Date diff = Date().Diffrence(startWorkingDate);
    int n = diff.Year() * 12 + diff.Month();

    cout << "Name: " << name << endl;
    cout << "Position: " << position << endl;
    cout << "Working since: " << startWorkingDate << endl;
    cout << "Number of months: " << n << endl;
    cout << "Salary: " << salary << endl;
}
