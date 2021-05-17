//
//  Employee.cpp
//  CoffeeManagement
//
//  Created by Khoi Hoang on 16/05/2021.
//

#include "../../Include/Employee/Employee.hpp"


Employee::Employee(string name, string position) : Item(name) {
    this->position = position;
    isWorking = 1;
}

void Employee::display(ostream& out) const {
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
    src.display(out);
    return out;
}
