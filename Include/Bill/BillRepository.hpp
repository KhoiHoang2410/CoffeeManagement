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

    void AddBill(string employeeName, vector<string> productName, vector<double> price, vector<int> amount);

    void CreateBill(string employeeName);
    void AddItemToBill(string productName, int price);
    void RemoveAnItemFromBill(int id);

    void ExportPriceLastBill() const;
    void ExportLastBill() const;
    bool ExportAllData() const;

    bool ImportDataFromFile(string fileName);

    void removeBill(int id);
    
    int Size();
};

#endif /* BillRepository_hpp */
