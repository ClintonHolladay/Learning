#include <iostream> 
#include <ctime>
#include <cstdlib>
#include <fstream>
#include<string>

using namespace std;

const float MAX_TURN = .5;
const int MAX_CHIPS = 100;
bool player1Turn = true;
bool gameOver = false;
bool continueGame = true;
int chipsInPile = 0;
int chipsTaken = 0;
int player1Wins = 0;
int computerWins = 0;

string playerName;

//Function Declarations//
//================================================================================//
void introduction();
void gameLoop();
void playAgain();

int main()
{
    bool accessGranted = false;
    int choice;
    int counter = 0;
    string username;
    string password;
    string passwordTry;
    string usernameTry;
    cout << "Please login to access the game. If you have not registered you will need to register before you can login.\n" << endl;
    cout << "Choose an option: " << endl;
    cout << "1: Register.\n2: Login." << endl;
    while (!accessGranted)
    {
        bool invalidAnswer = true;
        while (invalidAnswer)
        {
            cin >> choice;
            if (choice == 1)
            {
                invalidAnswer = false;
                cout << "Your username & password can be any arragnment of numbers, characters, or words." << endl;
                cout << "Enter your username: " << endl;
                cin.ignore();
                getline(cin, username);
                //cin >> username;
                cout << "Enter your password: " << endl;
                getline(cin, password);
                //cin >> password;
                system("CLS");

                ofstream registerFile;
                registerFile.open("username.txt");
                if (registerFile.fail())
                {
                    cout << "Register file username failed to open." << endl;
                }
                else
                {
                    registerFile << username << endl;
                }
                registerFile.close();

                registerFile.open("password.txt");
                if (registerFile.fail())
                {
                    cout << "Register file password failed to open." << endl;
                }
                else
                {
                    registerFile << password << endl;;
                }
                registerFile.close();

                cout << "Thank you for registering! You are able to login now.\n" << endl;
                cout << "Choose an option: " << endl;
                cout << "1: Register.\n2: Login." << endl;

                //accessGranted = true;
            }
            else if (choice == 2)
            {
                invalidAnswer = false;
                cout << "Please enter your username: " << endl;
                cin.ignore();
                getline(cin, usernameTry);
                //cin >> usernameTry;
                cout << "Please enter your password: " << endl;
                getline(cin, passwordTry);
                //cin >> passwordTry;
                string un;
                string pw;
                ifstream loginFile;
                loginFile.open("username.txt");
                if (loginFile.fail())
                {
                    cout << "Login username file failed to open." << endl;
                }
                else
                {
                    getline(loginFile, un);
                    //loginFile >> un;
                }
                loginFile.close();

                loginFile.open("password.txt");
                if (loginFile.fail())
                {
                    cout << "Login password file failed to open." << endl;
                }
                else
                {
                    getline(loginFile, pw);
                    //loginFile >> pw;
                }
                loginFile.close();

                if (un == usernameTry && pw == passwordTry)
                {
                    accessGranted = true;
                    system("CLS");
                }
                else
                {
                    accessGranted = false;
                    cout << "Your credentials don't match the saved file data. You have not been granted access. Try again.\n" << endl;
                    cout << "Choose an option: " << endl;
                    cout << "1: Register.\n2: Login." << endl;
                    invalidAnswer = true;
                    counter++;
                    if (counter > 2)
                    {
                        cout << "\n\n*****To many login attempts have been made... Access DENIED.*****\n\n" << endl;
                        return 0;
                    }
                }
            }
            else
            {
                cout << "You entered an invalid answer... Please try again." << endl;
                invalidAnswer = true;
            }
        }

    }


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
        cout <<"*****"<< maxToTake << "***** Chips can be taken from the pile." << endl;
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
                cout << "The Computer has won " << computerWins << " times :( :(" << endl;
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
            system("CLS");
        }
        else if (game == 'N')
        {
            continueGame = false;
            validAnswer = false;
            system("CLS");
        }
        else
            cout << "Invalid input! try again..." << endl;
    }
}

