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
<<<<<<< HEAD
    vector <int> stocks;
    vector <double> importedPrices;
    vector <double> salePrice;
    vector <Date> importedDates;
=======
    vector <int> stock;
    vector <double> capitalCost, sellPrice;
    vector <Date> importedDate;
>>>>>>> 2a5c537af9b4fef01893c728e0cccbd620710b2b
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

    int Size();

    vector<vector<pair<string, int> > > GetListMaterialForEachProduct();
};

#endif /* ProductRepository_hpp */
