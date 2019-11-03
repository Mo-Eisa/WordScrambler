#include "Word.h"
#include <iostream>
string theWord;

Word::Word(string randomWord)
{
    theWord = randomWord;
}

Word::~Word()
{
    //dtor
}

void Word::printWord(){
    cout << theWord << endl;
}


