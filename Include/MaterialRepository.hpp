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

#include "Materials.hpp"

using namespace std;

class MaterialRepository {
private:
    vector <int> IDs;
    vector <Materials> materialRepo;
    vector <int> stocks;
    vector <double> importedPrice;
    vector <Date> importedDate, expiredDate;
public:
    MaterialRepository();
    
    bool ClearData();
    void RestructureData();
    
    bool Add(string materialName, int number = 1);
    bool ReadAllData(string fileName = "") const;
    bool Update(string materialName, int number);
};

#endif /* MaterialRepository_hpp */
