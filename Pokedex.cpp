// Pokedex.cpp

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Pokemon
{
    int m_HP;
    string m_attack1Name;
    string m_attack2Name;
    int m_attack1;
    int m_attack2;
    int m_energyReq;
    int m_energyCounter;
    string m_stage;
    string m_name;
    string m_type;
    

public:
    //Pokemon();
    /*Pokemon(int hp, string attack1Name, string attack2Name, int Attack1, int Attack2, string Stage, string Name, string Type, int EnergyReq)
    {
        hp = m_HP, Attack1 = m_attack1, Attack2 = m_attack2, Stage = m_stage, Name = m_name, Type = m_type, EnergyReq = m_energyReq;
    }*/
    void getPokemon();
    void setPokemon();
    string getName();
    //~Pokemon();

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
    cout << "You are about to create a new Pokemon! Are you excited???" << endl;
    cout << "What do you want to name this Pokemon?" << endl;
    cin.ignore(); getline(cin, m_name);
    cout << "How many Hit Points do you want " << m_name <<" to have? " << endl;
    cin >> m_HP;
    cout << "What stage evolution will " << m_name << " be at?" << endl;
    cin >> m_stage;
    cout << "What Type will " << m_name << " be?" << endl;
    cin >> m_type;
    cout << m_name << " gets to have 2 attacks. What will the first one be called?" << endl;
    cin.ignore(); getline(cin, m_attack1Name);
    cout << "How much damage does " << m_attack1Name << " do?" << endl;
    cin >> m_attack1;
    cout << "What will " << m_name << "'s second attack be called?" << endl;
    cin.ignore(); getline(cin, m_attack2Name);
    cout << "How much damage does " << m_attack2Name << " do?" << endl;
    cin >> m_attack2;
    cout << "How many energies will " << m_name << " need to conduct his attacks?" << endl;
    cin >> m_energyReq;
}
string Pokemon::getName()
{
    return m_name;
}


int main()
{
    Pokemon* pokemon[50];
    int i = 0, choice;
    string search1;
    string search2;
    while (1)
    {
        cout << "\n\tMENU:\n" << endl;
        cout << "1. Create new Pokemon." << endl;
        cout << "2. Search for a Pokemon." << endl;
        cout << "3. Edit info for a Pokemon." << endl;
        cout << "4. Exit." << endl;
        cin >> choice;

        switch (choice)
        {
        case 1: pokemon[i] = new Pokemon();
            pokemon[i]->setPokemon();
            i++;
            system("CLS");
            break;
        case 2: 
            cout << "Please enter the Pokemon name you are looking for." << endl;
            cin.ignore(); getline(cin, search1);
            for (int j = 0; j < i; j++)
            {
                if (pokemon[j]->getName() == search1)
                {
                    cout << "\nWe found it!!" << endl;
                    pokemon[j]->getPokemon();
                    break;
                }
                else if (j == i-1)
                {
                    cout << "No Pokemon by this name was found in our database..." << endl;
                    break;
                }
            }
            break;
        case 3:
            cout << "Please enter the Pokemon name you want to edit info for." << endl;
            cin.ignore(); getline(cin, search2);
            for (int k = 0; k < i; k++)
            {
                if (pokemon[k]->getName() == search2)
                {
                    cout << "\nWe found it!!" << endl;
                    cout << "This Pokemon's current info is:\n" << endl;
                    pokemon[k]->getPokemon();
                    cout << "You many now choose different info.\n" << endl;
                    pokemon[k]->setPokemon();
                    break;
                }
                else if (k == i-1)
                {
                    cout << "No Pokemon by this name was found in our database..." << endl;
                    break;
                }
            }
            break;
        case 4: 
            cout << "GOODBYE!!!" << endl;
            exit(0);
        defaut: cout << "Invalid Answer!!! Try ahain." << endl;

        };

    }



}
