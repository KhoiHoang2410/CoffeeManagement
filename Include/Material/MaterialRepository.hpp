//
//  MaterialRepository.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef MaterialRepository_hpp
#define MaterialRepository_hpp

#include "Material.hpp"
#include "MaterialCheckList.hpp"
#include "../Date.hpp"

#include <vector>
#include <string>

using namespace std;

class MaterialRepository {
private:
    vector <int> ID;
    vector <Material> materialRepo;
    vector <int> stock;
    vector <double> importedPrice;
    vector <Date> importedDate, expiredDate;
    MaterialCheckList materialCheckList;
public:
    MaterialRepository() = default;
    
    bool ClearData();
    bool RestructureData();
    
    bool AddMaterialToCheckList(string materialName);
    bool AddMaterialInCheckList(string materialName, double cost, int number, int expiredInDay);
    bool UpdateStock(string materialName, int noTaken);

    bool ImportDataFromFile(string fileName);
    bool ImportDataFromFileToCheckList(string fileName);

    bool ExportData() const;
    bool ExportCheckListData() const;

    vector<pair<double, int> > GetCapitalCostAndStock(vector<vector<pair<string, int> > > src);
    pair<double, int> GetCapitalCostAndStock(vector<pair<string, int> > src);

    int CalcPriceForAllMaterial(string name);

    vector<int> GetIDsForThisMaterial(string name);

    int GetStock(string name);
    int GetStock(int ID);

    bool IsExisting(string materialName);

};

#endif /* MaterialRepository_hpp */
