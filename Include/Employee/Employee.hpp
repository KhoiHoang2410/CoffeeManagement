//
//  Employee.hpp
//  CoffeeManagement
//
//  Created by Khoi Hoang on 16/05/2021.
//

#ifndef Employee_hpp
#define Employee_hpp

#include "../ObjectManager.hpp"
#include "../Date.hpp"
#include "../Item.hpp"

#include <string>
#include <vector>

using namespace std;

class Employee : public Item {
private:
    Date startWorkingDate, stopWorkingDate;
    bool isWorking;
    string position;
    int salary;
public:
    Employee(string name, string position, int salary, Date startDate = Date());

    void StopWorking();

    void Display(ostream& out) const;

    string Position() const;

    void ExportData() const;
};

ostream& operator <<(ostream& out, const Employee& src);

#endif /* Employee_hpp */
