#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void HasntGuessedWord(string& rUser, int& rWrongSoFar, int& rMaxWrong, string& rSoFar, string& rTheWord, string& rUsedLetters) {
    while ((rWrongSoFar < rMaxWrong) && (rSoFar != rTheWord)) {
        //     Tell recruit how many incorrect guesses he or she has left
        cout << "You have " << (rMaxWrong - rWrongSoFar) << " guesses left" << endl;

        //     Show recruit the letters he or she has guessed
        cout << "You've used these leters: " << rUsedLetters << endl;

        //     Show player how much of the secret word he or she has guessed
        cout << "So far, this is what you know about the word: " << rSoFar << endl;

        //     Get recruit's next guess
        char guess;
        cout << "Enter your guess: ";
        cin >> guess;
        guess = tolower(guess);

        //     While recruit has entered a letter that he or she has already guessed
        while (rUsedLetters.find(guess) != string::npos) {
            //          Get recruit ’s guess
            cout << "You already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = tolower(guess);
        }
        //     Add the new guess to the group of used letters
        rUsedLetters += guess;

        //     If the guess is in the secret word
        if (rTheWord.find(guess) != string::npos)
        {
            //          Tell the recruit the guess is correct
            cout << "That's correct, Good job " << rUser << endl;

            //          Update the word guessed so far with the new letter
            for (int i = 0; i < rTheWord.length(); ++i) {
                if (rTheWord[i] == guess) {
                    rSoFar[i] = guess;
                }
            }
            if (rSoFar == rTheWord)
            {
                cout << "The word was " << rTheWord << endl;
            }
        }
        //     Otherwise
        else
        {
            //          Tell the recruit the guess is incorrect
            cout << "No, that's incorrect, try again " << rUser << endl;
            //          Increment the number of incorrect guesses the recruit has made
            rWrongSoFar++;
        }
        cout << "------------------------------------------------------------------------------------------------" << endl;
    }
}