//
//  Date.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef Date_hpp
#define Date_hpp

class Date {
private:
    int dd, mm, yy;
public:
    Date(); // get current date
    Date(int, int, int);
    
    int Day() const;
    void Month() const;
    void Year() const;
};

#endif /* Date_hpp */
