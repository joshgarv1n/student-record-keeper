/*
    COURSE DATA
*/

#include "../include/course.h"

Course::Course() {
}

Course::~Course() {
}

float Course::calculateGradePoints() {
    return hours * gradeValue;
}

float Course::determineGradeValue() {
    map<string, float> gradeMap = {
        {"A", 4.00},
        {"A-", 3.67},
        {"B+", 3.33},
        {"B", 3.00},
        {"B-", 2.67},
        {"C+", 2.33},
        {"C", 2.00},
        {"C-", 1.67},
        {"D+", 1.33},
        {"D", 1.00},
        {"D-", 0.67},
        {"F", 0.00}
    };
    auto it = gradeMap.find(grade);     // locate grade in the map
    return it->second;                  // return the grade value
}

void Course::splitTermYear(const string& semester) {
    // Parse semester and store term as string and year as int
    string yearStr;
    istringstream iss(semester);
    iss >> term >> yearStr;
    year = std::stoi(yearStr);
}

void Course::setCourseID(string set_id) {
    courseID = set_id;
}

void Course::setCourseName(string set_name) {
    courseName = set_name;
}

void Course::setSemester(string set_semester) {
    semester = set_semester;
    splitTermYear(semester);
}

void Course::setGrade(string set_grade) {
    grade = set_grade;
}

void Course::setHours(int set_hours) {
    hours = set_hours;
}

void Course::setGradeValue() {
    gradeValue = determineGradeValue();
}

void Course::setGradePoints() {
    gradePoints = calculateGradePoints();
}

string Course::getCourseID() const {
    return courseID;
}

string Course::getCourseName() const {
    return courseName;
}

string Course::getSemester() const {
    return semester;
}

string Course::getTerm() const {
    return term;
}

int Course::getYear() const {
    return year;
}

string Course::getGrade() const {
    return grade;
}

int Course::getHours() const {
    return hours;
}

float Course::getGradePoints() const {
    return gradePoints;
}