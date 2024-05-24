/*
    FUNCTIONS
*/

#include "../include/functions.h"


// CORE FUNCTIONS //
void userWelcome(string welcome, Student& student) {
    // Display welcome message, set and validate user name
    string fName;
    string lName;

    cout << welcome;
    sleep(1);

    setUserName(fName, lName);
    validateUserName(fName, lName, student);
} //end of userWelcome()

void displayMainMenu() {
    // Display main menu options
    cout << "\nMAIN MENU:\n";
    cout << "1. Add new course\t\t 5. Calculate my GPA\n";
    cout << "2. Edit a course\t\t 6. Export records to CSV\n";
    cout << "3. Remove a course\t\t 7. Exit program\n";
    cout << "4. View course(s)\n";
} // end of displayMainMenu()


// MENU FUNCTIONS //
void addNewCourse(Student& student, const vector<string>& allowedSemesters, const vector<string>& allowedGrades, const vector<int>& allowedHours) {
    // Creates a new course and pushes to Student courses vector
    Course newCourse;
    string id;
    string name;
    string semester;
    string grade;
    int hours;

    cout << "\nAdd New Course" << endl;
    
    chooseSemester(semester, allowedSemesters);
    newCourse.setSemester(semester);

    getStringInput("Enter Course ID (e.g. 'MATH 2414'): ", id);
    newCourse.setCourseID(id);
    
    getStringInput("Enter Course Name (e.g. 'Calculus II'): ", name);
    newCourse.setCourseName(name);
    
    chooseGrade(grade, allowedGrades);
    newCourse.setGrade(grade);

    chooseHours(hours, allowedHours);
    newCourse.setHours(hours);

    newCourse.setGradeValue();
    newCourse.setGradePoints();

    student.addCourse(newCourse);
} // end of addNewCourse()


// USER FUNCTIONS //
void setUserName(string& f, string& l) {
    // Change first/last name of user
    cout << "Enter your first name: ";
    cin >> f;
    cout << "Enter your last name: ";
    cin >> l;
} // end of setUserName()

void chooseSemester(string& sem, const vector<string>& allowedSemesters) {
    // Displays list of valid semesters, user selects one and confirms
    int choice;
    string selectedSemester;
    while (true) {
        cout << "\nSelect a semester:" << endl;
        for (size_t i = 0; i < allowedSemesters.size(); ++i) {
            cout << i + 1 << ". " << allowedSemesters[i] << endl;
        }

        int choice = 0;
        cout << "Enter the number corresponding to your desired semester: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter an integer." << endl;
            continue;
        }

        if (choice < 1 || choice > static_cast<int>(allowedSemesters.size())) {
            cout << "\nInvalid selection. Please try again." << endl;
            continue;
        }

        selectedSemester = allowedSemesters[choice - 1];
        char confirm;
        cout << "\nYou selected: " << selectedSemester << endl;
        cout << "Confirm selection (Y/N): ";
        cin >> confirm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (confirm == 'Y' || confirm == 'y') {
            cout << "Semester confirmed." << endl;
            sem = selectedSemester;
            return;
        } else if (confirm == 'N' || confirm == 'n') {
            cout << "Selection not confirmed." << endl;
        } else {
            cout << "Invalid confirmation response." << endl;
        }
    }
} // end of chooseSemester()

void chooseGrade(string& grade, const vector<string>& allowedGrades) {
    // User inputs letter grade which is validated and confirmed
    string userGrade;
    while (true) {
        cout << "\nEnter Letter Grade Received (e.g. 'A', 'B+', 'C-'): ";
        cin >> userGrade;

        auto it = std::find(allowedGrades.begin(), allowedGrades.end(), userGrade);
        if (it == allowedGrades.end()) {
            cout << "Invalid grade. Please try again." << endl;
            continue;
        }

        while (true) {
            char confirm;
            cout << "You entered: " << userGrade << endl;
            cout << "Confirm grade (Y/N): ";
            cin >> confirm;

            if (confirm == 'Y' || confirm == 'y') {
                cout << "Grade confirmed." << endl;
                grade = userGrade;
                return;
            } else if (confirm == 'N' || confirm == 'n') {
                cout << "Grade not confirmed." << endl;
                break;
            } else {
                cout << "Invalid confirmation response." << endl;
            }
        }
    }
} // end of chooseGrade()

void chooseHours(int& hours, const vector<int>& allowedHours) {
    // User inputs course hours which is validated and confirmed
    int userHours;
    while (true) {
        cout << "\nEnter credit hours (must be 1-4): ";
        if (!(cin >> userHours)) {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (cin.get() != '\n') {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the remaining input
            continue; // Restart the loop to prompt again
        }

        auto it = std::find(allowedHours.begin(), allowedHours.end(), userHours);
        if (it == allowedHours.end()) {
            cout << "Invalid hours. Please try again." << endl;
            continue;
        }

        char confirm;
        cout << "You entered: " << userHours << endl;
        cout << "Confirm hours (Y/N): ";
        cin >> confirm;

        if (confirm == 'Y' || confirm == 'y') {
            cout << "\nHours confirmed." << endl;
            hours = userHours;
            return;
        } else if (confirm == 'N' || confirm == 'n') {
            cout << "\nHours not confirmed." << endl;
        } else {
            cout << "\nInvalid confirmation response." << endl;
        }
    }
} // end of chooseHours()


// UTILITY FUNCTIONS //
bool isYesNo(string s, char& c) {
    // Verify user input is valid char
    if (s.length() == 1) {
        c = s[0];
        c = toupper(c);
        if (c == 'Y' || c == 'N') {
            return true;
        }
    }
    return false;
} // end of isYesNo()

void validateUserName(string& fName, string& lName, Student& student) {
    // Validate first/last name of user
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

bool isValidInput(const vector<string>& validInputs, const string& userInput) {
    // Check if user input is included in valid input vector
    for (const string& str : validInputs) {
        if (str == userInput) {
            return true;
        }
    }
    return false;
} // end of isValidInput(

void getStringInput(string prompt, string& str) {
    // Receives user string input and confirms with user
    while (true) {
        cout << "\n" << prompt;
        getline(cin, str);
        
        while (true) {
            cout << "You entered: " << str << endl;
            cout << "Is this correct? (Y/N): ";

            char confirm;
            cin >> confirm;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (confirm == 'N' || confirm == 'n') {
                break;
            } else if (confirm == 'Y' || confirm == 'y') {
                return;
            } else {
                cout << "\nInvalid input. Please enter 'Y' or 'N'." << endl;
            }
        }
    }
} // end of getStringInput()

void getIntegerInput(int& num) {
    // Receives user integer input and confirms with user
    while (true) {
        cin >> num;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You entered: " << num << endl;
        cout << "Is this correct? (Y/N): ";

        char confirm;
        cin >> confirm;
        cin.ignore();

        if (confirm == 'N' || confirm == 'n') {
            continue;
        } else if (confirm == 'Y' || confirm == 'y') {
            return;
        } else {
            cout << "Invalid input. Please enter 'Y' or 'N'." << endl;
        }
    }
} // end of getIntegerInput()
