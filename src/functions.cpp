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

void displayMainMenu(const vector<string>& options) {
    // Prints menu options from string vector in two columns
    // Prints left column option and checks for corresponding right column option 
    size_t mid = (options.size() + 1) / 2;

    cout << "\n";
    for (size_t i = 0; i < mid; ++i) {
        cout << i + 1 << ". " << std::left << std::setw(25) << options[i];
        if (i + mid < options.size()) {
            cout << i + mid + 1 << ". " << options[i + mid];
        }
        cout << endl;
    }  
}


// COURSEMAP FUNCTIONS //
void loadCourses(CourseMap& courseMap) {
    // Create a hashmap of hashmaps containing Course ID and Course Name key value pairs for all files in the data directory. Course prefix used as key of outer map
    const string dataDirectory = "./data/";

    // Iterate over all files in the data directory
    for (const auto& entry : fs::directory_iterator(dataDirectory)) {
        if (entry.is_regular_file()) {
            const auto& filePath = entry.path();
            ifstream file(filePath);
            if (!file) {
                cerr << "Error opening file: " << filePath << endl;
                continue;
            }

            string line;
            while (getline(file, line)) {
                istringstream ss(line);
                string courseId, courseName;

                if (getline(ss, courseId, ',') && getline(ss, courseName)) {
                    string prefix = courseId.substr(0, courseId.find(' '));
                    courseMap[prefix][courseId] = courseName;
                }
            }
        }
    } 
}

string searchCourseMap(const CourseMap& courseMap, const string& id) {
    // Search courseMap for given Course ID, return course name or empty string
    string prefix = id.substr(0, id.find(' '));
    auto prefixIt = courseMap.find(prefix);

    if (prefixIt != courseMap.end()) {
        auto courseIt = prefixIt->second.find(id);
        if (courseIt != prefixIt->second.end()) {
            return courseIt->second;
        }
    }

    return "";
}


// MENU FUNCTIONS //
void addNewCourse(Student& student, CourseMap& courseMap, const vector<string>& allowedSemesters, const vector<string>& allowedGrades, const vector<int>& allowedHours) {
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

    chooseCourseID(courseMap, id, name);
    newCourse.setCourseID(id);
    newCourse.setCourseName(name);
    
    chooseGrade(grade, allowedGrades);
    newCourse.setGrade(grade);

    chooseHours(hours, allowedHours);
    newCourse.setHours(hours);

    newCourse.setGradeValue();
    newCourse.setGradePoints();

    student.addCourse(newCourse);
} // end of addNewCourse()

void removeCourse(Student& student) {
    //
    int option;
    const vector<string> menu = {
        "Search by Course ID",
        "View All Courses",
        "Exit"
    };
    cout << "\nRemove a Course" << endl;
    while (true) {
        removeCourseMenuSelection("Select an option: ", menu, option);
        string courseID;
        string courseName;
        bool exit = false;
        switch (option) {
            case 1:         // Search by Course ID
                cout << "Search by Course ID selected." << endl;
                if (searchByCourseID(student, courseID, courseName)) {
                    if (confirmCourseRemoval(student, courseID, courseName)) {
                        exit = true;
                    }
                } else {
                    cout << "Invalid Course ID\n" << endl;
                }
                break;
            case 2:         // View All Courses
                cout << "View All Courses selected." << endl;
                break;
            case 3:         // Exit
                cout << "Exit selected." << endl;
                exit = true;
                break;
            default:
                cout << "Idk what happened bruh." << endl;
                break;
        } // end of switch
        if (exit) {
            break;
        }
    } // end of while (true)
} // end of removeCourse()

void removeCourseMenuSelection(const string& prompt, const vector<string>& menu, int& option) {
    //
    int userChoice;
    while (true) {
        printVectorMenu(menu);
        cout << prompt;
        cin >> userChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter a number from the list." << endl;
            continue;
        }

        if (userChoice < 1 || userChoice > 3) {
            cout << "\nInvalid selection. Please try again." << endl;
            continue;
        }

        if (confirmMenuSelection(menu, userChoice)) {
            option = userChoice;
            break;
        }
    }
}

void setUserName(string& f, string& l) {
    // Change first/last name of user
    cout << "Enter your first name: ";
    cin >> f;
    cout << "Enter your last name: ";
    cin >> l;
} // end of setUserName()

void chooseCourseID(CourseMap& courseMap ,string& id, string& name) {
    //
    string tempID;
    string tempName;
    while (true) {
        cout << "\nEnter Course ID (e.g. 'MATH 2414'): ";
        getline(cin, tempID);
        toUpperCase(tempID);
        tempName = searchCourseMap(courseMap, tempID);
        if (tempName != "") {
            if (confirmCourseSelection(tempID, tempName)) {
                id = tempID;
                name = tempName;
                break;
            }
        } else {
            cout << "Invalid Course ID" << endl;
        }
    }
} // end of chooseCourseID()

void chooseSemester(string& sem, const vector<string>& allowedSemesters) {
    // Displays list of valid semesters, user selects one and confirms
    int choice;
    string selectedSemester;
    while (true) {
        cout << "\nSelect a semester:" << endl;
        printVectorMenu(allowedSemesters);

        int choice = 0;
        cout << "Enter the number corresponding to your desired semester: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter a number from the list." << endl;
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
        toUpperCase(userGrade);

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
            cout << "Hours confirmed." << endl;
            hours = userHours;
            return;
        } else if (confirm == 'N' || confirm == 'n') {
            cout << "\nHours not confirmed." << endl;
        } else {
            cout << "\nInvalid confirmation response." << endl;
        }
    }
} // end of chooseHours()

bool searchByCourseID(Student& student, string& id, string& name) {
    // Search Student courses for Course ID, update id & name and return true if found
    string tempID;
    string tempName;

    cout << "\nEnter Course ID (e.g. 'MATH 2414'): ";
    getline(cin, tempID);
    toUpperCase(tempID);
    tempName = student.searchForCourse(tempID);

    if (tempName != "") {
        id = tempID;
        name = tempName;
        return true;
    }
    return false;
} // searchByCourseID()

bool confirmCourseRemoval(Student& student, string& id, string& name) {
    // If user confirms, course is removed from Student courses vector
    char confirm;
    while (true) {
        cout << id << ": " << name << endl;
        cout << "Confirm you would like to remove this course (Y/N): ";
        cin >> confirm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (confirm == 'Y' || confirm == 'y') {
            student.removeCourse(id);
            cout << id << ": " << name << " removed." << endl;
            return true;
        } else if (confirm == 'N' || confirm == 'n') {
            cout << "Not confirmed.\n" << endl;
            return false;
        } else {
            cout << "Invalid confirmation response." << endl;
        }     
    }
} // end of confirmCourseRemoval()


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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {
        cout << "\n" << prompt;
        getline(cin, str);
        
        while (true) {
            cout << "You entered: " << str << endl;
            cout << "Is this correct? (Y/N): ";

            char confirm;
            cin >> confirm;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

bool confirmMenuSelection(const vector<string>& menu, const int& selection) {
    // Requests user to confirm integer selection
    char confirm;
    while (true) {
        cout << "\nYou selected: " << menu[selection - 1] << endl;
        cout << "Confirm selection (Y/N): ";
        cin >> confirm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (confirm == 'Y' || confirm == 'y') {
            cout << "Confirmed.\n" << endl;
            return true;
        } else if (confirm == 'N' || confirm == 'n') {
            cout << "Not confirmed.\n" << endl;
            return false;
        } else {
            cout << "Invalid confirmation response." << endl;
        }     
    }
} // end of confirmIntSelection()

bool confirmCourseSelection(const string& id, const string& name) {
    // User confirms selected course id and course name
    char confirm;
    while (true) {
        cout << id << ": " << name << endl;
        cout << "Confirm selection (Y/N): ";
        cin >> confirm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (confirm == 'Y' || confirm == 'y') {
            cout << "Course Confirmed." << endl;
            return true;
        } else if (confirm == 'N' || confirm == 'n') {
            cout << "Not confirmed." << endl;
            return false;
        } else {
            cout << "Invalid confirmation response.\n" << endl;
        } 
    }
} // end of confirmCourseSelection()

void printVectorMenu(const vector<string>& options) {
    // Print numbered menu list using elements of options vector
    for (size_t i = 0; i < options.size(); ++i) {
        cout << i + 1 << ". " << options[i] << endl;
    }
} // end of printVectorMenu()

void pressEnterToContinue() {
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void toUpperCase(string& str) {
    //
    transform(str.begin(), str.end(), str.begin(), ::toupper);
} // end of toUpperCase()