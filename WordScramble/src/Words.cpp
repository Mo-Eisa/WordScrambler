//Mohamed Eisa
//Ganesh
//WordScramble
//CSCI 1300
#include "Words.h"
#include "fstream"
#include <fstream>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

string words[5]; //how many words there are in each file
string randomWord;  // variable used for the random word
vector<char> randomWordLetters;  //letters of the word
using namespace std;

Words::Words(string fileName)
{
    ifstream infile(fileName);  //The file of the words based on the difficulty
    int i = 0;
    string line;
    while(getline(infile, line)){
        words[i] = line;
        i++;
    }
}

Words::~Words()
{
    //dtordd
}

void Words::pickRandomWord(){  //picks random word
    srand ( time(NULL) );
    int i = rand() % 5;
    randomWord = words[i];
    for(int i = 0; i < randomWord.length(); i++){
        randomWordLetters.push_back(randomWord[i]);
    }
}

string Words::getRandomWord(){      // gets the random word
    return randomWord;  //returns it
}

vector<char> Words::getRandomWordLetters(){ //gets the randomword letters
    return randomWordLetters; //returns it
}
