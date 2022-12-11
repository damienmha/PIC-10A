/*
    PIC 10A Homework 7, StudentClub.cpp
    Author: Damien Ha
    Date: 11/26/2021
*/

#include"StudentClub.h"

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

StudentClub::StudentClub(string n)
{
    name = n;
    president = nullptr;
    treasurer = nullptr;
    member.resize(0);
}

StudentClub::StudentClub(string n, Student* p, Student* t, vector<Student*> m)
{
    name = n;
    president = p;
    treasurer = t;
    member = m;
}

Student* StudentClub::get_president() const
{
    return president;
}

Student* StudentClub::get_treasurer() const
{
    return treasurer;
}

vector<Student*> StudentClub::get_member() const
{
    return member;
}

void StudentClub::set_president(Student* p)
{
    president = p;
}

void StudentClub::set_treasurer(Student* t)
{
    treasurer = t;
}

void StudentClub::add_member(Student* s)
{
    member.push_back(s);
}

void StudentClub::print() const
{
    cout << setw(20) << "Club Name: " << name << endl;
    cout << setw(20) << "President Name: " << president << endl;
    cout << setw(20) << "Treasurer Name: " << treasurer << endl;
    cout << setw(20) << "Current members: " << member.size() << endl;
}

vector<string> find_youngest(const vector<Student*> member)
{
    vector<string> youth(0);
    
    int youngest = (*member[0]).get_age();
    
    for(int i = 0; i < member.size(); i++)
        if((*member[i]).get_age() <= youngest)
        {
            youngest = (*member[i]).get_age();
        }
    for(int i = 0; i < member.size(); i++)
        if((*member[i]).get_age() == youngest)
        {
            youth.push_back((*member[i]).get_name());
        }
    return youth;
}
