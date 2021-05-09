//
//  Item.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef Item_hpp
#define Item_hpp

#include <string>

using namespace std;

class Item {
protected:
    int ID;
    string name;
public:
    Item();
    Item(string);
    
    virtual bool CheckDuplicate(string);
    virtual string Name() const;
    
    virtual void UpdateName(string);
};

#endif /* Item_hpp */

