#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

#include "stack.hpp"
#include "drawCalc.hpp"

using namespace std;

// converts a string to a number
float stringToNum(string instring);
//do operation, and returns whether the operation is successful 
bool doOperation(string input, mathStack &calc);
bool isNum(string instring);
//prints out the stack
void displayResult(mathStack& calc);

int main()
{
    mathStack calculator;
    mathStack& calculatorRef = calculator;
    char cinput[50];
    string input;
    
    //print the calculator layout on the console
    //and move the cursor to the top left for user to enter inputs
    printCalc();
    gotoxy(2, 1);


    //the calculator keeps running until the user enter quit 
    while(true)
    {
        //read and store user input
        gets(cinput);
        input = string(cinput);
        
        //clear and reset the error box
        gotoxy(2, 4);
        for (int i = 1; i <= 28; i++)
            cout << " ";
            
        //do operarion on the input using calculator
        bool isValid = doOperation(input, calculatorRef); //directly pass &calculator does not work somehow

        //if the calculation is not valid
        if (!isValid)  
        {
            //close the calcutor if the input is q or quit
            if (input == "q" || input == "Q" || input == "quit" || input == "QUIT"){
                return(0);
            }
            //push the input to stack if it is a number
            else if (isNum(input)){
                calculator.push(stringToNum(input));
            }
            else //output invalid message
            {
                gotoxy(2, 4);
                cout << "Your input is invalid";
            }
        }

        fflush(stdin);
        
        //clear operands, display result, and move cursor to the input box.
        clearCalculator();
        displayResult(calculatorRef);
        gotoxy(2, 1);
    }
}


// converts a string to a number
float stringToNum(string instring)
{
    float number;
    istringstream(instring) >> number;
    return(number);
}

//do operation, and returns whether the operation is successful 
bool doOperation(string input, mathStack &calc)
{
    bool isResolved = true;   //stores whether the input was processed
    bool good = true;       //stores if there was a operation error
    
    //if the called function takes 2 numbers
    if (input == "+" || input == "-" || input == "*" 
                 || input == "/" || input == "^" || input == "xchge")
    {
        if (calc.getSize() >= 2)    //checks if there are 2 numbers
        {
            switch (input[0])
            {
                case '+': good = calc.add();
                          break;
                case '-': good = calc.subtract();
                          break;
                case '*': good = calc.multiply();
                          break;
                case '/': good = calc.divide();
                          break;
                case '^': good = calc.power();
                          break;
                case 'x': good = calc.xchge();
                          break;
            }
        }
        else
        {
            gotoxy(2, 4);
            cout << "No enough operands in stack." << endl;
        }
    }
    //if the called fuction takes just 1 number
    else if (input == "sin" || input == "cos" || input == "tan" || input == "asin" || input == "acos" || 
             input == "atan" || input == "+/-" || input == "sqrt" || input == "^2" || input == "log" ||
             input == "ln" || input == "rcp" || input == "pop")
    {
        if (calc.getSize() >= 1)
        {
            if (input == "sin")
                good = calc.takesin();
            else if (input == "cos")
                good = calc.takecos();
            else if (input == "tan")
                good = calc.taketan();
            else if (input == "asin")
                good = calc.takeasin();
            else if (input == "acos")
                good = calc.takeacos();
            else if (input == "atan")
                good = calc.takeatan();
            else if (input == "+/-")
                good = calc.flipsign();
            else if (input == "sqrt")
                good = calc.sqroot();
            else if (input == "^2")
                good = calc.square();
            else if (input == "log")
                good = calc.takelog();
            else if (input == "ln")
                good = calc.ln();      
            else if (input == "rcp")
                good = calc.rcp();
            else if (input == "pop")
                good = calc.pop();
        }
        else
        {
            gotoxy(2, 4);
            cout << "No operands in stack.";
        }
    }
    else if (input == "clear")
        calc.emptyList();
    else
        isResolved = false;   //the input was unprocessed if none of the above applies
        
    if (!good)      //if there was a math error
    {
        gotoxy(2, 4);
        cout << "Operation Error.";
    }
        
    return(isResolved);
}

bool isNum(string instring)
{
    //the first digit can be a number, '.' or '-'
    if ((instring[0] < '0' || instring[0] > '9') && instring[0] != '.' && instring[0] != '-')
        return(false);
    //the rest can only be numbers or '.'
    for (int i = 1; i < instring.length(); i++)
    {
        if ((instring[i] < '0' || instring[i] > '9') && instring[i] != '.')
            return(false);
    }
    
    //cannot have more than one decimal point
    int points = 0;
    for (int i = 0; i < instring.length(); i++)
    {
        if (instring[i] == '.')
            points++;
    }
    
    if (points <= 1)
        return(true);
    else
        return(false);
}

//prints out the stack
void displayResult(mathStack& calc)
{
    for (int i = 0; i < calc.getSize() && i <= 16; i++)  //prints no more than 17 numbers
    {
        gotoxy(2, 22 - i);
        cout << calc.get(i);
    }
}

