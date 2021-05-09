//
//  Item.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "../Include/Item.hpp"
#include "../Include/ObjectManager.hpp"

Item::Item(string name, double price) {
    this->name = name;
    this->price = price;
    this->ID = ObjectManager::GenerateNewID();
}

bool Item::checkDuplicate(string name) {
    return 1;
}


string Item::Name() const {
    return this->name;
}

double Item::Price() const {
    return this->price;
}

Date Item::AddDate() const {
    return this->addDate;
}



