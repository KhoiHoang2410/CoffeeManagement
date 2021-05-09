//
//  Date.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef Date_hpp
#define Date_hpp

#include <iostream>
#include <fstream>

using namespace std;

class Date {
private:
    int dd, mm, yy;
public:
    Date(); // get current date
    Date(int, int, int);
    
    int Day() const;
    int Month() const;
    int Year() const;
    
    void Output(ostream&) const ;
};

ostream& operator <<(ostream&, const Date&);

#endif /* Date_hpp */
