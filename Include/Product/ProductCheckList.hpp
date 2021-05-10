//
//  ProductCheckList.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 10/05/2021.
//

#ifndef ProductCheckList_hpp
#define ProductCheckList_hpp

#include "Product.hpp"

#include <vector>
#include <string>

using namespace std;

class ProductCheckList {
private:
    vector <Product> products;
public:
    bool AddProduct(string productName, vector<string> materialNames, vector<int> numbers);
    int GetID(string productName);
    Product GetProduct(string productName);
    Product GetProduct(int ID);
    bool UpdateProduct(string productName, vector<string> materialNames, vector<int> numbers);
    bool EraseProduct(string productName);
    
    bool ExportDataToFile(string fileName);
};

#endif /* ProductCheckList_hpp */
