/*
    STUDENT DATA HEADER FILE
*/

#ifndef COURSE_DATA_H
#define COURSE_DATA_H

#include <iostream>
#include <string>
using std::string;

class Course {

    protected:
    string courseID;
    string courseName;
    string semester;
    string grade;
    int hours;

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

    // Setters
    void setCourseID();
    void setCourseName();
    void setSemester();
    void setGrade();
    void setHours();
    
}; // end of class Course

#endif // COURSE_DATA_H