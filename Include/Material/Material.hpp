//
//  Material.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef Material_hpp
#define Material_hpp

#include "../Item.hpp"
#include "../Date.hpp"

class Material : public Item {
public:
    Material();
    Material(string materialName);
};

#endif /* Material_hpp */
