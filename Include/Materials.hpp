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
    static void Add(string name, double price);
    static int GetID(string name);
    static bool Update(string name, string newName, string newPrice);
    static bool Erase(string name);
};

#endif /* Material_hpp */
