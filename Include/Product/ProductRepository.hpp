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
    vector <int> ID;
    vector <Product> productRepo;
    vector <int> stock;
    vector <double> capitalCost, sellPrice;
    vector <Date> importedDate;
    ProductCheckList productCheckList;
public:
    ProductRepository() = default;
    
    bool ClearData();
    bool UpdateCapitalCostAndStock(vector <pair<double, int> > stocks);
    
    bool AddProductToCheckList(string productName, vector<string> materialNames, vector<int> numbers);
    bool AddProductFromCheckList(string productName, double price);
    bool UpdatePrice(string materialName, double newPrice);
    bool UpdateRecipe(string productName, vector<string> materialNames, vector<int> numbers);
    
    bool EraseProduct(string productName);

    bool ImportDataFromFile(string fileName);
    bool ImportDataFromFileToCheckList(string fileName);
    
    bool ExportData() const;
    bool ExportCheckListData() const;

    bool IsExist(string productName);
    bool IsExist(vector<string> productNames);

    int Size();

    vector<vector<pair<string, int> > > GetListMaterialForEachProduct();
};

#endif /* ProductRepository_hpp */
