//Mohamed Eisa
//Ganesh
//WordScramble
//CSCI 1300
#ifndef WORDS_H
#define WORDS_H
#include "string"
#include <vector>
using namespace std;

// Explained in cpp file
class Words
{
    public:
        Words(string);
        virtual ~Words();
        void pickRandomWord();
        string getRandomWord();
        vector<char> getRandomWordLetters();



    private:
};

#endif // WORDS_H
