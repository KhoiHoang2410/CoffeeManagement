//
//  Recipt.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef Recipt_hpp
#define Recipt_hpp

#include <vector>
using namespace std;

class Recipe {
private:
    int ID; // foreign key to Products.ID
    vector <int> materialID;
    vector <int> noMaterial;
public:
    Recipe();
    Recipe(int ID, string productName); // check ID is in Products
    
    void ClearData();
    
    bool AddMaterial(vector<string> materialNames, vector<int> numbers);
};

#endif /* Recipt_hpp */
