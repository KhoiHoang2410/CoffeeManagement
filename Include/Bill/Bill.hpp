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
    vector <int> price;
    vector <int> amount;
public:
    Bill(string employeeName);

    void AddProduct(string productName, int price);
    void RemoveProduct(string productName, int amount = 1);
    void RemoveProduct(int id, int amount = 1);
    void ExportData();
    int Total();
    int Size();
};

#endif /* Bill_hpp */
