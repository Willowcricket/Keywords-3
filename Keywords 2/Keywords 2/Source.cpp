#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "DisplayOverview.h"
#include "MainGameLoop.h"
#include "MistakeCheck.h"

using namespace std;

//Prototypes



int main() {
    srand(time(NULL));

    // Display Title of the program to the user
    cout << "Welcome to the Keyword Spy Program!" << endl;

    // Ask the recruit to log in using their name
    cout << "Who's useing this program?" << endl;
    cout << "Username: ";

    // Hold the recruit's name in a var, and address them by it throughout the simulation.
    string user;
    cin >> user;
    cout << "Welcome, " << user << endl;

    Overview(user);

    // Create a collection of 10 words you had written down manually
    const string keywords[10] = { "agent", "detective", "informer", "investigator", "mole", "operative", "plant", "sleeper", "sleuth", "snoop" };

    // Create an int var to count the number of simulations being run starting at 1
    int simulationCount = 1;

    char again = 'N';
    do {
        // Display the simulation # is starting to the recruit. 
        cout << "Simulation number " << simulationCount << " is now starting" << endl;

        // Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
        int randomIndex = rand() % 10;
        string kW = keywords[randomIndex];
        
        int maxWrong = 8;
        int wrongSoFar = 0;
        string theWord = kW;
        string soFar(theWord.size(), '-');
        string usedLetters = " ";

        // While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
        HasntGuessedWord(user, wrongSoFar, maxWrong, soFar, theWord, usedLetters);

        // If the recruit has made too many incorrect guesses
        CheckMistakes(wrongSoFar, maxWrong);

        // Ask the recruit if they would like to run the simulation again
        cout << "Would you like to run the simulation agin? Y/N? ";
        cin >> again;
        again = toupper(again);

        // If the recruit wants to run the simulation again
        if (again == 'Y') {
            //     Increment the number of simulations ran counter
            simulationCount++;
        }
        //     Move program execution back up to // Display the simulation # is starting to the recruit. 
    } while (again == 'Y');

    // Otherwise 
    if (again == 'N')
    {
        //     Display End of Simulations to the recruit
        cout << "Ending Simulation" << endl;
        //     Pause the Simulation with press any key to continue
        system("pause");
    }

    return 0;
}