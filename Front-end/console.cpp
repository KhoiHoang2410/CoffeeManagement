#pragma once

#include <stdio.h>
#include "console.h"


// int inputKey()
// {
// 	if (_kbhit())
// 	{
// 		int key = _getch();

// 		if (key == 224)	// special key
// 		{
// 			key = _getch();
// 			return key + 1000;
// 		}

// 		return key;
// 	}
// 	else
// 	{
// 		return key_none;
// 	}

// 	return key_none;
// }


// //-------------------------Screen-------------------------
// void clrscr()
// {
// 	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;                  
// 	HANDLE	hConsoleOut;
// 	COORD	Home = {0,0};
// 	DWORD	dummy;

// 	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
// 	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

// 	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
// 	csbiInfo.dwCursorPosition.X = 0;
// 	csbiInfo.dwCursorPosition.Y = 0;
// 	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
// }


//screen: goto [x,y]
void gotoXY(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}




// //screen: get [y]
// int whereY()
// {
// 	CONSOLE_SCREEN_BUFFER_INFO csbi;
// 	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
// 		return csbi.dwCursorPosition.Y;
// 	return -1;
// }


// void TextColor (int color)
// {
// 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
// }

// void Nocursortype()
// {
// 	CONSOLE_CURSOR_INFO Info;
// 	Info.bVisible = FALSE;
// 	Info.dwSize = 20;
// 	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
// }

// void ShowCur(bool CursorVisibility)
// {
// 	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
// 	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
// 	SetConsoleCursorInfo(handle, &cursor);
// }

// void FixConsoleWindow()
// {
	
// 		HWND consoleWindow = GetConsoleWindow();
// 		LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
// 		style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
// 		SetWindowLong(consoleWindow, GWL_STYLE, style);
	
// }
