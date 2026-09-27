#include <iostream>
using namespace std;
class Moves
{
public:
    int top;
    int capacity;
    char *moves;
    Moves(int cap = 5)
    {
        capacity = cap;
        moves = new char[cap];
        top = -1;
    }
    void push(char c)
    {
        if (isFull())
        {
            capacity *= 2;
            char *newMoves = new char[capacity];
            for (int i = 0; i <= top; i++)
            {
                newMoves[i] = moves[i];
            }
            delete[] moves;
            moves = newMoves;
        }
        moves[++top] = c;
    }
    char pop()
    {
        if (isEmpty())
        {
            return '@';
        }
        return moves[top--];
    }
    bool isFull()
    {
        return top == capacity - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }
    int getundos()
    {
        return top + 1;
    }
    ~Moves()
    {
        delete[] moves;
    }
};
class Player
{
public:
    string pID;
    int energy;
    bool active;
    Moves Rmoves;
    Player(string id)
    {
        pID = id;
        energy = 100;
        active = true;
    }
    void commands(char c)
    {
        if (c == 'U')
        {
            char m = Rmoves.pop();
            if (m == '@')
            {
                return;
            }
            if (m == 'F')
            {
                energy += 10;
            }
            if (m == 'T')
            {
                energy -= 20;
            }
            return;
        }
        if (c == 'F')
        {
            energy -= 10;
        }
        else if (c == 'T')
        {
            energy += 20;
        }
        Rmoves.push(c);
    }
};
class PlayersQueue
{
public:
    Player **players;
    Player **Eplayers;
    int front;
    int rear;
    int capacity;
    int count;
    int Ecount;
    PlayersQueue(int C = 100)
    {
        rear = -1;
        front = 0;
        capacity = C;
        players = new Player *[C];
        Eplayers = new Player *[C];
        count = 0;
        Ecount = 0;
    }
    void addPlayer(string id)
    {
        Player *p = new Player(id);
        enqueue(p);
    }
    void enqueue(Player *p)
    {
        if (isFull())
        {
            return;
        }
        rear = (rear + 1) % capacity;
        players[rear] = p;
        count++;
    }

    Player *dequeue()
    {
        if (isEmpty())
        {
            return NULL;
        }
        Player *p = players[front];
        front = (front + 1) % capacity;
        count--;
        return p;
    }
    void eliminate(Player *p)
    {
        p->active = false;
        Eplayers[Ecount++] = p;
    }
    void play(char c)
    {
        if (isEmpty())
        {
            return;
        }
        Player *p = dequeue();
        p->commands(c);
        if (p->energy <= 0)
        {
            eliminate(p);
        }
        else
        {
            enqueue(p);
        }
    }
    void display()
    {
        cout << "----Eliminated Players----\n";
        if (Ecount == 0)
        {
            cout << "None!" << endl;
        }
        else
        {
            for (int i = 0; i < Ecount; i++)
            {
                cout << Eplayers[i]->pID << " ";
            }
            cout << endl;
        }
        cout << "-----Active Players-----\n";
        if (count == 0)
        {
            cout << "None!" << endl;
        }
        else
        {
            int index = front;

            for (int i = 0; i < count; i++)
            {
                Player *p = players[index];

                cout << "ID: " << p->pID
                     << "  Energy: " << p->energy
                     << "  Undo actions: "
                     << p->Rmoves.getundos()
                     << endl;

                index = (index + 1) % capacity;
            }
        }
    }

    bool
    isFull()
    {
        return count == capacity;
    }
    bool isEmpty()
    {
        return count == 0;
    }
    ~PlayersQueue()
    {

        delete[] players;
        delete[] Eplayers;
    }
};
int main()
{
    PlayersQueue q;

    int n;
    cout << "Enter total Players: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string id;
        cout << "Enter ID for Player " << i + 1 << ":";
        cin >> id;
        q.addPlayer(id);
    }

    int commands;
    cout << "Enter Number of Commands: ";
    cin >> commands;

    for (int i = 0; i < commands; i++)
    {
        char c;
        cout << "Enter Command " << i + 1 << ":";
        cin >> c;
        q.play(c);
    }

    q.display();

    return 0;
}