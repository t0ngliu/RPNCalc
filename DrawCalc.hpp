#ifndef DRAWCALC_HPP
#define DRAWCALC_HPP

// takes the cursor to a certain position on the screen
void gotoxy(int x, int y);
// draws a rectangle with upper corner (x, y), width w and height h
void printRec(int x, int y, int w, int h);
// prints the outline of the calculator
void printCalc();
// clears the input box and stack display
void clearCalculator();

#endif
