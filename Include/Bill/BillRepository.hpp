//
//  BillRepository.hpp
//  CoffeeManagement
//
//  Created by Khoi Hoang on 17/05/2021.
//

#ifndef BillRepository_hpp
#define BillRepository_hpp

#include "Bill.hpp"

class BillRepository {
private:
    vector <Bill> billRepository;
public:
    BillRepository() = default;

    void Create(string employeeName);
    void AddItem(string productName, int price);
    void RemoveAnItemFromBill(int id);

    void ExportPriceLastBill();
    void ExportLastBill();
    void ExportAllData();
    
    int Size();
};

#endif /* BillRepository_hpp */
