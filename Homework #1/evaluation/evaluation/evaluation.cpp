/*
    PIC 10A Homework 1, evaluation.cpp
    Author: Damien Ha
    Date: 10/13/2021.
*/

#include <iostream>
#include <cmath> // To use math functions such as cos() and pow()
#include <iomanip> // To use setprecision() to limit number of decimals
// Call all libraries that will be used in this program
using namespace std; // Use standard name space in order to use cout and endl

int main() {
    
    cout << "Input two integers:" << endl; // Prompt the user to input two integers
    
    int x, y; // Declare two integers that the user can input
    
    cin >> x; // Allow user to input their first integer
    cin >> y; // Allow user to input a second integer
    
    double expression, expression1, expression2; // Declare the expression (in parts)
    expression1 = cos(x) + pow(x, -5); // Assign the value of the numerator to "expression1"
    expression2 = abs(y) + 1; // Assign the value of the denominator to "expression2"
    expression = expression1 / expression2; // Assign the value of the full expression (the numerator over the denominator) to "expression" (evaluate the full expression)
    
    cout << "The first number is equal to " << x << endl; // Output the user's first number
    cout << "The second number is equal to " << y << endl; // Output the user's the second number
    
    cout << "The expression is equal to " << fixed << setprecision(4) << expression << endl; // Output the value of the evaluated expression to 4 decimal places
    
    return 0;
}
