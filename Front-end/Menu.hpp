//
//  Menu.hpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 19/05/2021.
//

#ifndef Menu_hpp
#define Menu_hpp

#include "../Include/Admin.hpp"

#include <vector>
#include <string>

using namespace std;

class Menu {
private:
    vector <string> menuOptions, menuInputMaterial;
public:
    Menu();
    void Process();
    Admin admin;
};

#endif /* Menu_hpp */
