#include <iostream>
using namespace std;
class Product
{
public:
    int productID;
    string productName;
    double price;
    string Category;
    Product *next;
    Product(int id, string name, double price, string cat)
    {
        productID = id;
        productName = name;
        this->price = price;
        Category = cat;
        next = NULL;
    }
};
class Branch
{
public:
    Product *head;
    Product *tail;
    Branch()
    {
        head = tail = NULL;
    }
    void insert(int id, string name, double price, string cat)
    {
        Product *newProduct = new Product(id, name, price, cat);
        if (head == NULL)
        {
            head = tail = newProduct;
            return;
        }
        if (head->productID >= id)
        {
            newProduct->next = head;
            head = newProduct;
            return;
        }
        Product *temp = head;
        while (temp->next != NULL && temp->next->productID < id)
        {
            temp = temp->next;
        }
        newProduct->next = temp->next;
        temp->next = newProduct;
    }
    void display(string Branch)
    {
        if (head == NULL)
        {
            cout << "Empty!" << endl;
            return;
        }
        cout << Branch << " Products" << endl;
        Product *temp = head;
        int count = 1;
        while (temp != NULL)
        {
            cout << count << ". " << "Product No: " << temp->productID << ", Product Name: " << temp->productName << ", Price: " << temp->price << ", Category: " << temp->Category << endl;
            temp = temp->next;
            count++;
        }
        count = 1;
    }
    Product *mergeSorted(Product *head1, Product *head2)
    {
        if (head1 == NULL && head2 == NULL)
        {
            return NULL;
        }
        if (head1 == NULL)
        {
            return head2;
        }
        if (head2 == NULL)
        {
            return head1;
        }
        Product *MasterHead = NULL;
        if (head1->productID < head2->productID)
        {
            MasterHead = head1;
            head1 = head1->next;
        }
        else
        {
            MasterHead = head2;
            head2 = head2->next;
        }
        Product *MasterTail = MasterHead;
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->productID < head2->productID)
            {
                MasterTail->next = head1;
                head1 = head1->next;
            }
            else
            {
                MasterTail->next = head2;
                head2 = head2->next;
            }
            MasterTail = MasterTail->next;
        }
        if (head1 != NULL)
        {
            MasterTail->next = head1;
        }
        else
        {
            MasterTail->next = head2;
        }
        return MasterHead;
    }
};
void enter(int n, Branch &b)
{
    int id;
    string name, cat;
    double price;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Product " << i + 1 << " Details(Id,Name,Category,Price): ";
        cin >> id >> name >> cat >> price;
        b.insert(id, name, price, cat);
    }
}
int main()
{
    Branch GlowCare, BeautyHub;
    int n1, n2;
    cout << "Enter Number of Products For Both Branches: ";
    cin >> n1 >> n2;
    cout << "==Enter Products of GlowCare==\n";
    enter(n1, GlowCare);
    cout << "==Enter Products of BeautyHub==\n";
    enter(n2, BeautyHub);

    cout << "===Before Merging===\n";

    GlowCare.display("GlowCare");
    BeautyHub.display("BeautyHub");

    cout << "===After Merging===\n";
    Branch Merged;
    Merged.head = Merged.mergeSorted(GlowCare.head, BeautyHub.head);
    Merged.display("Merged");
}