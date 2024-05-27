/*
    STUDENT DATA HEADER FILE
*/

#ifndef STUDENTS_DATA_H
#define STUDENTS_DATA_H

#include "course.h"
#include <iostream>
#include <iomanip>              // for std::setw
#include <string>
#include <vector>
using namespace std;

class Student {

    private:
        string fName;
        string lName;
        vector<Course> courses;
        bool sorted = false;

        void sortCourses();

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

        // Course modifications
        void addCourse(Course&);
        void displayCourseList();

        // Comparator
        static bool compareCourses(const Course&, const Course&);

        // Utility
        void pressEnterToContinue();
};

#endif // STUDENTS_DATA_H