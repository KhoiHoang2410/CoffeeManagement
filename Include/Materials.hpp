//
//  Materials.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef Materials_hpp
#define Materials_hpp

#include <vector>
#include <string>

#include "../Include/Material.hpp"

using namespace std;

class Materials {
private:
    static inline vector <Material> materials;
public:
    static bool AddMaterial(string materialName);
    static int GetID(string materialName);
    static Material GetMaterial(string materialName);
    static bool UpdateMaterial(string materialName, string newMaterialName);
    static bool EraseMaterial(string materailName);
};

#endif /* Materials_hpp */


