/*
    FUNCTIONS
*/

#include "../include/functions.h"

// Beginning prompts when no arguments passed at execution
void defaultWelcome() {

    cout << "Welcome to Student Record Keeper v0.1\n";

} //end of defaultWelcome()

// Beginning prompts when arguments are passed at execution (user's name)
void userWelcome(int num, char** name) {

    bool goodName = false;
    bool goodResponse;
    string response;
    char r;
    string fName = name[1];
    string lName;

    cout << "Hello " << fName << "!\n";
    sleep(1);
    cout << "Welcome to Student Record Keeper v0.1\n";
    sleep(1);
    
    while (!goodName) {
        cout << "\nPlease verify your first and last name\n";
        cout << "First Name: " << fName << "\n";
        
        if (num == 3) {
            lName = name[2];
            cout << "Last Name: " << lName << "\n";
        }
        else if(num > 3) {
            lName = name[3];
            cout << "Last Name: " << lName << "\n";
        } else {
            cout << "Last Name:\n";
        }

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
                    goodResponse = true;
                }//end of if
            } else {
                cout << "You've entered an invalid response.\n";
            }//end of if
        }
    } //end of while

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

//
void setUserName(string& f, string& l) {

    cout << "Enter your first name: " << endl;
    cin >> f;
    cout << "Enter your last name: " << endl;
    cin >> l;

} // end of setUserName()