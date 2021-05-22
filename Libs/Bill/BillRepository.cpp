//
//  BillRepository.cpp
//  CoffeeManagement
//
//  Created by Khoi Hoang on 21/05/2021.
//

#include "../../Include/Bill/BillRepository.hpp"
#include "../../Include/Helper.hpp"

#include <fstream>
#include <iostream>

using namespace std;

void BillRepository::CreateBill(string employeeName) {
    billRepository.push_back(Bill(employeeName));
}

void BillRepository::AddBill(string employeeName, vector<string> productName, vector<double> price, vector<int> amount) {
    billRepository.push_back(Bill(employeeName, productName, price, amount));
}

void BillRepository::AddItemToBill(string productName, int price) {
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

bool BillRepository::ImportDataFromFile(string fileName) {
    ifstream cin(fileName);

    if (!cin.is_open()) {
        PutError("BillRepository::ImportDataFromFile", "File not Found", 1);
    }

    vector <string> productNames;
    vector <int> amounts;
    vector <double> prices;
    int n, amount; double price; 
    string employee, productName;

    getline(cin, employee);
    cin >> n;
    OutPut("BillRepository::ImportDataFromFile", fileName + " " + to_string(n));

    for(int i=0; i < n; i++) {
        getline(cin, productName);
        getline(cin, productName);

        cin >> price >> amount;

        productNames.push_back(productName);
        prices.push_back(price);
        amounts.push_back(amount);
    }

    cin.close();

    AddBill(employee, productNames, prices, amounts);

    OutPut("BillRepository::ImportDataFromFile", "Import success");

    return 1;
}