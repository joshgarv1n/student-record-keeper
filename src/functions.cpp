/*
    FUNCTIONS
*/

#include "../include/functions.h"

// Display welcome message, set and validate user name
void userWelcome(string welcome, Student& student) {
    string fName;
    string lName;

    cout << welcome;
    sleep(1);

    setUserName(fName, lName);
    validateUserName(fName, lName, student);

} //end of userWelcome()

// Verify user input is valid char
bool isYesNo(string s, char& c) {

    if (s.length() == 1) {
        c = s[0];
        c = toupper(c);
        if (c == 'Y' || c == 'N') {
            return true;
        }
    }
    return false;

} // end of isYesNo()

// Change first/last name of user
void setUserName(string& f, string& l) {

    cout << "Enter your first name: ";
    cin >> f;
    cout << "Enter your last name: ";
    cin >> l;

} // end of setUserName()

// Validate first/last name of user
void validateUserName(string& fName, string& lName, Student& student) {
    bool goodName = false;
    char r;
    string response;
    bool goodResponse;

    while (!goodName) {
        cout << "\nPlease verify your first and last name\n";
        cout << "First Name: " << fName << "\n";
        cout << "Last Name: " << lName << "\n";

        goodResponse = false;
        while (!goodResponse) {
            cout << "\nIs this correct? (Y/N): ";
            cin >> response;
            if (isYesNo(response, r)) {
                if (r == 'Y') {
                    student.setFirstName(fName);
                    student.setLastName(lName);
                    cout << "Name saved.\n";
                    goodName = true;
                    goodResponse = true;
                } else {
                    setUserName(fName, lName);
                    goodResponse = true;
                }//end of if
            } else {
                cout << "You've entered an invalid response.\n";
            }//end of if
        }//end of while        
    } //end of while

} // end of validateUserName()

// Display main menu options
void displayMainMenu() {

    cout << "\nMAIN MENU:\n";
    cout << "1. Add new course\t\t 5. Calculate my GPA\n";
    cout << "2. Edit a course\t\t 6. Export records to CSV\n";
    cout << "3. Remove a course\t\t 7. Exit program\n";
    cout << "4. View course(s)\n";

} // end of displayMainMenu()