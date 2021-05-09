//
//  Date.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef Date_hpp
#define Date_hpp

#include<ctime>

class Date {
private:
    int dd, mm, yy;
public:
    Date(); // get current date
    Date(int day, int month, int year);
    int Day() const;
    int Month() const;
    int Year() const;
};

#endif /* Date_hpp */
