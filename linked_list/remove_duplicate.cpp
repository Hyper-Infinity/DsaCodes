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

void remove_duplicate_1(node *&head)
{
    set<int> s;
    node *t = head;

    while (t != NULL)
    {
        if (!s.count(t->data))
        {
            s.insert(t->data);
        }
        t = t->next;
    }

    node *temp = NULL;
    t = head;

    for (auto it : s)
    {
        t->data = it;
        temp = t;
        t = t->next;
    }

    temp->next = NULL;

    while (t != NULL)
    {
        node *p = t;
        t = t->next;
        delete p;
    }
}

// aproach 2 is better.
void remove_duplicate_2(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    
    set<int> s;
    node *prev = head;
    s.insert(prev->data);
    node *curr = head->next;

    while (curr != NULL)
    {
        if (s.count(curr->data))
        {
            node *temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            s.insert(curr->data);
            curr = curr->next;
            prev = prev->next;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a = 10;
    string s;
    char ins = a;
    s.push_back(ins);

    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;

    Insert_At_Tail(tail, 20);
    Insert_At_Tail(tail, 10);
    Insert_At_Tail(tail, 50);
    Insert_At_Tail(tail, 20);
    Insert_At_Tail(tail, 30);
    Insert_At_Tail(tail, 20);
    Insert_At_Tail(tail, 30);
    Insert_At_Tail(tail, 50);
    Insert_At_Tail(tail, 40);
    Insert_At_Tail(tail, 50);

    print(head);

    remove_duplicate_2(head);
    print(head);

    return 0;
}