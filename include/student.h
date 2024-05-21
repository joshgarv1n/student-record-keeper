/*
    STUDENT DATA HEADER FILE
*/

#ifndef STUDENTS_DATA_H
#define STUDENTS_DATA_H

#include "course.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {

    private:
        string fName;
        string lName;
        vector<Course> courses;

    public:
        // Constructor
        Student();

        // Destructor
        ~Student();

        // Getters
        string getFirstName();
        string getLastName();

        // Setters
        void setFirstName(string);
        void setLastName(string);

};

#endif // STUDENTS_DATA_H