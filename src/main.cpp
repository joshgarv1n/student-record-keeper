/*
    *** STUDENT RECORD KEEPER APP ***
*/

#include "../include/main.h"

const string WELCOME = "\nWelcome to Student Record Keeper v0.1\n\n";
const vector<string> allowedSemesters = {
    "Spring 2023", 
    "Summer 2023", 
    "Fall 2023",
    "Spring 2024",
    "Summer 2024",
    "Fall 2024"
};
const array<string, 12> allowedGrades = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"};
const array<int, 4> allowedHours = {1, 2, 3, 4};

int main(int argc, char** argv) {
    
    bool terminate = false;

    Student thisStudent;
    
    userWelcome(WELCOME, thisStudent);

    while (!terminate) {
        displayMainMenu();
        terminate = true;
        // get user selection >>
        // optionIsValid()
        // call requested function
    }

    return 0;
}