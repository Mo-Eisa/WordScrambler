//Mohamed Eisa
//Ganesh
//WordScramble
//CSCI 1300
#include <algorithm>
#include "Mechanics.h"
#include "windows.h"
#include "string"
#include "Words.h"
#include <iostream>
#include <time.h>
#include "fstream"


int x=1; // x direction
int y=1; // y direction
int lives; // lives variable
int livesUsed = 0; // amount of lives used
string theWord;
vector<char> currentLetters;
string progressBar;
// All the letters

char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

bool game_running = true;
bool won = false;
bool lost = false;
string level;
char map[20][40] = {
    "|------------------------------------|",
    "|@                                   |",
    "|                                    |",
    "|                                    |",
    "|                                    |",
    "|                                    |",
    "|                                    |",    // The map itself
    "|                                    |",
    "|                                    |",
    "|                                    |",
    "|                                    |",
    "|                                    |",
    "|                                    |",
    "|                                    |",
    "|                                    |",
    "|                                    |",
    "|                                    |",
    "|                                    |",
    "|------------------------------------|",
};

using namespace std;

void Mechanics::startGame(){
    //Words words(level);
    //words.pickRandomWord();
    //theWord = words.getRandomWord();

   //loadLetters();
    cout << "This is WordScramble, where you the user have to guess the word based" << endl;
    cout << "on the difficulty you choose, level 1 gives you 7 lives, level 2 gives" << endl; // description of the game
    cout << "you 5 lives and level 3 give you 3 lives. Guess the correct letters for" << endl;
    cout << "the word in order to win! Use the @ symbol with the arrow keys to find the" << endl;
    cout << "lettersGood Luck!" << endl;
    cout << "First, enter your name..." << endl;
    string userName; // name
    cin >> userName;
    cout <<"What level difficulty would you like 1-3? (between 1 easy, 3 hardest)" << endl;
    cin >> level;
    while(level != "1" && level != "2" && level != "3"){
        cout << "you need to select a correct level" << endl;  // if you don't choose a number in between 1-3 it asks you again
        cin >> level; //takes in level
    }
    if(level == "1"){
    Words words("words1.txt");
    words.pickRandomWord();
    theWord = words.getRandomWord();
    lives = 7;

    }
    if(level == "2"){
    Words words("words2.txt");
    words.pickRandomWord();
    theWord = words.getRandomWord();
    lives = 5;

    }
    if(level == "3"){
    Words words("words3.txt");
    words.pickRandomWord();
    theWord = words.getRandomWord();
    lives = 3;
    }
    loadLetters();

    while(game_running == true){
        if(lives == 0){
            won = false;
            lost = true;
            game_running = false;
        }
        system("cls");
        printProgressBar(theWord);
        cout << "" << endl;
        // Displaying the map
        for(int d=0; d<20; d++){
            cout << map[d] << endl;
        }


        system("pause>nul");
          //gameObj mvmnt;
       // void movement(char gameobj){
        if(GetAsyncKeyState(VK_DOWN)){
            int y2 = y+1;
            if(map[y2][x] == ' '){
                map[y][x] = ' ';         // moving down
                y++;
                map[y][x] = '@';
            }
            else if(aLetter(map[y2][x])){
                if(theRightLetter(map[y2][x])){
                    currentLetters.push_back(map[y2][x]);
                    map[y][x] = ' ';
                    y++;
                    map[y][x] = '@';
                }else{
                    map[y][x] = ' ';              // checks if you hit a letter
                    y++;
                    map[y][x] = '@';
                    lives--;
                    livesUsed++;
                }
            }
        }

        if(GetAsyncKeyState(VK_UP)){
            int y2 = y-1;
            if(map[y2][x] == ' '){
                map[y][x] = ' ';            // moving up
                y--;
                map[y][x] = '@';
            }
            else if(aLetter(map[y2][x])){
                if(theRightLetter(map[y2][x])){
                    currentLetters.push_back(map[y2][x]);
                    map[y][x] = ' ';
                    y--;
                    map[y][x] = '@';
                }else{
                    map[y][x] = ' ';
                    y--;
                    map[y][x] = '@';
                    lives--;
                    livesUsed++;
                }
            }
        }

        if(GetAsyncKeyState(VK_RIGHT)){
            int x2 = x+1;
            if(map[y][x2] == ' '){
                map[y][x] = ' ';            // moving to the right
                x++;
                map[y][x] = '@';
            }else if(aLetter(map[y][x2])){
                if(theRightLetter(map[y][x2])){
                    currentLetters.push_back(map[y][x2]);
                    map[y][x] = ' ';
                    x++;
                    map[y][x] = '@';
                }else{
                    map[y][x] = ' ';
                    x++;
                    map[y][x] = '@';
                    lives--;
                    livesUsed++;
                }
            }
        }

        if(GetAsyncKeyState(VK_LEFT)){
            int x2 = x-1;
            if(map[y][x2] == ' '){
                map[y][x] = ' ';            // moving to the left
                x--;
                map[y][x] = '@';
            }else if(aLetter(map[y][x2])){
                if(theRightLetter(map[y][x2])){
                    currentLetters.push_back(map[y][x2]);
                    map[y][x] = ' ';
                    x--;
                    map[y][x] = '@';
                }else{
                    map[y][x] = ' ';
                    x--;
                    map[y][x] = '@';
                    lives--;
                    livesUsed++;
                }
            }
        }

        if(GetAsyncKeyState(VK_ESCAPE)){
            game_running = false;          //escapes the game
        }
    }
    if(won){
        system("cls");
        cout << "CONGRATULATIONS " << userName << "! You won the game! The word is: " << theWord << endl;    // if you win
    }else if(lost){
        cout << "GAME OVER!!" << userName << ", The word was: " << theWord << endl;   //if you lost
    }else{
        cout << "Don't be a quitter!" << endl;   // if you quit
    }
    ofstream myfile;
    myfile.open ("results.txt");
    myfile << "Username: " << userName << endl;   // recording your stats
    myfile << "The word: " << theWord << endl;
    myfile << "Lives used: " << livesUsed << endl;
    myfile.close();
    cout << "Username: " << userName << endl;
    cout << "The word: " << theWord << endl;         //outputs your stats
    cout << "Lives used: " << livesUsed << endl;
}

// check if hit a letter
bool Mechanics::aLetter(char pos){
    for(int i = 0; i <= 25; i++){
        if(pos == letters[i]){
            return true;
        }
    }
    return false;
}

// check if hit the RIGHT letter
bool Mechanics::theRightLetter(char pos){
    for(int i = 0; i < theWord.size(); i++){
        if(pos == theWord[i]){
            return true;
        }
    }
    return false;
}

// prints the progress bar after screen("cls")
void Mechanics::printProgressBar(string word){
    // is not needed int wordLength = word.length();

    cout << "Here is your current word progress: ";
    for(int i = 0; i < word.length(); i++){
        bool found = (find(currentLetters.begin(), currentLetters.end(), word[i]) != currentLetters.end());
        if(found){
            cout << word[i];
        }else{
            cout << "_";
        }
    }
    cout << "" << endl;
    cout << "" << endl;
    cout << "You have " << lives << " lives left!" << endl;
    if(level =="1"){
        cout <<"Hint: This is a reptile" << endl;   // The hints with there appropriate conditions
        }
    if(level == "2"){
        cout << "Hint: This is a land animal" << endl;
    }
    if(level == "3"){
        cout << "Hint: This is a luxury car Brand" << endl;
    }
    else{

    }


    int check = 0;
    for(int i = 0; i < word.length(); i++){
        bool found = (find(currentLetters.begin(), currentLetters.end(), word[i]) != currentLetters.end());
        if(found){
            check++;                           //increases check int and check is used to check if word is completed
        }else{}
    }
    if(check == word.length()){
        won = true;
        lost = false;
        game_running = false;
    }

    /*if(word.length() == currentLetters.size()){
        won = true;
        lost = false;
        game_running = false;
    }
    */

    cout << "" << endl;


}

//Function to randomly assort letters
void Mechanics::loadLetters(){
    //Randomly assort the RIGHT letters into the map
    srand ( time(NULL) );
    for(int i = 0; i < theWord.length(); i++){

        int randomY = rand() % 18;
        int randomX = rand() % 38;

        if(aLetter(map[randomY][randomX]) || map[randomY][randomX] == '|' || map[randomY][randomX] == '-'){
           while(aLetter(map[randomY][randomX])){
                int randomY = rand() % 18;
                int randomX = rand() % 38;
                if(map[randomY][randomX] == ' '){
                    map[randomY][randomX] = theWord[i];
                }
            }
        }else{
           map[randomY][randomX] = theWord[i];
        }

        //map[randomY][randomX] = theWord[i];
    }
    //Randomly assort ALL letters into the map
    for(int i = 0; i < 25; i++){
        int randomY = rand() % 18;
        int randomX = rand() % 38;

        if(aLetter(map[randomY][randomX]) || map[randomY][randomX] == '|' || map[randomY][randomX] == '-'){
           while(aLetter(map[randomY][randomX])){
                srand ( time(NULL) );
                int randomY = rand() % 18;
                int randomX = rand() % 38;
                if(map[randomY][randomX] == ' '){
                    map[randomY][randomX] = letters[i];
                }
            }
        }else{
           map[randomY][randomX] = letters[i];
        }
    }
}

