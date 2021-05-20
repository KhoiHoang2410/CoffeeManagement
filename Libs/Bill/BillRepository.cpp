//
//  BillRepository.cpp
//  CoffeeManagement
//
//  Created by Khoi Hoang on 21/05/2021.
//

#include "../../Include/Bill/BillRepository.hpp"

void BillRepository::Create(string employeeName) {
    billRepository.push_back(Bill(employeeName));
}

void BillRepository::AddItem(string productName, int price) {
    billRepository.back().AddProduct(productName, price);
}

void BillRepository::RemoveAnItemFromBill(int id) {
    billRepository.back().RemoveProduct(id);
}

void BillRepository::ExportPriceLastBill() {
    billRepository.back().Total();
}

void BillRepository::ExportLastBill() {
    billRepository.back().ExportData();
}

void BillRepository::ExportAllData() {
    for (int i=0; i<billRepository.size(); ++i) {
        billRepository[i].ExportData();
        cout << endl;
    }
}

int BillRepository::Size() {
    return billRepository.size();
}
