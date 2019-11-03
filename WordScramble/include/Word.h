#ifndef WORD_H
#define WORD_H
#include "string"
#include <vector>

using namespace std;

class Word
{
    public:
        Word(string);
        virtual ~Word();
        void printWord();
        vector<char> letters;


    protected:

    private:
};

#endif // WORD_H
