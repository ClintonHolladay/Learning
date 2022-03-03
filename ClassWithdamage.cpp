#include <iostream>

using namespace std;

class Character
{
    int health;
public:
    Character() { health = 100; }
    Character(int i){health = i;}
    int printHealth(){return health;}
    void takeDamage(int damage) { health -= damage; }
    int askPlayer()
    {
        int hurt;
        cout << "How much damage do you want to inflict?" << endl;
        cin >> hurt;
        return hurt;

    }
};

int main() 
{
    Character* zelda = new Character(1000);
    cout<<"Your health is currently at: "<< zelda->printHealth() << endl;
    cout << "============================================" << endl;
    cout << "You are about to take damage!!!" << endl;
    zelda->takeDamage(zelda->askPlayer());
    if (zelda->printHealth() > 0)
    {
        cout << "You got hit!!!" << endl;
        cout << "============================================" << endl;
        cout << "Your health is now only: " << zelda->printHealth() << "!!!!!!! You are Damaged!" << endl;
    }
    else
        cout << "You are dead!!!!" << endl;

    delete zelda;
    return 0;
}
