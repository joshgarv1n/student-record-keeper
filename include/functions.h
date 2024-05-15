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

void userWelcome(int, char**, string);
bool isYesNo(string, char&);
void setUserName(string&, string&);
void validateUserName(int, char**, string&, string&, bool&);
void displayMainMenu();

#endif // STUDENTS_FUNCTIONS_H