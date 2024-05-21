/*
    FUNCTIONS HEADER FILE
*/

#ifndef STUDENTS_FUNCTIONS_H
#define STUDENTS_FUNCTIONS_H

#include "student.h"
#include "course.h"
#include <iostream>
#include <string>
#include <unistd.h>         // for sleep()
using namespace std;

void userWelcome(string, Student&);
bool isYesNo(string, char&);
void setUserName(string&, string&);
void validateUserName(string&, string&, Student&);
void displayMainMenu();

#endif // STUDENTS_FUNCTIONS_H