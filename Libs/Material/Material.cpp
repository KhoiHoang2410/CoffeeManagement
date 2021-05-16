//
//  Material.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "../../Include/Material/Material.hpp"
#include "../../Include/ObjectManager.hpp"

Material::Material() {
}

Material::Material(string materialName) : Item(materialName) {
}

void Material::display(ostream& out) const {
    out << this->Name() << endl;
}

ostream& operator <<(ostream& out, const Material& src) {
    src.display(out);
    return out;
}