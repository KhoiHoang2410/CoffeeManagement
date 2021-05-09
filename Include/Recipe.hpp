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
    Recipe(int ID); // check ID is in Products
    
    void clearData();
    
    void addMaterial(vector<string> materialNames, vector<string> numbers);
};

#endif /* Recipt_hpp */
