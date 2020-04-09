#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void CheckMistakes(int& rWrongSoFar, int& rMaxWrong) {
    if (rWrongSoFar == rMaxWrong)
    {
        //     Tell the recruit that he or she has failed the Keywords II course.
        cout << "You have failed the simulation" << endl;
        // Otherwise
    }
    else
    {
        //     Congratulate the recruit on guessing the secret words
        cout << "Congratulations, You've completed the simulation" << endl;
    }
}