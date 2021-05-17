//
//  main.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "../Front-end/Menu.h"

using namespace std;

int main() {
    Menu a;
    a.admin.ImportMaterialsToCheckList("MaterialsCheckList.txt");
    a.admin.ExportCheckListMaterial();
    return 0;
}
