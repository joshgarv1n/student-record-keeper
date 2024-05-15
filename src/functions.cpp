/*
    FUNCTIONS
*/

#include "../include/functions.h"

// Beginning prompts when arguments are passed at execution (user's name)
void userWelcome(int num, char** name, string welcome) {

    string fName = "";
    string lName = "";
    bool userDefined = false;       // true if fName, lName assigned with setUserName()

    cout << welcome;
    sleep(1);
    
    if (num < 2) {
        setUserName(fName, lName);
        userDefined = true;
    }

    validateUserName(num, name, fName, lName, userDefined);

    cout << "Moving on.\n";

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
void validateUserName(int num, char** name, string& fName, string& lName, bool& userDefined) {
    bool goodName = false;
    char r;
    string response;
    bool goodResponse;

    while (!goodName) {
        cout << "\nPlease verify your first and last name\n";
        cout << "First Name: " << fName << "\n";
        
        if (!userDefined) {
            fName = name[1];
            if (num == 3) {
                lName = name[2];        // Assumes name[2] is last name
            } else if (num > 3) {
                lName = name[3];        // Assumes name[2] is middle name
            }
        }

        cout << "Last Name: " << lName << "\n";

        goodResponse = false;
        while (!goodResponse) {
            cout << "\nIs this correct? (Y/N): ";
            cin >> response;
            if (isYesNo(response, r)) {
                if (r == 'Y') {
                    cout << "Great!\n";
                    goodName = true;
                    goodResponse = true;
                } else {
                    setUserName(fName, lName);
                    userDefined = true;
                    goodResponse = true;
                }//end of if
            } else {
                cout << "You've entered an invalid response.\n";
            }//end of if
        }//end of while        
    } //end of while

} // end of validateUserName()