//
//  Menu.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "Menu.hpp"
#include "../Include/Helper.hpp"

#include <tuple>
#include <fstream>
#include <iostream>
using namespace std;

Menu::Menu() {
    ifstream cin("Data/Menu/MenuScreen.txt");
    if (!cin.is_open()) 
        PutError("Menu::Menu", "File not found", 1);

    int n; string str;
    cin >> n;

    OutPut("Menu::Menu", "Start import");
    getline(cin, str);
    for (int i=0; i<n; ++i) {
        getline(cin, str);
        menuOptions.push_back(str);
    }
    OutPut("Menu::Menu", "Import success");
    RenderImportCheckListScreen();
    RenderImportNewMaterialScreen();
    RenderImportNewProductScreen();
    RenderImportEmployeeScreen();
    RenderImportBillScreen();
}

void Menu::RenderMenuScreen() {
    ClearScreen();
    RenderTitle();
    for (int i=0; i<menuOptions.size(); ++i)
        RenderChooseOption(i + 1, menuOptions[i]);
    cout << endl << endl << endl;
    cout << "Input option: ";
}

void Menu::Process() {
	RenderMenuScreen();
    string option;
    
    while (1) {
        getline(cin, option);
        while (!IsInRange(option, 1, menuOptions.size())) {
            RenderMenuScreen();
            getline(cin, option);
        }
        subMenuScreen[StringToInt(option).second - 1]();
        RenderMenuScreen();
    }
}

void Menu::RenderSaveDataScreen() {
    RenderExitScreen();
}

void Menu::RenderImportCheckListScreen() {
    ClearScreen();
    vector<string> listFile = GetListFile("Data/MaterialCheckList");
    for (int i=0; i<listFile.size(); ++i) {
        if (IsHiddenFile(listFile[i])) continue;
        RenderNotice("Import file: Data/MaterialCheckList/" + listFile[i]);
        if (!admin.ImportMaterialToCheckList("Data/MaterialCheckList/" + listFile[i])) 
            RenderNotice("Import failed");
        else RenderNotice("Import success");
    }

    listFile = GetListFile("Data/ProductCheckList");
    for (int i=0; i<listFile.size(); ++i) {
        if (IsHiddenFile(listFile[i])) continue;
        RenderNotice("Import file: Data/ProductCheckList/" + listFile[i]);
        if (!admin.ImportProductToCheckList("Data/ProductCheckList/" + listFile[i])) 
            RenderNotice("Import failed");
        else RenderNotice("Import success");
    }
    RenderWaitingSentence();
}

void Menu::RenderImportNewMaterialScreen() {
    ClearScreen();
    vector<string> listFile = GetListFile("Data/ImportMaterial");
    for (int i=0; i<listFile.size(); ++i) {
        if (IsHiddenFile(listFile[i])) continue;
        RenderNotice("Import file: Data/ImportMaterial/" + listFile[i]);
        if (!admin.ImportNewMaterial("Data/ImportMaterial/" + listFile[i])) 
            RenderNotice("Import failed");
        else RenderNotice("Import success");
        
    }
    RenderWaitingSentence();
}

void Menu::RenderImportBillScreen() {
    ClearScreen();
    vector<string> listFile = GetListFile("Data/ImportBill");
    for (int i=0; i<listFile.size(); ++i) {
        if (IsHiddenFile(listFile[i])) continue;
        RenderNotice("Import file: Data/ImportBill/" + listFile[i]);
        if (!admin.ImportBill("Data/ImportBill/" + listFile[i]))
            RenderNotice("Import failed.");
        else RenderNotice("Import success");
    }
    RenderWaitingSentence();
}

void Menu::RenderImportNewProductScreen() {
    ClearScreen();
    vector<string> listFile = GetListFile("Data/ImportProduct");
    for (int i=0; i<listFile.size(); ++i) {
        if (IsHiddenFile(listFile[i])) continue;
        RenderNotice("Import file: Data/ImportProduct/" + listFile[i]);
        if (!admin.ImportNewProduct("Data/ImportProduct/" + listFile[i]))
            RenderNotice("Import failed.");
        else RenderNotice("Import success");
    }
    admin.CalculateProductStockAndCapitalCost();

    RenderWaitingSentence();
}

void Menu::RenderImportEmployeeScreen() {
    ClearScreen();
    vector<string> listFile = GetListFile("Data/ImportEmployee");
    for (int i=0; i<listFile.size(); ++i) {
        if (IsHiddenFile(listFile[i])) continue;
        RenderNotice("Import file: Data/ImportEmployee/" + listFile[i]);
        if (!admin.ImportEmployee("Data/ImportEmployee/" + listFile[i])) 
            RenderNotice("Import failed");
        else RenderNotice("Import success");
        
    }
    RenderWaitingSentence();
}

void Menu::RenderAllMaterialRepositoryScreen() {
    ClearScreen();
    admin.ExportMaterialRepository();
    RenderWaitingSentence();
}

void Menu::RenderAllBillRepositoryScreen() {
    ClearScreen();
    admin.ExportBillRepository();
    RenderWaitingSentence();
}

void Menu::RenderAllProductRepositoryScreen() {
    admin.CalculateProductStockAndCapitalCost();

    ClearScreen();
    admin.ExportProductRepository();
    RenderWaitingSentence();
}

void Menu::RenderAllEmployeeRepositoryScreen() {
    ClearScreen();
    admin.ExportEmployeeRepository();
    RenderWaitingSentence();
}

void Menu::RenderStatusMaterialScreen() {
    RenderExitScreen();
}

void Menu::RenderStatusProductScreen() {
    RenderExitScreen();
}

void Menu::RenderStatusEmployeeScreen() {
    RenderExitScreen();
}

void Menu::RenderSaleScreen() {
    // RenderExitScreen();
    string str, choose;
    ClearScreen();
    cout << "Enter employee name: ";
    getline(cin, str);
    if (!admin.GetEmployee(str).first) {
        return;
    }

    Bill bill(str);
    while (1) {
        ClearScreen();
        bill.ExportData();

        cout << "Do you want to add more item(0/1/2): ";
        getline(cin, choose);
        while (!IsInRange(choose, 0, 2)) {
            ClearScreen();
            bill.ExportData();
            cout << "Do you want to add more item(0/1/2): ";
            getline(cin, choose);
        }

        if (StringToInt(choose).second == 1) {
            ClearScreen();
            cout << "Enter product name: ";
            getline(cin, str);
            auto product = admin.GetProduct(str);
            while (get<0>(product) == false) {
                ClearScreen();
                cout << "(You enter wrong) Enter product name: ";
                getline(cin, str);
                product = admin.GetProduct(str);
            }
            bill.AddProduct(get<1>(product), get<2>(product));
        }

        else if (StringToInt(choose).second == 0){
            if (bill.Size() != 0) admin.AddBill(bill);
            return;
        }
        else {
            return;
        }
    }
}

void Menu::RenderExitScreen() {
    ClearScreen();
    cout << "Nice to meet you <3";
    RenderWaitingSentence();
    exit(0);
}

void Menu::RenderNotice(string title) {
    cout << endl << endl << title << endl << endl;
}

void Menu::RenderWaitingSentence() {
    cout << endl << endl << "Press enter to continue";
    getchar();
}

void Menu::ClearScreen() {
    system("clear && printf '\e[3J'");
}

void Menu::RenderTitle() {
    cout << "COFFEE MANAGER";
    cout << endl << endl << endl << endl << endl;
}

void Menu::RenderChooseOption(int id, string title) {
    cout << id << ". " << title << endl;
}
