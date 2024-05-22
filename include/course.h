/*
    STUDENT DATA HEADER FILE
*/

#ifndef COURSE_DATA_H
#define COURSE_DATA_H

#include <iostream>
#include <string>
#include <map>                      // used for determineGradeValue()
using std::string;
using std::map;

class Course {

    private:
        string courseID;            // e.g., COSC3360
        string courseName;          // e.g., Intro To Operating Systems
        string semester;            // e.g., Sp24, Su24, Fa24
        string grade;               // A, A-, B+, B, B-, C+, C, C-, D+, D, D-, F
        int hours;
        float gradeValue;           // A = 4.00, A- = 3.67, etc.
        float gradePoints;          // 3hrs with A = 12.00 grade points

        float calculateGradePoints();
        float determineGradeValue();

    public:
        // Constructor
        Course();

        // Destructor
        ~Course();

        // Getters
        string getCourseID();
        string getCourseName();
        string getSemester();
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
    
}; // end of class Course

#endif // COURSE_DATA_H