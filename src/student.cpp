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

void Student::addCourse(Course& course) {
    courses.push_back(course);
} // end of addCourse()

void Student::displayCourseList() {
    cout << "\n" << fName << " " << lName << "'s Courses:" << endl;
    for (size_t i = 0; i < courses.size(); ++i) {
        cout << i+1 << ". " << courses[i].getCourseID() << "\t" << courses[i].getCourseName() << "\t" << courses[i].getGrade() << "\t" << courses[i].getSemester() << endl;
    }
}