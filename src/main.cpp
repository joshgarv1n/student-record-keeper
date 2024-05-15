/*
    *** STUDENT RECORD KEEPER APP ***
*/

#include "../include/main.h"

const string WELCOME = "\nWelcome to Student Record Keeper v0.1\n\n";

int main(int argc, char** argv) {
    
    bool terminate = false;
    
    userWelcome(argc, argv, WELCOME);

    while (!terminate) {
        displayMainMenu();
        terminate = true;
        // get user selection >>
        // optionIsValid()
        // call requested function
    }

    return 0;
}