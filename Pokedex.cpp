// Pokedex.cpp
// began file creation 3 started loop in fill more than one pokemon. 


// TODO:
// add data write/read to/from a file so that Pokemon can be stored from one progam run to the next
// pokedex full f() needs to be completed...

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

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
    int pokemonNum{};
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
    Pokemon(){};
    void getPokemon();
    void setPokemon();
    string getName();
    string getStage();
    string getType();
    int getHP();
    string getAttack1Name();
    int getAttack1Damage();
    string getAttack2Name();
    int getAttack2Damage();
    int getEnergyReq();
    void editPokemon();
    void inputFail(int& input);
    void inputTextFormat(string& input1);
    void readFromFile(unsigned short& i);
};
void Pokemon::getPokemon()
{
    cout << endl << "\tPokemon Stats: " << endl;
    cout << "Name:     " << m_name << endl;
    cout << "Stage:    " << m_stage << endl;
    cout << "Type:     " << m_type << endl;
    cout << "HP:       " << m_HP << endl;
    cout << "Attack 1: " << m_attack1Name << " Damage: " << m_attack1 << endl;
    cout << "Attack 2: " << m_attack2Name << " Damage: " << m_attack2 << endl;
    cout << "Energy Requirments: " << m_energyReq << endl;
}
void Pokemon::setPokemon()
{
    system("CLS");
    cout << "\tPOKEMON CREATION!!!";
    cout << "\n\nYou are about to create a new Pokemon! Are you excited???" << endl;
    cout << "\nWhat do you want to name this Pokemon?" << endl;
    cin.ignore(256, '\n');
    inputTextFormat(m_name);
    cout << "\nHow many Hit Points do you want " << m_name <<" to have? " << endl;
    inputFail(m_HP);
    cout << "\nWhat stage evolution will " << m_name << " be at?" << endl;
    cin.ignore(256, '\n');
    num = true;
    while (num)
    {
        num = false;
        inputTextFormat(m_stage);
        if (m_stage != "Basic" && m_stage != "1" && m_stage != "2")
        {
            cout << endl << "Sorry, that is not a known Stage of Pokemon. If you have made a discovery please inform Professor Oak!" << endl;
            cout << "Please provide \"Basic\" or \"1\" or \"2\"." << endl;
            num = true;
        }
    }
    cout << "\nWhat Type will " << m_name << " be?" << endl;
    cout << "Your options are: "<< "Normal," << RED << " Fire" << RESET << "," << BLU << " Water" << RESET
         << "," << GRN << " Grass" << RESET << "," << YEL << " Electric" << RESET << ", " << CYN << "Ice" << RESET << ","
         << RED << " Fighting" << RESET << "," << GRN << " \n"<< "\tPoison" << RESET << "," << YEL << " Ground" 
         << RESET << "," << CYN << " Flying" << RESET << "," << MAG << " Psychic" << RESET << "," << GRN << " Bug"
         << RESET << "," << YEL << " Rock" << RESET << "," << MAG << " Ghost" << RESET << " and" << RED << " Dragon" << RESET << "." << endl;
    num = true;
    while (num)
    {
        num = false;
        inputTextFormat(m_type);
        if (m_type != "Fire" && m_type != "Water" && m_type != "Grass" && m_type != "Electric" && m_type != "Flying" 
            && m_type != "Normal" && m_type != "Ice" && m_type != "Fighting" && m_type != "Poison" && m_type != "Ground" 
            && m_type != "Psychic" && m_type != "Bug" && m_type != "Rock" && m_type != "Ghost" && m_type != "Dragon")
        {
            cout << endl << "Sorry, that is not a known Type of Pokemon. If you have made a discovery please inform Professor Oak!" << endl;
            cout << "Please provide one of the options listed above." << endl;
            num = true;
        }
    } 
    cout << endl << m_name << " gets to have 2 attacks. What will the first one be called?" << endl;
    inputTextFormat(m_attack1Name);
    cout << "\nHow much damage does " << m_attack1Name << " do?" << endl;
    inputFail(m_attack1);
    cout << "\nWhat will " << m_name << "'s second attack be called?" << endl;
    cin.ignore(256, '\n'); inputTextFormat(m_attack2Name);
    cout << "\nHow much damage does " << m_attack2Name << " do?" << endl;
    inputFail(m_attack2);
    cout << "\nHow many energies will " << m_name << " need to conduct his attacks?" << endl;
    inputFail(m_energyReq); 
}

string Pokemon::getName(){return m_name;}
string Pokemon::getStage() { return m_stage; }
string Pokemon::getType() { return m_type; }
int Pokemon::getHP() { return m_HP; }
string Pokemon::getAttack1Name() { return m_attack1Name; }
int Pokemon::getAttack1Damage() { return m_attack1; }
string Pokemon::getAttack2Name() { return m_attack2Name; }
int Pokemon::getAttack2Damage() { return m_attack2; }
int Pokemon::getEnergyReq() { return m_energyReq; }

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
            cout << endl << "Please provide a number only. Lets try again..." << endl;
            continue;
        }
        switch (option)
        {
        case 1:  
            cout << "Enter the new Name: "; 
            cin.ignore(256, '\n'); inputTextFormat(m_name);
            break;
        case 2: 
            cout << "Enter the new Stage: ";
            cin.ignore(256, '\n');
            num = true;
            while (num)
            {
                num = false;
                inputTextFormat(m_stage);
                if (m_stage != "Basic" && m_stage != "1" && m_stage != "2")
                {
                    cout << "Sorry, that is not a known Stage of Pokemon. If you have made a discovery please inform Professor Oak!" << endl;
                    cout << "Please provide \"Basic\" or \"1\" or \"2\"." << endl;
                    num = true;
                }
            }
            break;
        case 3:
            cout << "Enter the new Type: " << endl;
            cin.ignore(256, '\n');
            cout << "Your options are: " << "Normal," << RED << " Fire" << RESET << "," << BLU << " Water" << RESET
                << "," << GRN << " Grass" << RESET << "," << YEL << " Electric" << RESET << ", " << CYN << "Ice" << RESET << ","
                << RED << " Fighting" << RESET << "," << GRN << " \n" << "\tPoison" << RESET << "," << YEL << " Ground"
                << RESET << "," << CYN << " Flying" << RESET << "," << MAG << " Psychic" << RESET << "," << GRN << " Bug"
                << RESET << "," << YEL << " Rock" << RESET << "," << MAG << " Ghost" << RESET << " and" << RED << " Dragon" << RESET << "." << endl;
            num = true;
            while (num)
            {
                num = false;
                inputTextFormat(m_type);
                if (m_type != "Fire" && m_type != "Water" && m_type != "Grass" && m_type != "Electric" && m_type != "Flying"
                    && m_type != "Normal" && m_type != "Ice" && m_type != "Fighting" && m_type != "Poison" && m_type != "Ground"
                    && m_type != "Psychic" && m_type != "Bug" && m_type != "Rock" && m_type != "Ghost" && m_type != "Dragon")
                {
                    cout << "Sorry, that is not a known Type of Pokemon. If you have made a discovery please inform Professor Oak!" << endl;
                    cout << "Please provide one of the options listed above." << endl;
                    num = true;
                }
            }
            break;
        case 4:
            cout << "Enter the new HP: ";
            inputFail(m_HP);
            break;
        case 5:
            cout << "Enter the new Attack 1 Name: ";
            cin.ignore(256, '\n'); inputTextFormat(m_attack1Name);
            cout << "Enter the new Attack 1 Damage: ";
            inputFail(m_attack1);
            break;
        case 6:
            cout << "Enter the new Attack 2 Name: ";
            cin.ignore(256, '\n'); inputTextFormat(m_attack1Name);
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
        default: cout << endl << "Invalid Answer!!! Try again." << endl;
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
            cout << endl << "Please provide a number only. Lets try again..." << endl;
            num = true;
        }
        if (input < 0)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << endl << "Please provide a positive number. Lets try again..." << endl;
            num = true;
        }
    }
}
void Pokemon::inputTextFormat(string& input1)
{
    getline(cin, input1);
    while (input1[0] == ' ')
    {
        input1.erase(0, 1);
    }
    while (input1.back() == ' ')
    {
        input1.erase(input1.end() - 1);
    }
    for (int i = 0; i < input1.length(); i++)
    {
        input1[i] = tolower(input1[i]);
    }
    input1[0] = toupper(input1[0]);
    for (int p = 1; p < input1.length(); p++)
    {
        if (input1[p - 1] == ' ')
        {
            input1[p] = toupper(input1[p]);
        } 
    }
}
void Pokemon::readFromFile(unsigned short&i)
{
    ifstream pokemonFile;
    pokemonFile.open("PokemonDatabase.txt");
    // skip lines =to a multiple of i
    for (int n = 1; n <= (9 * i); n++)
    {
        pokemonFile.ignore(256, '\n');
        if ((n % 9) == 0) cout << "We have skipped " << n / 9 << " Pokemon." << endl;
    }
    if (pokemonFile.is_open())
    {
        cout << "Reading from the file into variables NOW." << endl;
        getline(pokemonFile, m_name);
        cout << m_name << endl;
        pokemonFile >> m_stage;
        cout << m_stage << endl;
        pokemonFile >> m_type;
        cout << m_type << endl;
        pokemonFile >> m_HP;
        cout << m_HP << endl;
        pokemonFile >> m_attack1Name;
        cout << m_attack1Name << endl;
        pokemonFile >> m_attack1;
        cout << m_attack1 << endl;
        pokemonFile >> m_attack2Name;
        cout << m_attack2Name << endl;
        pokemonFile >> m_attack2;
        cout << m_attack2 << endl;
        pokemonFile >> m_energyReq;
        cout << m_energyReq << endl;
        pokemonFile.close();
        i++;
    }
    else
    {
        cout << "pokemonFile failed to open" << endl;
    }
}

int main()
{
    const int MAX {152};
    Pokemon* pokemon[MAX]{};
    //pokemon[MAX-1] = NULL;??
    fstream pokemonFile1;
    unsigned short i = 0, choice{};
    string search;
    string edit;
    unsigned short counter = 0;
    cout << "Starting to read pokemon data into array." << endl;

    ifstream pokemonReadFile;
    pokemonReadFile.open("PokemonDatabase.txt");
    int pokemonNum{};
    while (!pokemonReadFile.eof())
    {
        getline(pokemonReadFile, name);
        pokemonReadFile >> stage;
        pokemonReadFile >> type;
        pokemonReadFile >> HP;
        pokemonReadFile >> attack1Name;
        pokemonReadFile >> attack1;
        pokemonReadFile >> attack2Name;
        pokemonReadFile >> attack2;
        pokemonReadFile >> energyReq;
        pokemonNum++;
        //read the # of lines from file
    }
    pokemonReadFile.close();

    while ()
    {
        pokemon[i] = new Pokemon();
        pokemon[i]->readFromFile(i);
        counter++;
        /*pokemon[i] = new Pokemon();
        pokemon[i]->readFromFile(i);*/
    }
    
    while (1)
    {
        // pokedex full f() needs to be completed...
        if (i >= 151)
        {
            cout << "The Pokedex is full!" << endl;
            return 0;
        }

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
            cout << endl << "Please provide a number only. Lets try again..." << endl;
            continue;
        }
        switch (choice)
        {
        case 1: 
            pokemon[i] = new Pokemon();
            pokemon[i]->setPokemon();
            pokemonFile1.open("PokemonDatabase.txt", ios::app);
            if (pokemonFile1.fail())
            {
                cout << "pokemonFile failed to open" << endl;
            }
            else
            {
                // pokemonFile1 << i + 1 << endl;
                pokemonFile1 << pokemon[i]->getName() << endl;
                pokemonFile1 << pokemon[i]->getStage() << endl;
                pokemonFile1 << pokemon[i]->getType() << endl;
                pokemonFile1 << pokemon[i]->getHP() << endl;
                pokemonFile1 << pokemon[i]->getAttack1Name() << endl;
                pokemonFile1 << pokemon[i]->getAttack1Damage() << endl;
                pokemonFile1 << pokemon[i]->getAttack2Name() << endl;
                pokemonFile1 << pokemon[i]->getAttack2Damage() << endl;
                pokemonFile1 << pokemon[i]->getEnergyReq() << endl; 
            }
            pokemonFile1.close();
            i++;
            system("CLS");
            break;
        case 2: 
            if (i == 0)
            {
                cout << "There are no Pokemon in the database. Please add a Pokemon before attempting a search." << endl;
                break;
            }
            else
            {
                cout << "Please enter the Pokemon name you are looking for." << endl;
                cin.ignore(256, '\n');
                pokemon[i]->inputTextFormat(search);
                for (int j = 0; j < i; j++)
                {
                    if (pokemon[j]->getName() == search)
                    {
                        cout << "\n**********\nWe found it!!\n**********" << endl;
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
                cout << "There are no Pokemon in the database. Please add a Pokemon before attempting to edit." << endl;
                break;
            }
            else
            {
                cout << "Please enter the Pokemon name you want to edit info for." << endl;
                cin.ignore(256, '\n'); pokemon[i]->inputTextFormat(edit);
                for (int k = 0; k < i; k++)
                {
                    if (pokemon[k]->getName() == edit)
                    {
                        cout << "\n**********\nWe found it!!\n**********" << endl;
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
        default: cout << endl << "Invalid Answer!!! Try again." << endl;
        }
    }
}
