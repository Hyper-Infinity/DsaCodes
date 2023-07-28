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
    char data;
    node *next;

    node(char data = 's')
    {
        this->data = data;
        this->next = NULL;
    }

    ~node()
    {
        char val = this->data;
        cout << "Deleting..." << val << endl;
    }
};

void Insert_At_Head(node *&head, char data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void Insert_At_Tail(node *&tail, char data)
{
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void Insert_At_Possition(node *&head, node *&tail, char p, char data)
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

void delete_node(node *&head, node *&tail, char val)
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

bool check(node *head)
{
    if ((head == NULL) || (head->next == NULL))
    {
        return true;
    }
    int count = 0;
    node *t1 = head;

    while (t1 != NULL)
    {
        count++;
        t1 = t1->next;
    }

    node *s = head; // slow
    node *f = head; // fast

    while ((f->next != NULL) && (f->next->next != NULL))
    {
        f = f->next;
        s = s->next;
        if (f != NULL)
        {
            f = f->next;
        }
    }
    stack<char> st;
    node *t = head;
    node *second = s->next;

    while (t != second)
    {
        st.push(t->data);
        t = t->next;
    }

    if (count & 1)
    {
        st.pop();
    }

    while (second != NULL)
    {
        if (st.top() != second->data)
        {
            return false;
        }
        st.pop();
        second = second->next;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    node *node1 = new node('s');
    node *head = node1;
    node *tail = node1;

    Insert_At_Tail(tail, 'a');
    Insert_At_Tail(tail, 'm');
    // Insert_At_Tail(tail, 'm');
    Insert_At_Tail(tail, 'a');
    Insert_At_Tail(tail, 's');

    if (check(head))
    {
        cout << "Given word is palindrome" << endl;
    }
    else
    {
        cout << "Given word is not a palindrome" << endl;
    }

    return 0;
}