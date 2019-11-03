//Mohamed Eisa
//Ganesh
//WordScramble
//CSCI 1300
#ifndef MECHANICS_H
#define MECHANICS_H

#include "Mechanics.h"
#include "windows.h"
#include "string"
#include "Words.h"
#include <iostream>
// Explained in cpp file
class Mechanics
{
    public:
        void startGame();
        bool aLetter(char);
        bool theRightLetter(char);
        void printProgressBar(string);
        void loadLetters();



    private:
};

#endif // MECHANICS_H
