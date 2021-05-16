#include "Menu.h"
#include "console.h"

Menu::Menu() {

}

void Menu::RenderFrame() {
	for (int j = 1; j <= 130; ++j) {
		gotoXY(30 + j, 1);
		cout << "─"; //─
		gotoXY(30 + j, 50);
		cout << "─";
	}
	
	gotoXY(31, 1);
	cout << "┌";
	gotoXY(160, 1);
	cout << "┐";
	for (int j = 2; j <= 49; ++j)
	{
		gotoXY(31, j);
		cout << "│";
		gotoXY(160, j);
		cout << "│";
	}
	gotoXY(31, 50);
	cout << "└";
	gotoXY(160, 50);
	cout << "┘";
}

void Menu::RenderFrameMini(int x, int y)
{
	for (int i = 1; i <= 26; ++i)
	{
		gotoXY(x + i, y);
		cout << "-";
		gotoXY(x + i, y + 2);
		cout << "-";
	}
	gotoXY(x, y + 1);
	cout << "│";
	gotoXY(x + 27, y + 1);
	cout << "│";
	gotoXY(x, y);
	cout << "┌";
	gotoXY(x + 27, y);
	cout << "┐";
	gotoXY(x, y + 2);
	cout << "└";
	gotoXY(x + 27, y + 2);
	cout << "┘";
}

void Menu::RenderMenu()
{
	RenderFrame();
	int a = 41, b = 3, c = 190, d = 39;
	gotoXY(a, b);
	cout << ( " ______     ______     ______   ______   ______     ______        ______     __  __     ______     ______     ") << endl;
	gotoXY(a, b + 1);
	cout << "/\\  ___\\   /\\  __ \\   /\\  ___\\ /\\  ___\\ /\\  ___\\   /\\  ___\\      /\\  ___\\   /\\ \\_\\ \\   /\\  __ \\   /\\  == \\ " << endl;
	gotoXY(a, b + 2);
	//Sleep(c);
	cout << "\\ \\ \\____  \\ \\ \\/\\ \\  \\ \\  __\\ \\ \\  __\\ \\ \\  __\\   \\ \\  __\\      \\ \\___  \\  \\ \\  __ \\  \\ \\ \\/\\ \\  \\ \\  _-/    " << endl;
	gotoXY(a, b + 3);
	//Sleep(c);
	cout << " \\ \\_____\\  \\ \\_____\\  \\ \\_\\    \\ \\_\\    \\ \\_____\\  \\ \\_____\\     \\/\\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\      " << endl;
	gotoXY(a, b + 4);
	//Sleep(c);
	cout << "  \\/_____/   \\/_____/   \\/_/     \\/_/     \\/_____/   \\/_____/      \\/_____/   \\/_/\\/_/   \\/_____/   \\/_/      ";
	gotoXY(d, b + 5);
	//Sleep(c);
	cout << " _____ ______   ________  ________   ________  ________  _______   _____ ______   _______   ________   _________   ";
	gotoXY(d, b + 6);
	//Sleep(c);
	cout << "|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\|\\   __  \\|\\   ____\\|\\  ___ \\ |\\   _ \\  _   \\|\\  ___ \\ |\\   ___  \\|\\___   ___\\ " << endl;
	gotoXY(d, b + 7);
	//Sleep(c);
	cout << "\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\___|\\ \\   __/|\\ \\  \\\\\\__\\ \\  \\ \\   __/|\\ \\  \\\\ \\  \\|___ \\  \\_| " << endl;
	gotoXY(d, b + 8);
	//Sleep(c);
	cout << " \\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\ \\   __  \\ \\  \\  __\\ \\  \\_|/_\\ \\  \\\\|__| \\  \\ \\  \\_|/_\\ \\  \\\\ \\  \\   \\ \\  \\  " << endl;
	gotoXY(d, b + 9);
	//Sleep(c);
	cout << "  \\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\__\\ \\__\\ \\_______\\ \\_______\\ \\__\\    \\ \\__\\ \\_______\\ \\__\\\\ \\__\\   \\ \\__\\" << endl;
	gotoXY(d, b + 10);
	//Sleep(c);
	cout << "   \\|__|     \\|__|\\|__|\\|__|\\|__| \\|__|\\|__|\\|__|\\|_______|\\|_______|\\|__|     \\|__|\\|_______|\\|__| \\|__|    \\|__|" << endl;
	//Sleep(c);



	for (int i = 1; i <= 4; ++i)
		RenderFrameMini(80, 15 + 3 * i);

	/*TextColor(6);
	gotoXY(69, 15);
	cout << "xxx         (N)";
	gotoXY(69, 18);
	cout << "xxx         (L)";
	gotoXY(69, 21);
	cout << "xxx         (S)";
	gotoXY(69, 24);
	cout << "xxx         (E)";*/

	/*char key;
	if (_kbhit)
	{
		key = _getch();
		if (key == 'p' || key == 'P')
		{
			system("cls");
		}
		else if (key == 'l' || key == 'L')
		{
			system("cls");
		}
		else if (key == 's' || key == 'S')
		{
			system("cls");
		}
		else if (key == 'e' || key == 'E')
		{
			system("cls");
		}
		else
		{

		}
	}*/
}

void Menu::Process() {
	RenderMenu();
	while (1) {
		// Khong display 
		/*
			Input choose: 
			Switch menu
			Display
			
		*/		
	}
}