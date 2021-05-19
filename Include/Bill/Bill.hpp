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
    Bill();

    void AsignEmployee(string employeeName);
    void Add(string productName, int price);
    void EraseProduct(string productName);
    void EraseProduct(int id);
    int Total();
    int NoProduct();
};

#endif /* Bill_hpp */
