/*
    PIC 10A Homework 3, randomWalk.cpp
    Author: Damien Ha
    Date: 10/27/2021
*/

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    
    int x, y, randNumber; // declare integers for the program to use, "x" will be the x-coordinate, "y" will be the y-coordinate, "randNumber" will be a randomly generated number from 0 to 3, each of which will correspond to a direction the robot will move and that the computer can use to execute that move
    x = 0; // Initialize x as 0 because the robot starts at the origin, so x = 0 at the beginning
    y = 0; // Initialize y as 0 because the robot starts at the origin, so y = 0 at the beginning
    
    srand(static_cast<int>(time(nullptr))); // Generate a different seed for every interation of the program so that the robot will walk a random trajectory every time
    
    do
    {
        randNumber = rand()%4; // Generate a random number from 0 to 3
        
        if(randNumber == 0)
        {
            y = y + 1; // The random number being 0 will correspond to a move up, which will mean that 1 will be added to the y-coordinate for its next position
            cout << setw(10) << left << "Up" << "(" << x << ", " << y << ")" << endl; // Tell the user the direction the robot has moved and its new coordinates
        }
        else if(randNumber == 1)
        {
            y = y - 1 ; // The random number being 1 will correspond to a move down, which will mean that 1 will be subtracted from the y-coordinate for its next position
            cout << setw(10) << left << "Down" << "(" << x << ", " << y << ")" << endl; // Tell the user the direction the robot has moved and its new coordinates
        }
        else if(randNumber == 2)
        {
            x = x - 1 ; // The random number being 2 will correspond to a move left, which will mean that 1 will be subtracted from the x-coordinate for its next position
            cout << setw(10) << left << "Left" << "(" << x << ", " << y << ")" << endl; // Tell the user the direction the robot has moved and its new coordinates
        }
        else
        {
            x = x + 1 ; // Otherwise, the random number will correspond to a move right, which means 1 will be added to the x-coordinate for its next position
            cout << setw(10) << left << "Right" << "(" << x << ", " << y << ")" << endl; // Tell the user the direction the robot has moved and its new coordinates
        }
        
        if(x == 0 && y == 0)
        {
            break; // If the robot returns to the origin, the loop ends
        }
    }
    while(-5<x && -5<y && x<5 && y<5); // The loop continues to repeat while the robot is within the boundaries, and ends if the robot hits the boundary
    
    if(x==0 && y==0)
        cout << "Back to the origin!" << endl; // Tell the user that the robot has returned to the origin if the program exits when x = 0 and y = 0
    else
        cout << "Hit the boundary!" << endl; // Otherwise the program ends when the robot hits the boundary, in which case you'll tell the user that the robot has hit the boundary
    
    return 0;
}
