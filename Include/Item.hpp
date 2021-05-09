//
//  Item.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef Item_hpp
#define Item_hpp

#include "Date.hpp"
#include <string>
using namespace std;

class Item {
private:
    int ID;
    string name;
    double price;
    Date addDate;
public:
    Item(string, double);
    
    string Name() const;
    double Price() const;
    Date AddDate() const;
};

#endif /* Item_hpp */

