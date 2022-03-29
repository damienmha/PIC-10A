/*
    PIC 10A Homework 2, CountSpace.cpp
    Author: Damien Ha
    Date: 10/20/2021
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string sentence;
    int sentencelength, i, spaces = 0; // declare integer variables to be used in for loop, sentencelength is total length of sentence in characters, spaces is number of spaces
    
    cout << "Please enter a sentence: "; // prompt user to enter a sentence, assume it will be a valid string
    getline(cin, sentence); // allow user to input a sentence on the same line as the prompt
    
    sentencelength = sentence.length(); // initialize sentence length as the length of the string "sentence" in characters
    
    for(i=0; i<=sentencelength; i++) // run the loop from i=0 to sentencelength
    {
        if(sentence[i] == ' ')
        {
            spaces++; // add 1 to "spaces" if the character is a space
        }
    }
    
    cout << "\"" << sentence << "\"" << " has " << spaces << " spaces." << endl; // Tell the user how many spaces their sentence has by outputting the resulting value of "spaces" to the console
    
    return 0;
}
