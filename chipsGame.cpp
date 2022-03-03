#include <iostream> 
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std; 
 
const float MAX_TURN = .5;
const int MAX_CHIPS = 100;
bool player1Turn = true;
bool gameOver = false;
bool continueGame = true;
int chipsInPile = 0;
int chipsTaken = 0;
int player1Wins = 0;
int computerWins =0;

string playerName;

void introduction();
void gameLoop();
void playAgain();

int main()  
{ 
    while (continueGame)
    {
        ifstream inputFile;
        inputFile.open("PlayerCount.txt");
        if (!inputFile.fail())
        {
            inputFile >> player1Wins;
        }
        inputFile.close();

        ifstream inputFile2;
        inputFile.open("ComputerCount.txt");
        if (!inputFile.fail())
        {
            inputFile >> computerWins;
        }
        inputFile.close();

        srand(time(0));
        introduction();
        gameLoop();
        playAgain();     
    }
    cout << "Goodbye!! Thanks for playing!!" << endl;  
  return 0; 
} 

                            //Function Definitions//
//================================================================================//

void introduction()
{
    cout << "CHIP GAME!!!\n\nYou will compete against the computer to take the last chip.";
    cout << "The most you can take is 1/2 of the available chips." << endl;
    cout << "Player 1, please enter your name: ";
    cin >> playerName;
    cout << "\nThanks and good luck!" << endl << endl;
    chipsInPile = (rand() % MAX_CHIPS) + 1;
    cout << "This round will start with " << chipsInPile << " chips in the pile\n";
}

void gameLoop()
{
    gameOver = false;
    while (!gameOver)
    {
        int maxToTake = MAX_TURN * chipsInPile;
        cout << maxToTake << " Chips can be taken from the pile." << endl;
        int playerTaken = 0;
        if (player1Turn)
        {
            cout << "How many chips would you like to take?" << endl;
            cin >> playerTaken;
            if (playerTaken > maxToTake)
            {
                cout << "Your took to many, try again..." << endl << endl;
                continue;
            }
            else
            {
                chipsInPile -= playerTaken;
                cout << "There are " << chipsInPile << " chips left." << endl << endl;
                player1Turn = false;
            }
        }
        else
        {
            int computerTaken = (rand() % maxToTake) + 1;
            cout << "The computer took " << computerTaken << " chips." << endl << endl;
            chipsInPile -= computerTaken;
            cout << "There are " << chipsInPile << " chips left." << endl << endl;
            player1Turn = true;
        }
        if (chipsInPile == 1)
        {
            gameOver = true;
            if (player1Turn)
            {
                cout << playerName << " WON!!!" << endl;
                player1Wins++;
                cout << playerName << " has won " << player1Wins << " times!!" << endl;
                ofstream outputFile;
                outputFile.open("PlayerCount.txt");
                if (!outputFile.fail())
                {
                    outputFile << player1Wins;
                }
                outputFile.close();
            }
            else
            {
                cout << "The Computer WON!!!" << endl;
                computerWins++;
                cout <<"The Computer has won " << computerWins << " times :( :(" << endl;
                ofstream outputFile;
                outputFile.open("ComputerCount.txt");
                if (!outputFile.fail())
                {
                    outputFile << computerWins;
                }
                outputFile.close();
            }
        }
    }
    cout << "GAME OVER!!" << endl << endl;
}

void playAgain()
{
    char game;
    cout << "Would you like to play again? Type \"Y\" for yes and \"N\" for no." << endl;
    bool validAnswer = true;
    while (validAnswer)
    {
        cin >> game;
        if (game == 'Y')
        {
            continueGame = true;
            validAnswer = false;
        }
        else if (game == 'N')
        {
            continueGame = false;
            validAnswer = false;
        }
        else
            cout << "Invalid input! try again..." << endl;
    }
}