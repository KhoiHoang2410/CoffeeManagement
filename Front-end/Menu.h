#ifndef _Menu_h_
#define _Menu_h_

#include "../Include/Admin.hpp"

#include <vector>
#include <string>

using namespace std;

class Menu {
private:
    Admin admin;
    vector <string> menuOptions, menuInputMaterial;
    void RenderFrame();
    void RenderFrameMini(int x, int y);
    void RenderMenu();
public:
    Menu();
    void Process();
};

#endif
