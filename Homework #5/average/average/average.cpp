/*
    PIC 10A Homework 5, average.cpp
    Author: Damien Ha
    Date: 11/10/2021
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


/* Prompts the user to enter their course grades
 @param hw: vector containing homework grades out of 100. Lowest 2 are dropped
 @param exam: vector containing exam scores out of 100. Midterm (first exam) is dropped in scheme 2
 @param participation: participation grade out of 100
 */
void read_grades(vector<double> &hw, vector<double> &exam, double &participation)
{
    cout << "Please enter homework grades 0-100: ";
    for (int i = 0; i < hw.size(); i++)
        {
            cin >> hw[i];
        }
    
    cout << "Please enter exam grades 0-100: ";
    for (int i = 0; i < exam.size(); i++)
        {
            cin >> exam[i];
        }
    
    cout << "Please enter participation grade 0-100: ";
    cin >> participation;
}


/* Computes the average course grade from both schemes, showing which assignments are dropped
 @param hw: vector containing 8 homework grades out of 100. Lowest 2 are dropped
 @param exam: vector containing 2 exam scores out of 100. Midterm (first exam) is dropped in scheme 2
 @param participation: participation grade out of 100
 */
double compute_average(vector<double> &hw, vector<double> &exam, double &participation)
{
    double min = hw[0];
    int position = 0;
    for (int i = 0; i < hw.size(); ++i)
    {
        if (hw[i] < min)
        {
            min = hw[i];
            position = i;
            break;
        }
    }
    // create a double named "minimum" which will find the first lowest homework score, loop through the elemts of the vector "hw" until the minimum is located
    
    double min2 = hw[0];
    int position2 = 0;
    for (int i = 0; i < hw.size(); ++i)
    {
        if (i != position && hw[i] <= min2)
        {
            min2 = hw[i];
            position2 = i;
            break;
        }
    }
    // create another double to find the second minimum (different from the previous one), loop through the elements of the vector "hw" until it is located, then break
    
    for (int i = 0; i < hw.size(); i++)
    {
        if (i == position)
        {
            cout << setw(12) << right << "Homework " << i+1 << setw(8) << hw[i] << " (Dropped)" << endl;
        }
        else if (i == position2)
        {
            cout << setw(12) << right << "Homework " << i+1 << setw(8) << hw[i] << " (Dropped)" << endl;
        }
        else
        {
            cout << setw(12) << right << "Homework " << i+1 << setw(8) << hw[i] << endl;
        }
        
    }
    // Output the homework scores from the elements of the vector "hw", the 2 minimum scores will have "(Dropped)" printed next to them
    
    double hwtotal = 0;
    for(int i = 0; i < hw.size(); i++)
    {
        if(i == position || i == position2)
        {
            continue;
        }
        else
        {
            hwtotal = hw[i]+hwtotal;
        }
    }
    // Calculate the homework total score, excluding the dropped scores
    
    double scheme1;
    scheme1 = (0.7 * hwtotal / 6) + (0.09 * exam[0]) + (0.2 * exam[1]) + (0.01 * participation);
    
    double scheme2;
    scheme2 = (0.7 * hwtotal / 6) + (0.29 * exam[1]) + (0.01 * participation);
    
    double average;
    if (scheme1 >= scheme2)
    {
        cout << setw(13) << right << "Midterm Exam" << setw(8) << exam[0] << endl;
        average = scheme1;
    }
    else
    {
        cout << setw(13) << right << "Midterm Exam" << setw(8) << exam[0] << " (Dropped in Scheme II)" << endl;
        average = scheme2;
    }
    // calculate the grade based on 2 different grading schemes, assign whichever scheme produces the higher grade to "average." Scheme 2 drops the first exam (the midterm) as printed in the output when scheme 2 is used, and makes the second exam (the final) worth 29% of the grade. Otherwise, homework is 70% of the grade, the midterm is 9%, the final is 20%, and particpation is 1%
    cout << setw(13) << right << "Final Exam" << setw(8) << exam[1] << endl;
    cout << setw(13) << right << "Participation" << setw(8) << participation << endl;
    // output the final exam and particpation grades
    return average;
    // the function returns the overall average grade, whichever is highest between the 2 schemes
}


int main()
{
    // declare containers for different grade items
    vector<double> hw(8);
    vector<double> exam(2); // contains midterm and final
    double participation;
    
    // read grades from user
    read_grades(hw, exam, participation);

    // compute average based on the grading scheme
    // print items to the console, including dropped situation
    double average = compute_average(hw, exam, participation);

    // output average grade
    cout << "The average grade is " << average << "." << endl;
    
    return 0;
}

