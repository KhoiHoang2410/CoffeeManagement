//
//  Item.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "../Include/Item.hpp"
#include "../Include/ObjectManager.hpp"
#include "../Include/Helper.hpp"

Item::Item() {
    this->ID = ObjectManager::GenerateNewID();
}

Item::Item(string name) {
    this->ID = ObjectManager::GenerateNewID();
    this->name = name;
}

bool Item::CheckDuplicate(string name) {
    return Normalize(this->name) == Normalize(name);
}

int Item::GetID() const {
    return ID;
}

string Item::Name() const {
    return this->name;
}

void Item::UpdateName(string newName) {
    this->name = newName;
}
