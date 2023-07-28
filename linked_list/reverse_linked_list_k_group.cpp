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

void reverse_k_group(node *&head, int k)
{
    if (k == 0)
    {
        return;
    }

    stack<int> s;
    node *t = head;
    node *copy = head;

    while (t != NULL)
    {
        for (int i = 0; i < k; i++)
        {
            if (t != NULL)
            {
                s.push(t->data);
                t = t->next;
            }
        }
        while (!s.empty())
        {
            copy->data = s.top();
            copy = copy->next;
            s.pop();
        }
    }
}

node* reverse_k_group_recursive(node *head, int k)
{
    // Base case
    if (head == NULL)
    {
        return head;
    }
    
    // step 1 = Reverse 1st k nodes
    node *next = NULL;
    node *prev = NULL;
    node *curr = head;
    int count = 0;

    while ((curr != NULL) && (count < k)) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    // step 2 = recutrsion dekh lega aage ka;
    if (next != NULL)
    {
        head->next = reverse_k_group_recursive(next, k);
    }
    
    return prev;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;

    Insert_At_Tail(tail, 20);
    Insert_At_Tail(tail, 30);
    Insert_At_Tail(tail, 40);
    Insert_At_Tail(tail, 50);
    Insert_At_Tail(tail, 60);
    print(head);

    reverse_k_group(head, 3);
    print(head);

    head = reverse_k_group_recursive(head, 2);
    print(head);

    return 0;
}