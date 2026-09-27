#include <iostream>
using namespace std;
class song
{
public:
    string title;
    string genre;
    int duration;
    bool isExplicit;
    song *next;
    song(string t, string g, int d, bool e)
    {
        title = t;
        genre = g;
        duration = d;
        isExplicit = e;
        next = NULL;
    }
};
class Playlist
{
public:
    song *head;

    Playlist()
    {
        head = NULL;
    }
    bool isSameGenre(song *prev, song *next, string g)
    {
        if (prev != NULL && prev->genre == g)
        {
            return false;
        }
        if (next != NULL && next->genre == g)
        {
            return false;
        }
        return true;
    }
    bool validuration(song *prev, song *curr, song *next)
    {
        if (prev != NULL && next != NULL)
        {
            return (prev->duration + curr->duration + next->duration) <= 600;
        }
        return true;
    }
    void insert(song *&newSong, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid Position!" << endl;
            return;
        }
        song *prev = NULL;
        song *curr = head;
        int index = 0;
        while (curr != NULL && index < pos)
        {
            prev = curr;
            curr = curr->next;
            index++;
        }
        if (pos > index)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        while (curr != NULL || prev != NULL)
        {

            if (isSameGenre(prev, curr, newSong->genre) && validuration(prev, newSong, curr))
            {
                break;
            }
            prev = curr;
            if (curr != NULL)
            {
                curr = curr->next;
            }
        }
        if (prev == NULL)
        {
            newSong->next = head;
            head = newSong;
        }
        else
        {
            newSong->next = curr;
            prev->next = newSong;
        }
        cout << "Song Inserted" << endl;
    }
    void deleteSong(int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid Position!" << endl;
            return;
        }
        song *curr = head;
        song *prev = NULL;
        int count = 0;
        while (curr != NULL && count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if (curr == NULL)
        {
            cout << "Invalid Position!";
            return;
        }
        if (pos > count)
        {
            cout << "Invalid Position";
            return;
        }

        if (curr->isExplicit)
        {
            cout << "Cannot delete explicit song.\n";
            cout << "Make it non-explicit first.\n";
            return;
        }
        if (curr->next != NULL && prev != NULL && prev->genre == curr->next->genre)
        {
            cout << "Deletion violates genre rule.\n";
            return;
        }
        if (prev == NULL)
        {

            head = curr->next;
        }
        else
        {
            prev->next = curr->next;
        }
        cout << "Song " << curr->title << " Deleted" << endl;
        delete curr;
    }
    void search(string title)
    {
        song *temp = head;
        int pos = 0;

        while (temp != NULL)
        {
            if (temp->title == title)
            {
                cout << "Found at position " << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Song not found.\n";
    }
    void display()
    {
        song *temp = head;
        int pos = 0;

        while (temp != NULL)
        {
            cout << pos << ": "
                 << temp->title << " | "
                 << temp->genre << " | "
                 << temp->duration << " sec | "
                 << (temp->isExplicit ? "Explicit" : "Clean")
                 << endl;

            temp = temp->next;
            pos++;
        }
    }
};
int main()
{

    Playlist p;

    song *s1 = new song("Believer", "Rock", 204, false);
    song *s2 = new song("Perfect", "Pop", 263, false);
    song *s3 = new song("TakeFive", "Jazz", 300, false);

    p.insert(s1, 0);
    p.insert(s2, 1);
    p.insert(s3, 2);

    cout << "\nPlaylist:\n";
    p.display();

    cout << "\nSearching:\n";
    p.search("Perfect");

    cout << "\nDeleting song at position 1:\n";
    p.deleteSong(1);

    cout << "\nPlaylist after deletion:\n";
    p.display();

    song *s4 = new song("FurElise", "Classical", 180, false);

    cout << "\nAdding another song:\n";
    p.insert(s4, 1);

    cout << "\nFinal Playlist:\n";
    p.display();

    return 0;
}
