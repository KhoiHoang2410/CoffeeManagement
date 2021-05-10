//
//  Materials.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "../../Include/Material/Materials.hpp"
#include <iostream>

bool Materials::AddMaterial(string name) {
    materials.push_back(Material(name));
    return true;
}

int Materials::GetID(string name) {
    for (int i=0; i<materials.size(); ++i)
        if (materials[i].CheckDuplicate(name))
            return i;
    return -1;
}

Material Materials::GetMaterial(string name) {
    int id = GetID(name);
    if (id == -1) {
        cout << "Materials::Get(string)\n";
        cout << "ID not found.\n";
        exit(1);
    }
    
    return materials[id];
}

bool Materials::UpdateMaterial(string name, string newName) {
    int id = GetID(name);
    if (id == -1) {
        cout << "Materials::Update\n";
        cout << "ID not found.\n";
        return 0;
    }
    materials[id].UpdateName(name);
    return 1;
}

bool Materials::EraseMaterial(string name) {
    int id = GetID(name);
    if (id == -1) {
        cout << "Materials::Erase\n";
        cout << "ID not found.\n";
        return 0;
    }
    
    materials.erase(materials.begin() + id);
    return 1;
}
