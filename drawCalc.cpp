#include <iostream>
#include <windows.h>

#include "DrawCalc.hpp"

using namespace std;

// takes the cursor to a certain position on the screen
void gotoxy(int x, int y)
{   
    static HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x, y};
    
    SetConsoleCursorPosition(hStdout, position); 
}
//draws a rectangle with upper corner (x, y), width w and height h
void printRec(int x, int y, int w, int h)
{
    //top line
    gotoxy(x, y);
    cout << (char) 218;
    for (int i = 1; i <= w - 2; i++)
        cout << (char) 196;
    cout << (char) 191;
    
    //sides
    gotoxy(x, y + 1);
    cout << (char) 179;
    for (int i = 1; i <= h - 3; i++)
    {
        gotoxy(x + w - 1, y + i);
        cout << (char) 179;
        gotoxy(x, y + i + 1);
        cout << (char) 179;
    }
    gotoxy(x + w - 1, y + h - 2);
    cout << (char) 179;
    
    //bottom
    gotoxy(x, y + h - 1);
    cout << (char) 192;
    for (int i = 1; i <= w - 2; i++)
        cout << (char) 196;
    cout << (char) 217;
}

//prints the outline of the calculator
void printCalc()
{
    //input and stack boxes
    printRec(1, 0, 54, 3);
    printRec(1, 3, 30, 21);
    
    //splits the stack box for error box
    gotoxy(1, 5);
    cout << (char) 195;
    for (int i = 1; i <= 28; i++)
        cout << (char) 196;
    cout << (char) 180;
    
    //prints all the button boxes
    for (int x = 32; x <= 48; x += 8)
        for (int y = 3; y <= 21; y += 3)
             printRec(x, y, 7, 3);
    
    //prints the text
    gotoxy(34, 4);
    cout << "pop";
    gotoxy(41, 4);
    cout << "clear";
    gotoxy(49, 4);
    cout << "xchge";
    gotoxy(34, 7);
    cout << "sqrt";
    gotoxy(43, 7);
    cout << "^";
    gotoxy(51, 7);
    cout << "^2";
    gotoxy(34, 10);
    cout << "log";
    gotoxy(43, 10);
    cout << "ln";
    gotoxy(50, 10);
    cout << "rcp";
    gotoxy(35, 13);
    cout << "+";
    gotoxy(42, 13);
    cout << "asin";
    gotoxy(50, 13);
    cout << "sin";
    gotoxy(35, 16);
    cout << "-";
    gotoxy(42, 16);
    cout << "acos";
    gotoxy(50, 16);
    cout << "cos";
    gotoxy(35, 19);
    cout << "*";
    gotoxy(42, 19);
    cout << "atan";
    gotoxy(50, 19);
    cout << "tan";
    gotoxy(35, 22);
    cout << "/";
    gotoxy(42, 22);
    cout << "+/-";
    gotoxy(50, 22);
    cout << "quit";
}
//clears the input box and stack display
void clearCalculator()
{
    gotoxy(2, 1);
    for (int i = 1; i <= 52; i++)
        cout << " ";
    for (int i = 6; i <= 22; i++)
    {
        gotoxy(2, i);
        for (int j = 1; j <= 28; j++)
            cout << " ";
    }
}
