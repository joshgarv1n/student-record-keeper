/*
    FUNCTIONS HEADER FILE
*/

#ifndef STUDENTS_FUNCTIONS_H
#define STUDENTS_FUNCTIONS_H

#include "student.h"
#include <iostream>
#include <string>
#include <unistd.h>         // for sleep()
using namespace std;

void defaultWelcome(string);
void userWelcome(int, char**, string);
bool isYesNo(string, char&);
void setUserName(string&, string&);
void validateUserName(string&, string&, bool&, bool&);

#endif // STUDENTS_FUNCTIONS_H