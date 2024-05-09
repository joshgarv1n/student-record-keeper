/*
    *** STUDENT RECORD KEEPER APP ***
*/

#include "../include/main.h"

int main(int argc, char** argv) {
    
    if (argc < 2) {
        defaultWelcome();
    } else {
        userWelcome(argc, argv);
    }

    return 0;
}