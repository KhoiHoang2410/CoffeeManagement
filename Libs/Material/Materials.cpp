//
//  Materials.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "../../Include/Material/Materials.hpp"
#include "../../Include/Helper.hpp"

#include <iostream>

bool Materials::AddMaterial(string materialName) {
    if (GetID(materialName) != -1) {
        putError("Materials::AddMaterial", "Add existing material to check list", 1);
    }
    
    materials.push_back(Material(materialName));
    return true;
}

int Materials::GetID(string materialName) {
    for (int i=0; i<materials.size(); ++i)
        if (materials[i].CheckDuplicate(materialName))
            return i;
    return -1;
}

Material Materials::GetMaterial(string materialName) {
    int id = GetID(materialName);
    if (id == -1) {
        putError("Materials::Get", "ID not found", 1);
    }
    
    return materials[id];
}

bool Materials::UpdateMaterial(string materialName, string newName) {
    int id = GetID(materialName);
    if (id == -1) {
        putError("Materials::Update", "ID not found");
        return 0;
    }
    materials[id].UpdateName(newName);
    return 1;
}

bool Materials::EraseMaterial(string materialName) {
    int id = GetID(materialName);
    if (id == -1) {
        putError("Materials::Erase", "ID not found");
        return 0;
    }
    
    materials.erase(materials.begin() + id);
    return 1;
}

