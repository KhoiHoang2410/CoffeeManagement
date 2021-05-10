//
//  ProductRepository.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 10/05/2021.
//

#ifndef ProductRepository_hpp
#define ProductRepository_hpp

#include "Product.hpp"
#include "../Date.hpp"

#include <vector>
#include <string>

using namespace std;

class ProductRepository {
private:
    vector <int> IDs;
    vector <Product> productRepo;
    vector <int> stocks;
    vector <double> importedPrices;
    vector <Date> importedDates;
public:
    ProductRepository() = default;
    
    bool ClearData();
    bool CalculateStock();
    
    bool AddProduct(string productName, double price);
    bool ReadAllData(string fileName = "") const;
    bool UpdatePrice(string materialName, double newPrice);
    bool UpdateRecipe(string productName, vector<string> materialNames, vector<int> numbers);
    
    bool EraseProduct(string productName);
};

#endif /* ProductRepository_hpp */
