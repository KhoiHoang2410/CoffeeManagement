//
//  Item.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "Item.hpp"
#include "ObjectManager.hpp"

Item::Item(string name, double price) {
    this->name = name;
    this->price = price;
    this->ID = ObjectManager::generateNewID();
}
