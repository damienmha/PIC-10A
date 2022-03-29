/*
    PIC 10A Homework 4, menu.cpp
    Author: Damien Ha
    Date: 11/03/2021
*/

#include <iostream>
using namespace std;

void displayMenu(int& times)
{
    cout << "================== MENU " << times << " ==================" << endl;
    cout << "1. Output the median" << endl;
    cout << "2. Get the next permutation" << endl;
    cout << "3. Sort in descending order" << endl;
    cout << "4. Simplify the numbers" << endl;
    cout << "Enter your choice (1 - 4), Q to quit: ";
}
// display a menu of options to the console

int median(int a, int b, int c)
{
    if (b>a && c<a)
    {
        cout << "The median among the three is: " << a << endl;
        return a;
    }
    else if (c>a && b<a)
    {
        cout << "The median among the three is: " << a << endl;
        return a;
    } // test if a is between b and c and output it if it is
    else if (c<b && a>b)
    {
        cout << "The median among the three is: " << b << endl;
        return b;
    }
    else if (a<b && c>b)
    {
        cout << "The median among the three is: " << b << endl;
        return b;
    } // test if b is between a and c and output it if it is
    else if (a>c && b<c)
    {
        cout << "The median among the three is: " << c << endl;
        return c;
    }
    else
    {
        cout << "The median among the three is: " << c << endl;
        return c;
    } // test if c is between b and a and output it if it is
}


void mySort(int& a, int& b, int& c)
{
    int l, m, n; // these are dummy variables that will be used to reassign the values of a, b, c and sort them
    
    cout << "After sorting: ";
    
    if (a>=b && a>=c)
    {
        l = a;
    }
    else if (b>=a && b>=c)
    {
        l = b;
    }
    else
    {
        l = c;
    }
    // Determine which value among a, b, and c is greatest and assign to l
    
    if (b>=a && c<=a)
    {
        m = a;
    }
    else if (c>=a && b<=a)
    {
        m = a;
    }
    else if (c<=b && a>=b)
    {
        m = b;
    }
    else if (a<=b && c>=b)
    {
        m = b;
    }
    else if (a>=c && b<=c)
    {
        m = c;
    }
    else
    {
        m = c;
    }
    // Determine which value among a, b, and c is second greatest and assign to m
    
    if (a<=b && a<=c)
    {
        n = a;
    }
    else if (b<=a && b<=c)
    {
        n = b;
    }
    else
    {
        n = c;
    }
    // Determine which value among a, b, and c is least and assign to n
    a = l;
    b = m;
    c = n;
    // reassing values so they will print in the right order
}


void myPermutation(int& a, int& b, int& c)
{
    int l, m, n; // dummy variables, just like mySort
    l = c;
    m = a;
    n = b;
    
    a = l;
    b = m;
    c = n;
    // reassign values a, b, and c to l, m, n
}


void mySimplify(int& a, int& b, int& c)
{
    int gcf = 1;
    int maximum = a + b + c; // largest it can be is their sum
    for(int i = 2; i<=maximum; i++)
    {
        if(a%i == 0 && b%i == 0 && c%i == 0)
        {
            gcf = i;
            break;
        }
    }
    // compute gcf
    a = a / gcf;
    b = b / gcf;
    c = c / gcf;
    // divide all values by greatest common factor
    cout << "After simplify: " << a << " " << b << " " << c << endl;
}


int main() {
    
    int a, b, c;
    cout << "Enter your three positive integers: ";
    cin >> a;
    cin >> b;
    cin >> c;
// Prompt the user to input 3 positive integer values
    
    bool valid = false; // Create a boolean value for validity
    
    while (a<=0 || b<=0 || c<=0)
    {
        if (!valid)
        {
            cout << "Error: non-positive inputs received." << endl;
            cout << endl;
            cout << "Enter your three positive integers: "  ;
            cin >> a;
            cin >> b;
            cin >> c;
            // When the user inputs invalid (non-positive) integers, give them an error message and promt them to input new values
        }
        }
    
    int times = 1;
    string choice;
    displayMenu(times);
    cin >> choice;
    while(choice != "Q") // assign menu choices to each of the corresponding functions, loop it until the user enters Q
    {
        if(choice == "1")
        {
            median(a, b, c);
            cout << endl;
        }
    
        else if(choice == "3")
        {
            mySort(a, b, c);
            cout << "After sorting: " << a << " " << b << " " << c << endl;
            cout << endl;
        }
    
        else if(choice == "2")
        {
            myPermutation(a, b, c);
            cout << "After one permutation: " << a << " " << b << " " << c << endl;
            cout << endl;
        }
        
        else if(choice == "4")
        {
            mySimplify(a, b, c);
            cout << endl;
        }
        
        times++;
        displayMenu(times);
        cin >> choice;
    }
    cout << "Exit the menu" << endl;
    // perform the functions until the user inputs Q, in which case they exit the menu
    
    return 0;
}
