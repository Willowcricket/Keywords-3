#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Overview(string& rUser) {
    char start = 'N';
    do
    {
        // Display an overview of what Keywords II is to the recruit 
        cout << "This program is to train our recruits to detect and decode these low tech scrambled keywords" << endl;

        // Display directions to the recruit on how to use Keywords
        cout << "Your job, " << rUser << ", is to decode these phases that could possibly identify a spy in our system" << endl;
        cout << "Do you understand and want to continue? Y/N: ";
        cin >> start;
        start = toupper(start);
    } while (start != 'Y');
}