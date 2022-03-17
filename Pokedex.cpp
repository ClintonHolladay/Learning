// Pokedex.cpp
// partial edit to white space deletion

// TODO:
// distribute inputTextFormat()
 for(int i = 0; i < input.length(); i++)
 {
      if(input[i] == ' ')
          {
              continue;
          }
      else
         output += input[i];
 }

 while (input[0] == ' ')
 {
     for (int i = 1; i <= input.length(); i++)
     {
         output[i - 1] = input[i];
         input = output;
     }
 }

 while (input[input.length()-1] == ' ')
 {
     string output[input.length() - 2]{};
     for (int i = input.length() - 2; i >= 0; i--)
     {
         output[i] = input[i];
         input = output;
     }
 }
 
// delete user input white spaces at the end of the input
// add data write/read to/from a file so that Pokemon can be stored from one progam run to the next

#include <iostream>
#include <string>
#include <cstdlib>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

using namespace std;

class Pokemon
{
    int m_HP{};
    string m_attack1Name;
    string m_attack2Name;
    int m_attack1{};
    int m_attack2{};
    int m_energyReq{};
    string m_stage;
    string m_name;
    string m_type;
    bool num = true;
public:
    void getPokemon();
    void setPokemon();
    string getName();
    void editPokemon();
    void inputFail(int& input);
    void inputTextFormat(string& input1);
};
void Pokemon::getPokemon()
{
    cout << endl << "\tPokemon Stats: " << endl;
    cout << "Name:     " << m_name << endl;
    cout << "Stage:    " << m_stage << endl;
    cout << "Type:     " << m_type << endl;
    cout << "HP:       " << m_HP << endl;
    cout << "Attack 1: " << m_attack1Name << " " << m_attack1 << endl;
    cout << "Attack 2: " << m_attack2Name << " " << m_attack2 << endl;
    cout << "Energy Requirments: " << m_energyReq << endl;
}
void Pokemon::setPokemon()
{
    cout << "\n\nYou are about to create a new Pokemon! Are you excited???" << endl;
    cout << "What do you want to name this Pokemon?" << endl;
    cin.ignore(256, '\n');
    inputTextFormat(m_name);
    cout << "How many Hit Points do you want " << m_name <<"to have? " << endl;
    inputFail(m_HP);
    cout << "What stage evolution will " << m_name << " be at?" << endl;
    cin.ignore(256, '\n');
    num = true;
    while (num)
    {
        num = false;
        getline(cin, m_stage);
        if (m_stage != "Basic" && m_stage != "1" && m_stage != "2")
        {
            cout << "Sorry, that is not a known Stage of Pokemon. If you have made a discovery please inform Professor Oak!" << endl;
            cout << "Please provide \"Basic\" or \"1\" or \"2\"." << endl;
            num = true;
        }
    }
    cout << "What Type will " << m_name << " be?" << endl;
    cout << "Your options are: "<< "Normal," << RED << " Fire" << RESET << "," << BLU << " Water" << RESET
         << "," << GRN << " Grass" << RESET << "," << YEL << " Electric" << RESET << ", " << CYN << "Ice" << RESET << ","
         << RED << " Fighting" << RESET << "," << GRN << " \n"<< "\tPoison" << RESET << "," << YEL << " Ground" 
         << RESET << "," << CYN << " Flying" << RESET << "," << MAG << " Psychic" << RESET << "," << GRN << " Bug"
         << RESET << "," << YEL << " Rock" << RESET << "," << MAG << " Ghost" << RESET << " and" << RED << " Dragon" << RESET << "." << endl;
    num = true;
    while (num)
    {
        num = false;
        getline(cin, m_type);
        if (m_type != "Fire" && m_type != "Water" && m_type != "Grass" && m_type != "Electric" && m_type != "Flying" 
            && m_type != "Normal" && m_type != "Ice" && m_type != "Fighting" && m_type != "Poison" && m_type != "Ground" 
            && m_type != "Psychic" && m_type != "Bug" && m_type != "Rock" && m_type != "Ghost" && m_type != "Dragon")
        {
            cout << "Sorry, that is not a known Type of Pokemon. If you have made a discovery please inform Professor Oak!" << endl;
            cout << "Please provide one of the options listed above." << endl;
            num = true;
        }
    }
    cout << m_name << " gets to have 2 attacks. What will the first one be called?" << endl;
    getline(cin, m_attack1Name);
    cout << "How much damage does " << m_attack1Name << " do?" << endl;
    inputFail(m_attack1);
    cout << "What will " << m_name << "'s second attack be called?" << endl;
    cin.ignore(256, '\n'); getline(cin, m_attack2Name);
    cout << "How much damage does " << m_attack2Name << " do?" << endl;
    inputFail(m_attack2);
    cout << "How many energies will " << m_name << " need to conduct his attacks?" << endl;
    inputFail(m_energyReq); 
}
string Pokemon::getName(){return m_name;}

void Pokemon::editPokemon()
{
    int option;
    bool editing = true;
    while (editing)
    {
        cout << "\n\t\tEDIT MENU:\n" << endl;
        cout << "\t1. Name." << endl;
        cout << "\t2. Stage." << endl;
        cout << "\t3. Type." << endl;
        cout << "\t4. HP." << endl;
        cout << "\t5. Attack 1 Name and Damage." << endl;
        cout << "\t6. Attack 2 Name and Damage." << endl;
        cout << "\t7. Energy Requirements." << endl;
        cout << "\t8. Exit Editing Menu." << endl;
        cin >> option;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Please provide a number only..." << endl;
            cout << "Lets try again... " << endl;
            continue;
        }
        switch (option)
        {
        case 1:  
            cout << "Enter the new Name: "; 
            cin.ignore(256, '\n'); getline(cin, m_name);
            break;
        case 2: 
            cout << "Enter the new Stage: ";
            cin.ignore(256, '\n'); getline(cin, m_stage);
            break;
        case 3:
            cout << "Enter the new Type: ";
            cin.ignore(256, '\n'); getline(cin, m_type);
            break;
        case 4:
            cout << "Enter the new HP: ";
            inputFail(m_HP);
            break;
        case 5:
            cout << "Enter the new Attack 1 Name: ";
            cin.ignore(256, '\n'); getline(cin, m_attack1Name);
            cout << "Enter the new Attack 1 Damage: ";
            inputFail(m_attack1);
            break;
        case 6:
            cout << "Enter the new Attack 2 Name: ";
            cin.ignore(256, '\n'); getline(cin, m_attack1Name);
            cout << "Enter the new Attack 2 Damage: ";
            inputFail(m_attack2);
            break;
        case 7:
            cout << "Enter the new Energy Requirements: ";
            inputFail(m_energyReq);
            break;
        case 8:
            editing = false;
            break;
        default: cout << "Invalid Answer!!! Try again." << endl;
        }
    }
}
void Pokemon::inputFail(int& input)
{
    num = true;
    while (num)
    {
        num = false;
        cin >> input;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Please provide a number only..." << endl;
            cout << "Lets try again... " << endl;
            num = true;
        }
    }
}
void Pokemon::inputTextFormat(string& input1)
{
    getline(cin, input1);
    for (int i = 0; i < input1.length(); i++)
    {
        input1[i] = tolower(input1[i]);
    }
    input1[0] = toupper(input1[0]);
}

int main()
{
    Pokemon* pokemon[50]{};
    int i = 0, choice;
    string search;
    string edit;
    while (1)
    {
        cout << GRN << "\n\tMAIN MENU:\n" << RESET << endl;
        cout << "1. Create new Pokemon." << endl;
        cout << "2. Search for a Pokemon." << endl;
        cout << "3. Edit info for a Pokemon." << endl;
        cout << "4. Exit." << endl;
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Please provide a number only..." << endl;
            cout << "Lets try again... " << endl;
            continue;
        }
        switch (choice)
        {
        case 1: pokemon[i] = new Pokemon();
            pokemon[i]->setPokemon();
            i++;
            system("CLS");
            break;
        case 2: 
            if (i == 0)
            {
                cout << "There are no Pokemon in the database. Please add a Pokemon to search." << endl;
                break;
            }
            else
            {
                cout << "Please enter the Pokemon name you are looking for." << endl;
                cin.ignore(256, '\n'); getline(cin, search);
                // pokemon[i]->inputTextFormat(search);
                for (int j = 0; j < i; j++)
                {
                    if (pokemon[j]->getName() == search)
                    {
                        cout << "\nWe found it!!" << endl;
                        pokemon[j]->getPokemon();
                        break;
                    }
                    else if (j == i - 1)
                    {
                        cout << "No Pokemon by this name was found in our database... Press ENTER to Continue." << endl;
                        cin.get();
                        system("CLS");
                        break;
                    }
                }
            }
            break;
        case 3:
            if (i == 0)
            {
                cout << "There are no Pokemon in the database. Please add a Pokemon to search." << endl;
                break;
            }
            else
            {
                cout << "Please enter the Pokemon name you want to edit info for." << endl;
                cin.ignore(256, '\n'); getline(cin, edit);
                for (int k = 0; k < i; k++)
                {
                    if (pokemon[k]->getName() == edit)
                    {
                        cout << "\nWe found it!!" << endl;
                        cout << "This Pokemon's current info is:\n" << endl;
                        pokemon[k]->getPokemon();
                        cout << "You may now choose different info.\n" << endl;
                        pokemon[k]->editPokemon();
                        break;
                    }
                    else if (k == i - 1)
                    {
                        cout << "No Pokemon by this name was found in our database..." << endl;
                        break;
                    }
                }
            }
            break;
        case 4: 
            cout << "GOODBYE!!!" << endl;
            exit(0);
        default: cout << "Invalid Answer!!! Try again." << endl;
        }
    }
}
