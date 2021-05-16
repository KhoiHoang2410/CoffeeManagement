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

#include <fstream>

class Material : public Item {
public:
    Material();
    Material(string materialName);

    void display(ostream& out) const;
};

ostream& operator <<(ostream& out, const Material& src);

#endif /* Material_hpp */
