#include <iostream>
using namespace std;
#define Max 100
class Patient
{
public:
    int patientID;
    int severity;
    Patient()
    {
        patientID = 0;
        severity = 0;
    }
    Patient(int id, int s)
    {
        patientID = id;
        severity = s;
    }
};
class PatientQueue
{
public:
    Patient Pqueue[Max];
    int front;
    int rear;
    PatientQueue()
    {
        front = 0;
        rear = 0;
    }
    void enqueue(Patient p)
    {
        Pqueue[rear++] = p;
    }
    bool isEmpty()
    {
        return rear == front;
    }
    Patient dequeue()
    {
        return Pqueue[front++];
    }
    int rem()
    {
        return rear - front;
    }
};
class Emergency
{
public:
    PatientQueue Critical;
    PatientQueue Serious;
    PatientQueue Normal;
    int treated;
    Emergency()
    {
        treated = 0;
    }
    void arrive(int id, int s)
    {
        Patient p = Patient(id, s);
        if (s == 1)
        {
            Critical.enqueue(p);
        }
        else if (s == 2)
        {
            Serious.enqueue(p);
        }
        else if (s == 3)
        {
            Normal.enqueue(p);
        }
    }
    void treat()
    {
        Patient p;
        if (Critical.isEmpty() == false)
        {
            p = Critical.dequeue();
        }
        else if (Serious.isEmpty() == false)
        {
            p = Serious.dequeue();
        }
        else if (Normal.isEmpty() == false)
        {
            p = Normal.dequeue();
        }
        else
        {
            cout << "There is no Patient to treat!" << endl;
            return;
        }
        cout << "Treated Patient: " << p.patientID << endl;
        treated++;
    }
    void display()
    {
        int c = Critical.rem();
        int s = Serious.rem();
        int n = Normal.rem();
        cout << "\n========== RESULT ==========\n";
        cout << "Total Patients Treated: " << treated << endl;
        cout << "Total Patients Remaining: "
             << c + s + n << endl;

        cout << "Critical Remaining: " << c << endl;
        cout << "Serious Remaining: " << s << endl;
        cout << "Normal Remaining: " << n << endl;
    }
};
int main()
{
    Emergency E;

    int choice;
    int id, severity;

    while (true)
    {
        cout << "\n1. ARRIVE";
        cout << "\n2. TREAT";
        cout << "\n3. END";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter ID and Severity: ";
            cin >> id >> severity;

            E.arrive(id, severity);
        }

        else if (choice == 2)
        {
            E.treat();
        }

        else if (choice == 3)
        {
            break;
        }

        else
        {
            cout << "Invalid choice!" << endl;
        }
    }

    E.display();

    return 0;
}