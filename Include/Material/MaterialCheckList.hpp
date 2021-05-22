//
//  MaterialCheckList.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef MaterialCheckList_hpp
#define MaterialCheckList_hpp

#include <vector>
#include <string>

#include "Material.hpp"

using namespace std;

class MaterialCheckList {
private:
    vector <Material> materials;
public:
    bool AddMaterial(string materialName);
    int GetID(string materialName);
    bool IsExisting(int materialID);
    Material GetMaterial(int materialID);
    Material GetMaterial(string materialName);

    bool UpdateMaterial(string materialName, string newMaterialName);
    bool EraseMaterial(string materailName);
    
    bool ExportData() const;
};

#endif /* MaterialCheckList_hpp */