//
//  Bill.hpp
//  CoffeeManagement
//
//  Created by Khoi Hoang on 17/05/2021.
//

#ifndef Bill_hpp
#define Bill_hpp

#include "../Item.hpp"
#include "../Date.hpp"

#include <string>
#include <vector>
using namespace std;

class Bill : public Item {
private:
    Date exportDate;
    string employeeName;
    vector <int> IDs;
    vector <string> productName;
    vector <double> price;
    vector <int> amount;
public:
    Bill(string employeeName);
    Bill(string employeeName, vector<string> productName, vector<double> price, vector<int> amount);

    void AddProduct(string productName, double price);
    void RemoveProduct(string productName, int amount = 1);
    void RemoveProduct(int id, int amount = 1);
    void ExportData() const;
    int Total() const;
    int Size() const;
};

#endif /* Bill_hpp */
