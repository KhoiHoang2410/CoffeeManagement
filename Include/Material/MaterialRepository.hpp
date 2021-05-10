//
//  MaterialRepository.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#ifndef MaterialRepository_hpp
#define MaterialRepository_hpp

#include <vector>
#include <string>

#include "Material.hpp"
#include "../Date.hpp"

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
    bool ReadAllData(string fileName = "") const;
    bool UpdateStock(string materialName, int noTaken);
};

#endif /* MaterialRepository_hpp */
