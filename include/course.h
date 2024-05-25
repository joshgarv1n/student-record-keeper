/*
    STUDENT DATA HEADER FILE
*/

#ifndef COURSE_DATA_H
#define COURSE_DATA_H

#include <iostream>
#include <string>
#include <sstream>                  // used for std::istringstream
#include <map>                      // used for determineGradeValue()
#include <vector>                   // used for comparator
#include <algorithm>                // used for comparator
using std::string;
using std::map;
using std::istringstream;

class Course {

    private:
        string courseID;            // e.g., "COSC 3360"
        string courseName;          // e.g., "Intro To Operating Systems"
        string semester;            // e.g., "Spring 2024"
        string term;                // e.g. "Spring"
        int year;                   // e.g. 2024
        string grade;               // A, A-, B+, B, B-, C+, C, C-, D+, D, D-, F
        int hours;
        float gradeValue;           // A = 4.00, A- = 3.67, etc.
        float gradePoints;          // 3hrs with A = 12.00 grade points

        float calculateGradePoints();
        float determineGradeValue();
        void splitTermYear(const string&);

    public:
        // Constructor
        Course();

        // Destructor
        ~Course();

        // Getters
        string getCourseID();
        string getCourseName();
        string getSemester();
        string getTerm();
        int getYear();
        string getGrade();
        int getHours();
        float getGradePoints();

        // Setters
        void setCourseID(string);
        void setCourseName(string);
        void setSemester(string);
        void setGrade(string);
        void setHours(int);
        void setGradeValue();
        void setGradePoints();

        // Comparator
        bool compareCourses(const Course&, const Course&);
    
}; // end of class Course

#endif // COURSE_DATA_H