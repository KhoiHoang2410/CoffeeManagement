//
//  Products.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 10/05/2021.
//

#ifndef Products_hpp
#define Products_hpp

#include "Product.hpp"

#include <vector>
#include <string>

using namespace std;

class Products {
private:
    static inline vector <Product> products;
public:
    static bool AddProduct(string productName, vector<string> materialNames, vector<int> numbers);
    static int GetID(string productName);
    static Product GetProduct(string productName);
    static Product GetProduct(int ID);
    static bool UpdateProduct(string productName, vector<string> materialNames, vector<int> numbers);
    static bool EraseProduct(string productName);
};

#endif /* Products_hpp */
