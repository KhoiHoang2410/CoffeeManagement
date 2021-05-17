//
//  ProductRepository.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 10/05/2021.
//

#ifndef ProductRepository_hpp
#define ProductRepository_hpp

#include "Product.hpp"
#include "ProductCheckList.hpp"
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
    ProductCheckList productCheckList;
public:
    ProductRepository() = default;
    
    bool ClearData();
    bool UpdateStock(vector <int> stocks);
    
    bool AddProductToCheckList(string productName, vector<string> materialNames, vector<int> numbers);
    bool AddProductInCheckList(string productName, double price);
    bool UpdatePrice(string materialName, double newPrice);
    bool UpdateRecipe(string productName, vector<string> materialNames, vector<int> numbers);
    
    bool EraseProduct(string productName);

    bool ImportDataFromFile(string fileName);
    bool ImportDataFromFileToCheckList(string fileName);
    
    bool ExportData() const;
    bool ExportCheckListData() const;
};

#endif /* ProductRepository_hpp */
