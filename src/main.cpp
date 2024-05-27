/*
    *** STUDENT RECORD KEEPER APP ***
*/

#include "../include/main.h"

const string WELCOME = "\nWelcome to Student Record Keeper v0.1\n\n";
const vector<string> mainMenuOptions = {
    "Add new course",
    "Edit a course",
    "Remove a course",
    "View course(s)",
    "Calculate my GPA",
    "Export records to CSV",
    "Exit program"
};
const vector<string> allowedSemesters = {
    "Spring 2023", 
    "Summer 2023", 
    "Fall 2023",
    "Spring 2024",
    "Summer 2024",
    "Fall 2024"
};
const vector<string> allowedGrades = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"};
const vector<int> allowedHours = {1, 2, 3, 4};

int main(int argc, char** argv) {
    
    bool terminate = false;
    int choice;
    Student thisStudent;

    userWelcome(WELCOME, thisStudent);

    while (!terminate) {
        displayMainMenu(mainMenuOptions);
        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
            continue; 
        }

        switch (choice) {
            case 1:
                addNewCourse(thisStudent, allowedSemesters, allowedGrades, allowedHours);
                break;
            case 2:
                cout << "Edit a course... under construction..." << endl;
                break;
            case 3:
                removeCourse(thisStudent);
                break;
            case 4:
                thisStudent.displayCourseList();
                break;
            case 5:
                cout << "Calculate my GPA... under construction..." << endl;
                break;
            case 6:
                cout << "Export to CSV... under construction..." << endl;
                break;
            case 7:
                cout << "Exiting program..." << endl;
                cout << "Goodbye." << endl;
                terminate = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}