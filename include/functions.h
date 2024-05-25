/*
    FUNCTIONS HEADER FILE
*/

#ifndef STUDENTS_FUNCTIONS_H
#define STUDENTS_FUNCTIONS_H

#include "student.h"
#include "course.h"
#include <iostream>
#include <iomanip>          // for std::setw
#include <string>
#include <vector>
#include <unistd.h>         // for sleep()
#include <algorithm>        // for std::find
#include <limits>           // for std::numeric_limits
using namespace std;

// Core functions
void userWelcome(string, Student&);
void displayMainMenu(const vector<string>&);

// Menu functions
void addNewCourse(Student&, const vector<string>&, const vector<string>&, const vector<int>&);

// User functions
void setUserName(string&, string&);
void chooseSemester(string&, const vector<string>&);
void chooseGrade(string&, const vector<string>&);
void chooseHours(int&, const vector<int>&);

// Utility functions
bool isYesNo(string, char&);
void validateUserName(string&, string&, Student&);
bool isValidInput(const vector<string>&, const string&);
void getStringInput(string, string&);
void getIntegerInput(int&);         // ***unused***

#endif // STUDENTS_FUNCTIONS_H