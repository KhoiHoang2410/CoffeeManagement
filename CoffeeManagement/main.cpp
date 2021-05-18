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
    a.admin.ImportMaterialsToCheckList("MaterialCheckList.txt");
    // a.admin.ExportCheckListMaterial();

    a.admin.ImportNewMaterial("MaterialRepos.txt");
    // a.admin.ExportMaterialRepository();

    a.admin.ImportProductsToCheckList("ProductCheckList.txt");
    // a.admin.ExportCheckListProduct();

    a.admin.ImportNewProduct("ProductRepos.txt");
    a.admin.CalculateProductStockCanBeSolve();
    a.admin.ExportProductRepository();
    return 0;
}
