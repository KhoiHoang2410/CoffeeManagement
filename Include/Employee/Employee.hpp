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

using namespace std;

class Employee : public Item {
private:
    Date startWorkingDate, stopWorkingDate;
    bool isWorking;
    string position;
public:
    Employee() = default;
    Employee(string name, string position);

    void StopWorking();

    void display(ostream& out) const;

    string Position() const;
};

ostream& operator <<(ostream& out, const Employee& src);

#endif /* Employee_hpp */
