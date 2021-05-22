//
//  Bill.cpp
//  CoffeeManagement
//
//  Created by Khoi Hoang on 21/05/2021.
//

#include "../../Include/Bill/Bill.hpp"

Bill::Bill(string employeeName) {
    this->employeeName = employeeName;
    this->exportDate = Date();
}

Bill::Bill(string employeeName, vector<string> productName, vector<double> price, vector<int> amount) {
    this->employeeName = employeeName;
    this->productName = productName;
    this->price = price;
    this->amount = amount;
    this->exportDate = Date();
    for (int i=0;i<productName.size(); ++i)
        IDs.push_back(i+1);
}

void Bill::AddProduct(string productName, double price) {
    for (int i=0; i<this->productName.size(); ++i)
        if (this->productName[i] == productName) {
            this->amount[i] += 1;
            return;
        }
    
    this->productName.push_back(productName);
    this->price.push_back(price);
}

void Bill::RemoveProduct(string productName, int amount) {
    for (int i=0; i<this->productName.size(); ++i)
        if (this->productName[i] == productName) {
            this->amount[i] -= amount;
            if (this->amount[i] == 0) {
                this->amount.erase(this->amount.begin() + i);
                this->productName.erase(this->productName.begin() + i);
                this->price.erase(this->price.begin() + i);
            }
        }
}

void Bill::RemoveProduct(int id, int amount) {
    this->amount[id] -= amount;
    if (this->amount[id] == 0) {
        this->amount.erase(this->amount.begin() + id);
        this->productName.erase(this->productName.begin() + id);
        this->price.erase(this->price.begin() + id);
    }
}

int Bill::Total() const {
    int res = 0;
    for (int i=0; i<productName.size(); ++i) {
        res += price[i] * amount[i];
    }
    return res;
}

int Bill::Size() const {
    return productName.size();
}

void Bill::ExportData() const {
    cout << "Bill ID: " << GetID() << endl;
    cout << "Employee name: " << employeeName << endl;
    // for (int i=0; i<productName.size(); ++i) {
    //     cout << "Date create: " << exportDate << endl;
    //     cout << "Product name: " << productName[i] << endl;
    //     cout << "Price: " << price[i] << endl;
    //     cout << "Amount: " << amount[i] << endl;
    // }

    for (int i=0; i<IDs.size(); ++i) {
        cout << "ID: " << IDs[i] << " - Product name: " << productName[i] << " - Amount: " << amount[i] 
            << " - Price: " << price[i] << endl;
    }
}