
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Combatant
{
public:
    string name;
    int health;
    int attackPower;

    Combatant *prev;
    Combatant *next;

    Combatant(string n, int h, int a)
    {
        name = n;
        health = h;
        attackPower = a;
        prev = next = NULL;
    }
};

class Team
{
public:
    Combatant *head;
    Combatant *tail;

    Team()
    {
        head = tail = NULL;
    }

    void add(Combatant *c)
    {
        if (head == NULL)
            head = tail = c;
        else
        {
            tail->next = c;
            c->prev = tail;
            tail = c;
        }
    }

    bool empty()
    {
        return head == NULL;
    }

    Combatant *find(string name)
    {
        Combatant *temp = head;

        while (temp != NULL)
        {
            if (temp->name == name)
                return temp;

            temp = temp->next;
        }

        return NULL;
    }

    Combatant *find(int pos)
    {
        Combatant *temp = head;

        for (int i = 1; temp != NULL; i++)
        {
            if (i == pos)
                return temp;

            temp = temp->next;
        }

        return NULL;
    }

    void remove(Combatant *c)
    {
        if (c == NULL)
            return;

        if (c == head)
            head = c->next;

        if (c == tail)
            tail = c->prev;

        if (c->prev != NULL)
            c->prev->next = c->next;

        if (c->next != NULL)
            c->next->prev = c->prev;

        delete c;
    }

    void display()
    {
        Combatant *temp = head;

        while (temp != NULL)
        {
            cout << temp->name << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    int totalHealth()
    {
        int total = 0;
        Combatant *temp = head;

        while (temp != NULL)
        {
            total += temp->health;
            temp = temp->next;
        }

        return total;
    }

    void details()
    {
        Combatant *temp = head;

        while (temp != NULL)
        {
            cout << temp->name << " "
                 << temp->health << " "
                 << temp->attackPower << endl;

            temp = temp->next;
        }
    }
};

Combatant *choose(Team &t)
{
    int choice;

    cout << "1. Position  2. Name: ";
    cin >> choice;

    if (choice == 1)
    {
        int pos;
        cin >> pos;
        return t.find(pos);
    }
    else
    {
        string name;
        cin >> name;
        return t.find(name);
    }
}

void attack(Team &enemy,
            Combatant *attacker,
            Combatant *target)
{
    int damage =
        attacker->attackPower *
        (rand() % 3 + 1);

    target->health -= damage;

    cout << attacker->name
         << " attacks "
         << target->name << endl;

    if (target->health <= 0)
    {
        cout << target->name << " defeated!\n";
        enemy.remove(target);
    }
}

void battle(Team &heroes, Team &enemies)
{
    for (int round = 1;
         round <= 10 &&
         !heroes.empty() &&
         !enemies.empty();
         round++)
    {
        cout << "\nRound " << round << endl;

        cout << "Heroes: ";
        heroes.display();

        cout << "Enemies: ";
        enemies.display();

        // Hero turn
        cout << "Hero attacker: ";
        Combatant *h = choose(heroes);

        cout << "Enemy target: ";
        Combatant *e = choose(enemies);

        if (h && e)
            attack(enemies, h, e);

        if (enemies.empty())
            break;

        // Enemy turn
        cout << "Enemy attacker: ";
        e = choose(enemies);

        cout << "Hero target: ";
        h = choose(heroes);

        if (e && h)
            attack(heroes, e, h);
    }

    cout << "\n========== RESULT ==========\n";

    if (heroes.empty())
    {
        cout << "Enemies Win!\n";
        enemies.details();
    }
    else if (enemies.empty())
    {
        cout << "Heroes Win!\n";
        heroes.details();
    }
    else
    {
        int h = heroes.totalHealth();
        int e = enemies.totalHealth();

        if (h > e)
        {
            cout << "Heroes Win!\n";
            heroes.details();
        }
        else if (e > h)
        {
            cout << "Enemies Win!\n";
            enemies.details();
        }
        else
        {
            cout << "Draw!\n";
            cout << "Heroes:\n";
            heroes.details();

            cout << "Enemies:\n";
            enemies.details();
        }
    }
}

// ================= MAIN =================

int main()
{
    srand(1);

    Team heroes, enemies;

    heroes.add(new Combatant("Arthur", 60, 5));
    heroes.add(new Combatant("Lancelot", 55, 4));
    heroes.add(new Combatant("Merlin", 45, 3));
    heroes.add(new Combatant("Gwen", 50, 4));
    heroes.add(new Combatant("Robin", 40, 5));

    enemies.add(new Combatant("Goblin", 35, 3));
    enemies.add(new Combatant("Orc", 60, 4));
    enemies.add(new Combatant("Troll", 70, 5));
    enemies.add(new Combatant("Skeleton", 30, 2));
    enemies.add(new Combatant("Dragon", 70, 5));

    battle(heroes, enemies);
}