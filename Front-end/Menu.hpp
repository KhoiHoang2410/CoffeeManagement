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
    vector <string> menuOptions;
    static inline vector<string> menuLoadData;

    static void RenderLoadDataScreen();
    static void RenderImportNewMaterialScreen();
    static void RenderImportNewProductScreen();
    static void RenderImportEmployee();
    
    static void RenderSaveDataScreen();

    static void RenderAllMaterialRepositoryScreen();
    static void RenderAllProductRepositoryScreen();
    static void RenderAllEmployeeScreen();

    static void RenderStatusMaterialScreen();
    static void RenderStatusProductScreen();
    static void RenderStatusEmployeeScreen();

    static void RenderSaleScreen();
    static void RenderExitScreen();

    static void ClearScreen();
    static void RenderNotice(string title);
    static void RenderTitle();

    static void RenderWaitingSentence();

    void (*subMenuScreen[9])() = {RenderSaveDataScreen, RenderAllMaterialRepositoryScreen, RenderAllProductRepositoryScreen
                            , RenderAllEmployeeScreen, RenderStatusMaterialScreen, RenderStatusProductScreen
                            , RenderStatusEmployeeScreen, RenderSaleScreen, RenderExitScreen};

    void RenderMenuScreen();
    void RenderChooseOption(int id, string title);
public:
    Menu();
    void Process();
    static inline Admin admin;
};

#endif /* Menu_hpp */
