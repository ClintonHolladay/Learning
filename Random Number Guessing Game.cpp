// Random Number Guessing Game.cpp 

#include <iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;

int main()
{
    bool numberNOTguessed = true;
    srand(time(NULL));
    int randNum = rand() % 100 + 1;
    int guess = 0;
    cout << "This is a random # GAME!!!!!\n" << endl;

    cout << "Please guess a random number and then hit the ENTER key.";
    do
    {
        cin >> guess;
        if (guess == randNum)
        {
            numberNOTguessed = false;
            cout << "Congratulations!!!!! You WIN!!!!" << endl;            
        }
        else if (guess > randNum)
            cout << "You guessed high. Try AGAIN!!!" << endl;
        else if (guess < randNum)
            cout << "You guessed low. Try AGAIN!!!" << endl;
        else
            cout << "try again something went wrong..." << endl;

    } while (numberNOTguessed);
}


