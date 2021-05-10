//
//  MaterialRepository.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef MaterialRepository_hpp
#define MaterialRepository_hpp

#include "Material.hpp"
#include "../Date.hpp"

#include <vector>
#include <string>

using namespace std;

class MaterialRepository {
private:
    vector <int> IDs;
    vector <Material> materialRepo;
    vector <int> stocks;
    vector <double> importedPrices;
    vector <Date> importedDates, expiredDates;
public:
    MaterialRepository() = default;
    
    bool ClearData();
    bool RestructureData();
    
    bool AddMaterialToCheckList(string materialName);
    bool AddMaterialInCheckList(string materialName, double price, int number = 1);
    bool UpdateStock(string materialName, int noTaken);

    bool ImportDataFromFile(string fileName);
    bool ImportDataFromFileToCheckList(string fileName);

    bool ExportDataToFile(string fileName) const;
    bool ExportCheckListDataToFile(string fileName = "");
};

#endif /* MaterialRepository_hpp */
