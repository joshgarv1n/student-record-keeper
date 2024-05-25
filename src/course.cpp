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

string Course::getCourseID() {
    return courseID;
}

string Course::getCourseName() {
    return courseName;
}

string Course::getSemester() {
    return semester;
}

string Course::getTerm() {
    return term;
}

int Course::getYear() {
    return year;
}

string Course::getGrade() {
    return grade;
}

int Course::getHours() {
    return hours;
}

float Course::getGradePoints() {
    return gradePoints;
}

bool Course::compareCourses(const Course& c1, const Course& c2) {
    // Sort by year and term (e.g. Fall 2023, Spring 2024, Summer 2024)
    if (c1.year != c2.year) {
        return c1.year < c2.year;
    }

    const std::vector<string> termOrder = {"Spring", "Summer", "Fall"};
    auto it1 = std::find(termOrder.begin(), termOrder.end(), c1.term);
    auto it2 = std::find(termOrder.begin(), termOrder.end(), c2.term);

    return it1 < it2;
}