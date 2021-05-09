//
//  Material.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef Material_hpp
#define Material_hpp

#include <vector>
#include <string>

#include "Item.hpp"

using namespace std;

class Materials {
private:
    static inline vector <Item> materials;
public:
    static void add(string name, double price);
    static int getID(string name);
    static bool update(string name, string newName, string newPrice);
    static bool erase(string name);
};

#endif /* Material_hpp */
