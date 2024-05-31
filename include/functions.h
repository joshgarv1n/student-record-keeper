/*
    FUNCTIONS HEADER FILE
*/

#ifndef STUDENTS_FUNCTIONS_H
#define STUDENTS_FUNCTIONS_H

#include "student.h"
#include "course.h"
#include "course_map.h"
#include <iostream>
#include <iomanip>          // for std::setw
#include <string>
#include <vector>
#include <unistd.h>         // for sleep()
#include <algorithm>        // for std::find
#include <limits>           // for std::numeric_limits
#include <filesystem>       
#include <fstream>
#include <sstream>
using namespace std;
namespace fs = std::filesystem;

// Core functions
void userWelcome(string, Student&);
void displayMainMenu(const vector<string>&);

// CourseMap functions
void loadCourses(CourseMap&);
string searchCourseMap(const CourseMap&, const string&);

// Menu functions
void addNewCourse(Student&, CourseMap&, const vector<string>&, const vector<string>&, const vector<int>&);
void removeCourse(Student&);
void removeCourseMenuSelection(const string&, const vector<string>&, int&);
void setUserName(string&, string&);
void chooseCourseID(CourseMap&, string&, string&);
void chooseCourseName(string&);
void chooseSemester(string&, const vector<string>&);
void chooseGrade(string&, const vector<string>&);
void chooseHours(int&, const vector<int>&);

// Utility functions
bool isYesNo(string, char&);
void validateUserName(string&, string&, Student&);
bool isValidInput(const vector<string>&, const string&);
void getStringInput(string, string&);
bool confirmMenuSelection(const vector<string>&, const int&);
bool confirmCourseSelection(const string&, const string&);
void printVectorMenu(const vector<string>&);
void pressEnterToContinue();
void toUpperCase(string&);

#endif // STUDENTS_FUNCTIONS_H