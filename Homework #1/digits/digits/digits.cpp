/*
    PIC 10A Homework 1, digits.cpp
    Author: Damien Ha
    Date: 10/13/2021
*/

#include <iostream>
using namespace std; // use standard namespace in order to use cout and endl

int main() {
    
    cout << "Input a three-digit number (100 - 999):" << endl; // Prompt user to input a three-digit number
    
    int number; // Declare an integer for the user to input
    cin >> number; // Allow user to input and integer, assume it will be a 3-digit number
    
    int ones, tens, hundreds, product;
    ones = number % 10; // select the ones digit from the number the user has inputted
    tens = number / 10 % 10; // select the tens digit from the number the user has inputted
    hundreds = number / 100 % 10; // select the hundreds digit from the number the user has inputted
    product = ones * tens * hundreds; // calculate the product of the three digits
    
    cout << "The one's digit is " << ones << "." << endl;
    cout << "The ten's digit is " << tens << "." << endl;
    cout << "The hundred's digit is " << hundreds <<  "." << endl;
    // output each of the digits of the user's number
    
    cout << "The product of three digits is " << product << "." << endl;
    // output the product of the digits of the user's number
    
    return 0;
}
