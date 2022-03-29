/*
    PIC 10A Homework 3, mySqrt.cpp
    Author: Damien Ha
    Date: 10/27/2021
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    int n; // Create an integer that the user will input
    cout << "Please enter a positive integer: "; // Prompt the user to input a positive integer, assume they will listen to the directions
    cin >> n; // Allow user to input an integer
    
    double left, right, middle, length, TOL = 1e-5; // create doubles, "left" and "right" are the left and right bounds of the interval, "middle" will be the middle of the interval, "length" is interval length, TOL is the level of tolerance for the interval length
    left = 0; // set left bounds to be 0 at the beginning
    right = n; // set right bound to be the user's integer at the beginning
    cout << "Square root of " << n << " is located in the interval [0, " << n << "]." << endl; // The first line the computer outputs tells the user that the square root is between 0 and their number
    do{
        middle = (left + right) / 2; // The middle will be the avergae of the left and right bounds of the interval
        if(middle*middle-n>0)
        {
            right = middle; // make the right bounds equal to the middle when this inequality is true
        }
        else
        {
            left = middle; // otherwise make the left bounds be the middle
        }
        
        cout << "Square root of " << n << " is located in the interval [" << setprecision(10) << left << ", " << right << "]." << endl; // Tell the user an interval in which the square root of their integer is located
        length = right - left; // the right bound minus the left should be the total length of the interval
    }
    while(length >= TOL); // Continue the loop while the length of the interval is greater than the tolerance
    
    cout << "The interval length is " << length << "." << endl; // Tell the user how long the interval is
    
    return 0;
}
