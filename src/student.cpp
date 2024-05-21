/*
    STUDENT DATA
*/

#include "../include/student.h"

Student::Student() {
} // end of Student()

Student::~Student() {
} // end of ~Student()

void Student::setFirstName(string firstName) {
    fName = firstName;
} // end of setFirstName()

void Student::setLastName(string lastName) {
    lName = lastName;
} // end of setLastName()

string Student::getFirstName() {
    return fName;
} // end of getFirstName()

string Student::getLastName() {
    return lName;
} // end of getLastName()