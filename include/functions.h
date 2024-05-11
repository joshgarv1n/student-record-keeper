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

void defaultWelcome();
void userWelcome(int, char**);
bool isYesNo(string, char&);

#endif // STUDENTS_FUNCTIONS_H