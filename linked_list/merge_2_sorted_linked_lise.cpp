/* <<<<< CODE BY SRP >>>>> */
/* <<<<< SAMARTH >>>>> */
/* <<<<< JAY HIND >>>>> */

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef vector<long long int> vli;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef map<int, int> mi;
typedef multimap<int, int> mmi;
typedef unordered_map<int, int> umi;
typedef set<int> si;
typedef multiset<int> msi;
typedef unordered_set<int> usi;

class node
{
public:
    int data;
    node *next;

    node(int data = 0)
    {
        this->data = data;
        this->next = NULL;
    }

    ~node()
    {
        int val = this->data;
        cout << "Deleting..." << val << endl;
    }
};

void Insert_At_Head(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void Insert_At_Tail(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void Insert_At_Possition(node *&head, node *&tail, int p, int data)
{
    if (p == 1) // insert at head so we have to up date head
    {
        Insert_At_Head(head, data);
        return;
    }
    node *t = head;
    node *ins = new node(data);
    p--;
    p--;
    while (p--)
    {
        t = t->next;
    }
    if (t->next == NULL) // insert at last so we have to update tail
    {
        Insert_At_Tail(tail, data);
        return;
    }

    ins->next = t->next;
    t->next = ins;
}

void delete_node(node *&head, node *&tail, int val)
{
    node *t = head;

    if (t->data == val)
    {
        head = t->next;
        t->next = NULL;
        delete t;
        return;
    }

    while ((t->next->data != val))
    {
        t = t->next;
        if (t->next == NULL)
        {
            cout << "Element not found" << endl;
            return;
        }
    }
    node *temp = t->next;

    if (temp->next == NULL)
    {
        t->next = NULL;
        tail = t;
        temp->next = NULL;
        delete temp;
        return;
    }

    t->next = temp->next;
    temp->next = NULL;
    delete temp;
}

void print(node *&head)
{
    node *t = head;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

node *merge(node* h1, node* h2)
{
    // one of the list is empty
    if (h1 == NULL)
    {
        return h2;
    }
    if (h2 == NULL)
    {
        return h1;
    }

    node* c1 = h1->next;
    node* p1 = h1;
    node* t = h2;

    while ((c1 != NULL) && (t != NULL))
    {
        if ((t->data <= p1->data) && (p1 == h1))
        {
            h1 = t;
            node* temp = t;
            t = t->next;
            temp->next = p1;
            p1 = h1;
            c1 = h1->next;
        }
        else if ((t->data <= c1->data) && (t->data >= p1->data))
        {
            node* temp = t;
            t = t->next;
            p1->next = temp;
            temp->next = c1;
            p1 = temp;
        }
        else
        {
            p1 = c1;
            c1 = c1->next;
        }
    }
    if (c1 == NULL)
    {
        p1->next = t;
    }
    return h1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    node *node1 = new node(3);
    node *head1 = node1;
    node *tail1 = node1;

    node *node2 = new node(1);
    node *head2 = node2;
    node *tail2 = node2;

    Insert_At_Tail(tail1, 6);
    Insert_At_Tail(tail1, 8);
    Insert_At_Tail(tail1, 10);
    Insert_At_Tail(tail2, 2);
    Insert_At_Tail(tail2, 7);
    Insert_At_Tail(tail2, 9);
    Insert_At_Tail(tail2, 11);
    print(head1);
    print(head2);
    cout << endl;

    head1 = merge(head1, head2);
    cout << "After merging : ";
    print(head1);

    return 0;
}