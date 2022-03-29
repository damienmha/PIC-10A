/*
    PIC 10A Homework 2, RankString.cpp
    Author: Damien Ha
    Date: 10/20/2021
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string string1, string2, string3; // Declare 3 strings that the user will input
    cout << "Please enter three strings:" << endl; // Prompt user to input 3 strings, assume they will be valid strings
    
    getline(cin, string1); // Allow user to input the first string
    getline(cin, string2); // Allow user to input the second string
    getline(cin, string3); // Allow user to input the third string
    
    cout << "Descending dictionary order:" << endl; // Alert user that the output is in desecnding dictionary order
    
    if(string1 > string2 && string1 > string3)
        cout << string1 << endl; // compare string1 to string2 and string3, output string1 if it's the highest in dictionary order
    else if(string2 > string1 && string2 > string3)
        cout << string2 << endl; // compare string2 to string1 and string3, output string2 if it's the highest in dictionary order
    else
        cout << string3 << endl; // output string3 if none of the previous conditions are satisfied
        
    if(string1 > string2 && string1 < string3)
        cout << string1 << endl; // compare string1 to string2 and string3, output string1 if it's in the middle by dictionary order based off this comparison (when this condition is true)
    else if(string1 > string3 && string1 < string2)
        cout << string1 << endl; // compare string1 to string2 and string3, output string1 if it's in the middle by dictionary order based off this comparison (when this condition is true)
    else if(string2 > string3 && string2 < string1)
        cout << string2 << endl; // compare string2 to string1 and string3, output string2 if it's in the middle by dictionary order based off this comparison (when this condition is true)
    else if(string2 > string1 && string2 < string3)
        cout << string2 << endl; // compare string2 to string1 and string3, output string2 if it's in the middle by dictionary order based off this comparison (when this condition is true)
    else if(string3 > string1 && string3 < string2)
        cout << string3 << endl; // compare string3 to string1 and string2, output string3 if it's in the middle by dictionary order based off this comparison (when this condition is true)
    else
        cout << string3 << endl; // output string3 if none of the above conditions are satisfied
    
    if(string1 < string2 && string1 < string3)
        cout << string1 << endl; // compare string1 to string2 anf string3, output it if it's lowest in dictionary order
    else if(string2 < string1 && string2 < string3)
        cout << string2 << endl; // compare string2 to string1 anf string3, output it if it's lowest in dictionary order
    else
        cout << string3 << endl; // output string3 if none of the above conditions are satisfied
    
    return 0;
}
