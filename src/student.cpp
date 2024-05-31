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
    sorted = false;
} // end of addCourse()

void Student::displayCourseList() {
    if (!sorted) {
        sortCourses();
    } 
    const int idWidth = 11;
    const int nameWidth = 28;
    const int gradeWidth = 4;
    const int semWidth = 11;
    cout << "\n" << fName << " " << lName << "'s Courses:" << endl;
    for (size_t i = 0; i < courses.size(); ++i) {
        string currName = courses[i].getCourseName();
        if (currName.length() > nameWidth) {
            currName = currName.substr(0, nameWidth - 4) + "...";
        }
        cout << i+1 << ". " << setw(idWidth) << courses[i].getCourseID() << setw(nameWidth) << currName << setw(gradeWidth) << courses[i].getGrade() << setw(semWidth) << courses[i].getSemester() << endl;
    }
} // end of displayCourseList()

void Student::sortCourses() {
    // Sort courses vector using custom comparator
    std::sort(courses.begin(), courses.end(), compareCourses);
    sorted = true;
} // end of sortCourses()

bool Student::compareCourses(const Course& c1, const Course& c2) {
    // Sort by year and term (e.g. Fall 2023, Spring 2024, Summer 2024)
    if (c1.getYear() != c2.getYear()) {
        return c1.getYear() < c2.getYear();
    }

    const std::vector<string> termOrder = {"Spring", "Summer", "Fall"};
    auto it1 = std::find(termOrder.begin(), termOrder.end(), c1.getTerm());
    auto it2 = std::find(termOrder.begin(), termOrder.end(), c2.getTerm());

    return it1 < it2;
}

void Student::calculateGPA() {
    // Calculate cumulative GPA
    totalHours = 0;
    totalGradePoints = 0.00;
    
    if (courses.empty()) {
        return;
    }

    for (size_t i = 0; i < courses.size(); ++i) {
        totalHours += courses[i].getHours();
        totalGradePoints += courses[i].getGradePoints();
    }
    gpa = totalGradePoints / totalHours;
} // end of calculateGPA()

void Student::displayGPA() {
    // Display cumulative GPA and courses summary
    calculateGPA();
    cout << "\nYou have taken " << courses.size() << " class(es) and your cumulative GPA is " << fixed << setprecision(2) << gpa << endl;
}
