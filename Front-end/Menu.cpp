//
//  Menu.cpp
//  CoffeeManagement
//
//  Created by Nguyen-Khoi Hoang on 09/05/2021.
//

#include "Menu.hpp"
#include "../Include/Helper.hpp"

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
}

void Menu::ClearScreen() {
    system("clear");
}

void Menu::RenderTitle() {
    cout << "COFFEE MANAGER";
    cout << endl << endl << endl << endl << endl;
}

void Menu::RenderChooseOption(int id, string title) {
    cout << id << ". " << title << endl;
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

void Menu::RenderNotice(string title) {
    cout << endl << endl << title << endl << endl;
}

void Menu::RenderWaitingSentence() {
    cout << endl << endl << "Press any button to continue";
    getchar();
}

void Menu::RenderLoadDataScreen() {
    ClearScreen();
    vector<string> listFile = GetListFile("Data/MaterialCheckList");
    for (int i=0; i<listFile.size(); ++i) {
        if (IsHiddenFile(listFile[i])) continue;
        admin.ImportMaterialToCheckList("Data/MaterialCheckList/" + listFile[i]);
    }
    listFile = GetListFile("Data/ProductCheckList");
    for (int i=0; i<listFile.size(); ++i) {
        if (IsHiddenFile(listFile[i])) continue;
        admin.ImportProductToCheckList("Data/MaterialCheckList/" + listFile[i]);
    }
    cout << "Import success";
    RenderWaitingSentence();

    // string str;

    // cout << "Material check list file: ";
    // getline(cin, str);

    // if (!admin.ImportMaterialsToCheckList(str)) RenderNotice("File not found");
    // else RenderNotice("Import success");

    // cout << "Product check list file: ";
    // getline(cin, str);

    // if (!admin.ImportProductsToCheckList(str)) RenderNotice("File not found");
    // else RenderNotice("Import success");

    // RenderWaitingSentence();
}

void Menu::RenderSaveDataScreen() {
    RenderExitScreen();
}

void Menu::RenderImportNewMaterialScreen() {
    ClearScreen();
    vector<string> listFile = GetListFile("Data/ImportMaterial");
    for (int i=0; i<listFile.size(); ++i) {
        if (IsHiddenFile("Data/ImportMaterial" + listFile[i])) continue;
        admin.ImportNewMaterial(listFile[i]);
    }

    cout << "Import success";
    RenderWaitingSentence();
    // string str;

    // cout << "Material file: ";
    // getline(cin, str);

    // if (!admin.ImportNewMaterial(str)) RenderNotice("File not found");
    // else RenderNotice("Import success");
    
    // RenderWaitingSentence();
}

void Menu::RenderImportNewProductScreen() {
    ClearScreen();
    vector<string> listFile = GetListFile("Data/ImportProduct");
    for (int i=0; i<listFile.size(); ++i) {
        if (IsHiddenFile(listFile[i])) continue;
        admin.ImportNewProduct("Data/ImportProduct" + listFile[i]);
    }
    admin.CalculateProductStockAndCapitalCost();

    cout << "Import success";
    RenderWaitingSentence();
}

void Menu::RenderAllMaterialRepositoryScreen() {
    ClearScreen();
    admin.ExportMaterialRepository();
    RenderWaitingSentence();
}

void Menu::RenderAllProductRepositoryScreen() {
    admin.CalculateProductStockAndCapitalCost();

    ClearScreen();
    admin.ExportProductRepository();
    RenderWaitingSentence();
}

void Menu::RenderStatusMaterialScreen() {
    RenderExitScreen();
}

void Menu::RenderStatusProductScreen() {
    RenderExitScreen();
}

void Menu::RenderAllEmployeeScreen() {
    RenderExitScreen();
}

void Menu::RenderStatusEmployeeScreen() {
    RenderExitScreen();
}

void Menu::RenderSaleScreen() {
    RenderExitScreen();
}

void Menu::RenderExitScreen() {
    ClearScreen();
    cout << "Nice to meet you <3";
    RenderWaitingSentence();
    exit(0);
}
