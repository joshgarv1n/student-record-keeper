/*
    *** STUDENT RECORD KEEPER APP ***
*/

#include "../include/main.h"

const string WELCOME = "Welcome to Student Record Keeper v0.1\n";

int main(int argc, char** argv) {
    
    if (argc < 2) {
        defaultWelcome(WELCOME);
    } else {
        userWelcome(argc, argv, WELCOME);
    }

    return 0;
}