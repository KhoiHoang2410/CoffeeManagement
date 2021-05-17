//
//  Recipt.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef Recipt_hpp
#define Recipt_hpp

#include <vector>
#include <string>

using namespace std;

class Recipe {
private:
    vector <string> materials;
    vector <int> noMaterial;
public:
    Recipe() = default;
    
    void ClearData();
    
    bool AddMaterial(vector<string> materialNames, vector<int> numbers);

    void Display() const;
};

#endif /* Recipt_hpp */
