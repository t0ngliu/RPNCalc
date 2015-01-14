/* @author Tong Liu
 * @version 1.0
 */

#ifndef DRAWCALC_H
#define DRAWCALC_H

// takes the cursor to a certain position on the screen
void gotoxy(int x, int y);
//draws a rectangle with upper corner (x, y), width w and height h
void printRec(int x, int y, int w, int h);
//prints the outline of the calculator
void printCalc();
//clears the input box and stack display
void clearCalculator();
#include "drawCalc.cpp"

#endif
