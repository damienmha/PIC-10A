/*
    PIC 10A Homework 7, StudentClub.h
    Author: Damien Ha
    Date: 11/26/2021
*/

#ifndef __StudentClub_h__
#define __StudentClub_h__

#include "Student.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


using namespace std;

class StudentClub
{
    public:
        StudentClub(string n);
        StudentClub(string n, Student* p, Student* t, vector<Student*> m);
        Student* get_president() const;
        Student* get_treasurer() const;
        vector<Student*> get_member() const;
        void set_president(Student* p);
        void set_treasurer(Student* t);
        void add_member(Student* s);
        void print() const;
    
    private:
        string name;
        Student* president;
        Student* treasurer;
        vector<Student*> member;
    
};

vector<string> find_youngest(const vector<Student*> member);

#endif /* StudentClub_h */
