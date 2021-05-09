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
    static bool Add(string name);
    static int GetID(string name);
    static Material Get(string name);
    static bool Update(string name, string newName);
    static bool Erase(string name);
};

#endif /* Materials_hpp */


