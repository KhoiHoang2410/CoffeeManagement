#include"Menu.h"


void frame()
{

	for (int j = 1; j <= 130; ++j)
	{
		gotoXY(30 + j, 1);
		putchar(196); //─
		gotoXY(30 + j, 50);
		putchar(196); //─
	}
	gotoXY(31, 1);
	putchar(218); //┌
	gotoXY(160, 1);
	putchar(191); //┐
	for (int j = 2; j <= 49; ++j)
	{
		gotoXY(31, j);
		putchar(124); //│
		gotoXY(160, j);
		putchar(124); //│
	}
	gotoXY(31, 50);
	putchar(192); //└
	gotoXY(160, 50);
	putchar(217); //┘
}

void frameMini(int x, int y)
{
	for (int i = 1; i <= 26; ++i)
	{
		gotoXY(x + i, y);
		putchar(205); //─
		gotoXY(x + i, y + 2);
		putchar(205); //─
	}
	gotoXY(x, y + 1);
	putchar(186); //│
	gotoXY(x + 27, y + 1);
	putchar(186); //│
	gotoXY(x, y);
	putchar(201); //┌
	gotoXY(x + 27, y);
	putchar(187); //┐
	gotoXY(x, y + 2);
	putchar(200); //└
	gotoXY(x + 27, y + 2);
	putchar(188); //┘
}

void printMenu()
{
	frame();
	Nocursortype();
	int a = 41, b = 3, c = 190, d = 39;
	gotoXY(a, b);
	TextColor(15);
	//Sleep(c);
	cout << " ______     ______     ______   ______   ______     ______        ______     __  __     ______     ______     " << endl;
	gotoXY(a, b + 1);
	TextColor(9);
	//Sleep(c);
	cout << "/\\  ___\\   /\\  __ \\   /\\  ___\\ /\\  ___\\ /\\  ___\\   /\\  ___\\      /\\  ___\\   /\\ \\_\\ \\   /\\  __ \\   /\\  == \\ " << endl;
	gotoXY(a, b + 2);
	TextColor(10);
	//Sleep(c);
	cout << "\\ \\ \\____  \\ \\ \\/\\ \\  \\ \\  __\\ \\ \\  __\\ \\ \\  __\\   \\ \\  __\\      \\ \\___  \\  \\ \\  __ \\  \\ \\ \\/\\ \\  \\ \\  _-/    " << endl;
	gotoXY(a, b + 3);
	TextColor(11);
	//Sleep(c);
	cout << " \\ \\_____\\  \\ \\_____\\  \\ \\_\\    \\ \\_\\    \\ \\_____\\  \\ \\_____\\     \\/\\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\      " << endl;
	gotoXY(a, b + 4);
	TextColor(12);
	//Sleep(c);
	cout << "  \\/_____/   \\/_____/   \\/_/     \\/_/     \\/_____/   \\/_____/      \\/_____/   \\/_/\\/_/   \\/_____/   \\/_/      ";
	gotoXY(d, b + 5);
	TextColor(13);
	//Sleep(c);
	cout << " _____ ______   ________  ________   ________  ________  _______   _____ ______   _______   ________   _________   ";
	gotoXY(d, b + 6);
	TextColor(14);
	//Sleep(c);
	cout << "|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\|\\   __  \\|\\   ____\\|\\  ___ \\ |\\   _ \\  _   \\|\\  ___ \\ |\\   ___  \\|\\___   ___\\ " << endl;
	gotoXY(d, b + 7);
	TextColor(15);
	//Sleep(c);
	cout << "\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\___|\\ \\   __/|\\ \\  \\\\\\__\\ \\  \\ \\   __/|\\ \\  \\\\ \\  \\|___ \\  \\_| " << endl;
	gotoXY(d, b + 8);
	TextColor(13);
	//Sleep(c);
	cout << " \\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\ \\   __  \\ \\  \\  __\\ \\  \\_|/_\\ \\  \\\\|__| \\  \\ \\  \\_|/_\\ \\  \\\\ \\  \\   \\ \\  \\  " << endl;
	gotoXY(d, b + 9);
	TextColor(11);
	//Sleep(c);
	cout << "  \\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\__\\ \\__\\ \\_______\\ \\_______\\ \\__\\    \\ \\__\\ \\_______\\ \\__\\\\ \\__\\   \\ \\__\\" << endl;
	gotoXY(d, b + 10);
	TextColor(14);
	//Sleep(c);
	cout << "   \\|__|     \\|__|\\|__|\\|__|\\|__| \\|__|\\|__|\\|__|\\|_______|\\|_______|\\|__|     \\|__|\\|_______|\\|__| \\|__|    \\|__|" << endl;
	//Sleep(c);
	TextColor(8);



	for (int i = 1; i <= 4; ++i)
		frameMini(80, 15 + 3 * i);

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
