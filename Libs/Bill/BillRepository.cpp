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

void BillRepository::ExportPriceLastBill() const {
    billRepository.back().Total();
}

void BillRepository::ExportLastBill() const {
    billRepository.back().ExportData();
}

bool BillRepository::ExportAllData() const {
    for (int i=0; i<billRepository.size(); ++i) {
        billRepository[i].ExportData();
        cout << endl;
    }
    return 1;
}

int BillRepository::Size() {
    return billRepository.size();
}

pair<pair<vector<string>, vector<vector<string> > >, pair<vector<vector<int> >, vector<vector<double> > > >
        BillRepository::ImportDataFromFile(string fileName) {
    ifstream cin(fileName);

    if (!cin.is_open()) {
        PutError("BillRepository::ImportDataFromFile", "File not Found", 1);
    }

    vector<vector<string> > productNames;
    vector<vector<int> > amounts;
    vector<vector<double> > prices;
    vector<string> employeeNames;
    int n, m, amount; double price; 
    string employee, productName;

    cin >> n;
    OutPut("BillRepository::ImportDataFromFile", fileName + " " + to_string(n));

    for(int i=0; i < n; i++) {
        getline(cin, employee);
        getline(cin, employee);
        cin >> m;

        employeeNames.push_back(employee);
        productNames.push_back(vector<string>());
        amounts.push_back(vector<int>());
        prices.push_back(vector<double>());

        for (int j=0; j < m; ++j) {
            getline(cin, productName);
            getline(cin, productName);

            cin >> amount >> price;

            productNames.back().push_back(productName);
            prices.back().push_back(price);
            amounts.back().push_back(amount);
        }
    }

    cin.close();

    
    OutPut("BillRepository::ImportDataFromFile", "Import success");

    return make_pair(make_pair(employeeNames, productNames), make_pair(amounts, prices));
}